// gcc ffmpeg-practice.c $(pkg-config --cflags --libs libavcodec libavutil libavformat) -o ffmpeg-output
#include <stdlib.h>
#include <stdio.h>
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <string.h>
#include <inttypes.h>
#include <stdarg.h>

static void logging(const char*fmt)
{
	fprintf(stderr, "LOG: %s \n", fmt);
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

int main(int argc, const char *argv[])
{
	if (argc < 2){
		printf("Specify media file.\n");
		return -1;
	}

	const char *file_name = argv[1];
	
	AVFormatContext *pFormatContext = avformat_alloc_context();
	if (!pFormatContext) {
		logging("ERROR could not allocate memory for Format Context");
		return -1;
	}

	if (avformat_open_input(&pFormatContext, argv[1], NULL, NULL) != 0) {
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
		snprintf(frame_filename, sizeof(frame_filename), "%s-%d.pgm", "frame", frames_to_process);
		print_luma_frame(frame->data[0], frame->linesize[0], frame->width, frame->height, frame_filename);

		av_packet_unref(packet);
	}




	av_packet_free(&packet);
	av_frame_free(&frame);
	avcodec_free_context(&codec_context);
	avformat_close_input(&pFormatContext);
	
	return 0;

}


