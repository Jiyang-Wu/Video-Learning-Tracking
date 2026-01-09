// gcc ffmpeg-practice.c $(pkg-config --cflags --libs libavcodec libavutil libavformat) -o ffmpeg-output
#include <stdlib.h>
#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <string.h>
#include <inttypes.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <errno.h>
#include <libavutil/timestamp.h>
#include <libavutil/opt.h>

static void logging(const char *fmt)
{
	fprintf(stderr, "LOG: %s \n", fmt);
}

int ensure_dir(const char *path)
{
	if (mkdir(path, 0755) == -1) {
		if (errno != EEXIST) {
			perror("mkdir");
			return -1;
		}
	}
	return 0;
}
//sample.pgm
static void print_luma_frame(unsigned char *buf, int wrap, int xsize, int ysize, char* filename)
{
	FILE *f = fopen(filename, "w");
	fprintf(f, "P5\n");
	fprintf(f, "%d %d\n", xsize, ysize);
	fprintf(f, "%d\n", 255);

	for (int i = 0; i < ysize; ++i){
		fwrite(buf + i*wrap, 1, xsize, f);
	}
	fclose(f);
}

//Task 0: Extracting a single frames from the bunny video and display luma channel
int extract_luma_frame(const char *file_name)
{

	AVFormatContext *pFormatContext = avformat_alloc_context();
	if (!pFormatContext) {
		logging("ERROR could not allocate memory for Format Context");
		return -1;
	}

	if (avformat_open_input(&pFormatContext, file_name, NULL, NULL) != 0) {
		logging("ERROR could not open the file");
		return -1;
	}
	
	printf("format %s, duration %ld us \n", pFormatContext->iformat->long_name, pFormatContext->duration);

	printf("number of streams %d \n", pFormatContext->nb_streams);

	int video_index = -1;
	for (int i = 0; i < pFormatContext->nb_streams; ++i){
		if (pFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
			video_index = i;	
	}
	AVStream *video_stream = pFormatContext->streams[video_index];
	AVCodecParameters *video_stream_param = video_stream->codecpar;
	printf("Stream and codec type: %d \n", video_stream_param->codec_type);

	const AVCodec *video_codec = avcodec_find_decoder(video_stream_param->codec_id);
	printf("Codec Info: name: %s, bit_rate: %ld", video_codec->long_name, video_stream_param->bit_rate);

	AVCodecContext *codec_context = avcodec_alloc_context3(video_codec);
	avcodec_parameters_to_context(codec_context, video_stream_param);
	avcodec_open2(codec_context, video_codec, NULL);
	AVPacket *packet = av_packet_alloc();
	AVFrame *frame = av_frame_alloc();

	int frames_to_process = 8;
	ensure_dir("./task0");
	while (av_read_frame(pFormatContext, packet) >= 0){
		if (packet->stream_index != video_index){
			av_packet_unref(packet);
			continue;
		}
		avcodec_send_packet(codec_context, packet);
		int ret = avcodec_receive_frame(codec_context, frame);
		if (ret == AVERROR(EAGAIN)) {
			av_packet_unref(packet);
			continue;	
		}
		char frame_filename[1024];
		frames_to_process--;
		if (frames_to_process == 0) break;
		snprintf(frame_filename, sizeof(frame_filename), "./task0/%s-%d.pgm", "frame", frames_to_process);
		print_luma_frame(frame->data[0], frame->linesize[0], frame->width, frame->height, frame_filename);

		av_packet_unref(packet);
	}




	av_packet_free(&packet);
	av_frame_free(&frame);
	avcodec_free_context(&codec_context);
	avformat_close_input(&pFormatContext);
	
	return 0;

}

//Task 2: Video Remuxing -- shifting betwen containers/formats
// Implementation:
	// copying over raw data stream, codec parameters
	// shifting timestamps (pts, dts, duration)
int remux(const char *inFile, const char *outFile)
{
	AVFormatContext *inFormatContext = NULL, *outFormatContext = NULL;
	int *stream_list = NULL;
	int output_index = 0;
	AVPacket *av_packet = av_packet_alloc();

	
	//opening input file
	if (avformat_open_input(&inFormatContext, inFile, NULL, NULL) != 0) {
		logging("Unable to open input file!");
		goto end;
	}
	if (avformat_find_stream_info(inFormatContext, NULL) < 0) {
		logging("Failed to parse stream info");
		goto end;
	}

	//opening output context
	if (avformat_alloc_output_context2(&outFormatContext, NULL, NULL, outFile) != 0) {
		logging("Unable to create output context!");
		goto end;
	}

	int num_of_streams = inFormatContext->nb_streams;
	
	stream_list = av_calloc(num_of_streams, sizeof(*stream_list));

	// looping over streams, create mapping table + copying over codec parameters
	for (int i = 0; i < num_of_streams; ++i) {
		if (inFormatContext->streams[i]->codecpar->codec_type != AVMEDIA_TYPE_VIDEO 
			&& inFormatContext->streams[i]->codecpar->codec_type != AVMEDIA_TYPE_AUDIO 
			&& inFormatContext->streams[i]->codecpar->codec_type != AVMEDIA_TYPE_SUBTITLE) {
			stream_list[i] = -1;
			continue;
		}

		stream_list[i] = output_index++;
		AVStream *out_stream = avformat_new_stream(outFormatContext, NULL);
		if (!out_stream) {
			fprintf(stderr, "Failed to create output stream %d", output_index);
			goto end;
		}
		avcodec_parameters_copy(out_stream->codecpar, inFormatContext->streams[i]->codecpar);
		
		//now we have a new corresponding stream in the outputContext, with same codec info as before
		//and a mapping (stream_list) of input stream index -> output stream index

	}

	av_dump_format(outFormatContext, 0, outFile, 1);

	// first identify whether the output format is a no-file format
	// then open up the corresponding IO context, setting it to field pb
	if (!(outFormatContext->oformat->flags & AVFMT_NOFILE)) {
		if (avio_open(&outFormatContext->pb, outFile, AVIO_FLAG_WRITE) < 0) {
			logging("unable to open output file for write");
			goto end;
		}
	}
	
	avformat_write_header(outFormatContext, NULL);
	
	// sequentially write frame packets into the output file
	while (1) {
		AVStream *in_stream, *out_stream = NULL;
		if (av_read_frame(inFormatContext, av_packet) < 0) {
			break;
		}
		// verify packet stream info
		if (av_packet->stream_index >= inFormatContext->nb_streams || stream_list[av_packet->stream_index] == -1) {
			av_packet_unref(av_packet);
			continue;
		}
		in_stream = inFormatContext->streams[av_packet->stream_index];
		out_stream = outFormatContext->streams[stream_list[in_stream->index]];
		av_packet->stream_index = out_stream->index;	

		fprintf(stdout, "input timebase is %d over %d\n", in_stream->time_base.num, in_stream->time_base.den);
		fprintf(stdout, "output timebase is %d over %d\n", out_stream->time_base.num, out_stream->time_base.den);
		av_packet->pts = av_rescale_q_rnd(av_packet->pts, in_stream->time_base, out_stream->time_base, AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX);
		av_packet->dts = av_rescale_q_rnd(av_packet->dts, in_stream->time_base, out_stream->time_base, AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX);
		av_packet->duration = av_rescale_q(av_packet->duration, in_stream->time_base, out_stream->time_base);
		av_packet->pos = -1;

		av_interleaved_write_frame(outFormatContext, av_packet);

		av_packet_unref(av_packet);
	}

	av_write_trailer(outFormatContext);

end:
	avformat_close_input(&inFormatContext);
	if (outFormatContext && !(outFormatContext->oformat->flags & AVFMT_NOFILE)) {
		avio_closep(&outFormatContext->pb);
	}
	avformat_free_context(outFormatContext);
	av_freep(&stream_list);
	av_packet_free(&av_packet);
	return 0;	

}

// Helper functions modualizing specific tasks
int open_input_format_ctx(const char *in_file_name, AVFormatContext **in_format_ctx) 
{
	if (avformat_open_input(in_format_ctx, in_file_name, NULL, NULL) != 0) {
		fprintf(stderr, "Unable to open input format context");
		return -1;	
	}
	if (avformat_find_stream_info(*in_format_ctx, NULL) < 0) {
		fprintf(stderr, "Unable to find stream info");
		return -1;
	}
	return 0;	
}

int open_out_format_ctx(const char *out_file_name, AVFormatContext **out_format_ctx) 
{
	if (avformat_alloc_output_context2(&out_format_ctx, NULL, NULL, out_file_name) != 0) {
		fprintf(stderr, "Unable to open output format context");
		return -1;
	}	
	return 0;
}

// Task 3: Adding transcoding feature that converts the incoming file (in sample, H264) into H265
int transcode(const char *in_file, const char *out_file) 
{
	AVFormatContext *in_format_ctx = NULL, *out_format_ctx = NULL;
	AVPacket *in_packet = NULL, *video_out_packet = NULL;
	int video_stream_idx = -1;
	AVCodecContext *video_encoder_ctx = NULL, *video_decoder_ctx = NULL;
	AVCodec *video_encoder_codec = NULL, *video_decoder_codec = NULL;
	char *encoder_name = "libx265";
	char *encoder_priv_key = "x265-params";
	char *encoder_priv_val = "keyint=60:min-keyint=60:scenecut=0";

	
	open_input_format_ctx(in_file, &in_format_ctx);
	open_out_format_ctx(out_file, &out_format_ctx);	

	for (int i = 0; i < in_format_ctx->nb_streams; ++i) {
		if (in_format_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
			video_stream_idx = i;
		}
	}
	if (video_stream_idx == -1) {
		fprintf(stderr, "No video stream found");
		goto end;
	}

	
	for (int i = 0; i < in_format_ctx->nb_streams; ++i) {
		AVStream *out_stream = avformat_new_stream(out_format_ctx, NULL);
		if (!out_stream) {
			fprintf(stderr, "Failed to create output stream %d", i);
			goto end;
		}
		if (i != video_stream_idx) {
			avcodec_parameters_copy(out_stream->codecpar, in_format_ctx->streams[i]->codecpar);
			fprintf(stderr, "default timebase before manually setting is %d over %d", out_stream->time_base.num, out_stream->time_base.den);
			out_stream->time_base = in_format_ctx->streams[i]->time_base;
			fprintf(stderr, "default timebase after manually setting is %d over %d", out_stream->time_base.num, out_stream->time_base.den);
		} else {
			video_encoder_codec = avcodec_find_encoder_by_name(encoder_name);
			video_encoder_ctx = avcodec_alloc_context3(video_encoder_codec);
				
			video_decoder_codec = avcodec_find_decoder(in_format_ctx->streams[i]->codecpar->codec_id);
			video_decoder_ctx = avcodec_alloc_context3(video_decoder_codec);
			avcodec_parameters_to_context(video_decoder_ctx, in_format_ctx->streams[i]->codecpar);
			avcodec_open2(video_decoder_ctx, video_decoder_codec, NULL);
			video_decoder_ctx->time_base = in_format_ctx->streams[i]->time_base;
			
			// codec parameters
			av_opt_set(video_encoder_ctx->priv_data, encoder_priv_key, encoder_priv_val, 0);
			video_encoder_ctx->height = video_decoder_ctx->height;
			video_encoder_ctx->width = video_decoder_ctx->width;
			video_encoder_ctx->pix_fmt = video_encoder_codec->pix_fmts[0];
			// control rate
			video_encoder_ctx->bit_rate = 2 * 1000 * 1000;
			video_encoder_ctx->rc_buffer_size = 4 * 1000 * 1000;
			video_encoder_ctx->rc_max_rate = 2 * 1000 * 1000;
			video_encoder_ctx->rc_min_rate = 2.5 * 1000 * 1000;
			// time base is based fixed to 1/FPS, enforcing CRF
			video_encoder_ctx->time_base = av_inv_q(av_guess_frame_rate(in_format_ctx, in_format_ctx->streams[i], NULL));
			
			out_stream->time_base = video_encoder_ctx->time_base;
			avcodec_open2(video_encoder_ctx, video_encoder_codec, NULL);
			avcodec_parameters_from_context(out_stream->codecpar, video_encoder_ctx);

		}
	}
	/*
		after the loop, both encoder and decoder contexts should be opened up and loaded with corresponding codecs
		the output format context should be ready with all streams
		video stream in output format context should be using the correct parameters from decoder context
		NEXT: strating reading frames and process them
	*/
	AVFrame *frame = av_frame_alloc();
	in_packet = av_packet_alloc();
	video_out_packet = av_packet_alloc();
	while (av_read_frame(in_format_ctx, in_packet) >= 0) {
		// if not video frame, directly remux (timebase is unified, so not timebase tuning required)				
		if (in_packet->stream_index != video_stream_idx) 
		{
			in_packet->pos = -1;
			av_interleaved_write_frame(out_format_ctx, in_packet);
			av_packet_unref(in_packet);
			continue;
		} 
		else
		{
			//if is video frame, we feed it into the decoder and attempt to retrieve one frame
			avcodec_send_packet(video_decoder_ctx, in_packet);
			int ret = avcodec_receive_frame(video_decoder_ctx, frame);
			if (ret == AVERROR(EAGAIN)) {
				av_packet_unref(in_packet);
				continue;
			}
			frame->pts = av_rescale_q_rnd(frame->pts, in_format_ctx->streams[video_stream_idx]->time_base, video_encoder_ctx->time_base, AV_ROUND_NEAR_INF | AV_ROUND_PASS_MINMAX);
			avcodec_send_frame(video_encoder_ctx, frame);
			ret = avcodec_receive_packet(video_encoder_ctx, video_out_packet);
			if (ret == AVERROR(EAGAIN)) {
				av_packet_unref(in_packet);
				av_frame_unref(frame);
				continue;
			}
			av_interleaved_write_frame(out_format_ctx, video_out_packet);

		}
	}
	// Demuxing: read packet of info from the input format context, only decode if it belongs to the video stream
	// Decoding: if packet is from video stream, make it into full frame and trigger re-coding only after a full frame is assembled
	// Encoding: TODO
	// Muxing: write timebase synced packets back to the output frame context 
		

//TODO
// Close input_format_ctx, out_format_ctx
// in_packet
end:
	avformat_close_input(&in_format_ctx);
	return 0;	
}

int main(int argc, const char *argv[])
{

	int task_num = atoi(argv[1]);
	if (task_num == 0) {
		const char *file_name = argv[2];
		extract_luma_frame(file_name);
	}
	if (task_num == 2) {
		const char *in_file_name = argv[2];
		const char *out_file_name = argv[3];
		remux(in_file_name, out_file_name);
	}
	return 0;
}


