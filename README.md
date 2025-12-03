# 2-Month Video Infrastructure Engineering Study Plan
## Core Video Fundamentals + Distributed Systems

> **Goal**: Master video fundamentals + build distributed video processing system by Feb 2026
> 
> **Target Roles**: Video Infrastructure Engineering at YouTube, Twitch, Netflix, NVIDIA GeForce Now
> 
> **Time Commitment**: 25-35 hours/week

---

## 📅 Timeline Overview

| Phase | Dates | Focus | Milestone |
|-------|-------|-------|-----------|
| **Month 1** | Dec 1-31, 2025 | Video Fundamentals + WebRTC + HLS | ✅ WebRTC demo + HLS player |
| **Month 2** | Jan 1-31, 2026 | Distributed Processing Pipeline | ✅ Production system |

---

## 🎯 Project Overview

You'll build **3 complementary projects**:

1. **CLI Video Transcoder** - Master FFmpeg fundamentals
2. **WebRTC Real-Time Streaming Demo** - Understand low-latency live streaming (P2P video chat)
3. **HLS Video Player** - Build a video viewing player (like Netflix/YouTube player)
4. **Distributed Video Processing Pipeline** - Build a video upload/processing system (like YouTube backend)
   - This will USE the HLS player from Project 3 to view the processed videos!

**Key Distinctions:**
- **WebRTC (Project 2)**: For **live peer-to-peer streaming** (video calls, gaming, <500ms latency)
- **HLS Player (Project 3)**: For **viewing** pre-recorded videos with quality selection (VOD)
- **Distributed Pipeline (Project 4)**: **Processes** uploaded videos AND uses HLS player to view them

---

# 📚 MONTH 1: Video Engineering Fundamentals

## Week 1-2: Video Internals + FFmpeg

### 🎯 Goal
Understand codecs, containers, compression, and FFmpeg mastery

### 📖 Core Learning (15-20 hours)

**Must-Read Resources:**
1. **[Digital Video Introduction](https://github.com/leandromoreira/digital_video_introduction)** ⭐
   - Time: 6-8 hours
   - Read: Chapters 1-6 (basics through codecs)
   - Action: Clone repo, run examples
   - This explains: codecs (H.264, VP9), containers (MP4, WebM), compression

2. **[FFmpeg libav Tutorial](https://github.com/leandromoreira/ffmpeg-libav-tutorial)** ⭐
   - Time: 4-6 hours
   - Code along with examples 0-3
   - Understand: demuxing, decoding, encoding, muxing

3. **FFmpeg Command Line Mastery**
   - [FFmpeg Official Docs](https://ffmpeg.org/ffmpeg.html)
   - Focus: `-i`, `-c:v`, `-c:a`, `-b:v`, `-r`, `-s`, `-filter_complex`
   - Practice: transcode, resize, change codecs, extract streams

**Optional Reading:**
- [Netflix Per-Title Encoding](https://netflixtechblog.com/per-title-encode-optimization-7e99442b62a2)
- Search for articles on video compression, H.264 codec fundamentals

### 🛠️ Mini Project: CLI Video Transcoder
**Time: 10-15 hours**

#### What You'll Build
A production-ready CLI tool demonstrating FFmpeg expertise.

#### Features
- Convert between formats (MP4, WebM, MKV)
- Generate multiple resolutions (1080p, 720p, 480p, 360p)
- Extract metadata (codec, bitrate, duration, fps)
- Progress bar with ETA
- Quality presets (high/medium/low)
- Batch processing

#### Tech Stack
- **Language**: Python
- **CLI**: Click or argparse
- **Video**: FFmpeg (subprocess)
- **UI**: tqdm for progress bars

#### Project Structure
```
video-transcoder/
├── README.md
├── requirements.txt
├── transcoder.py          # Main CLI logic
├── presets.py            # Quality presets
├── metadata.py           # Metadata extraction
└── examples/
    └── usage_examples.md
```

#### Key Implementation Points
- Use subprocess to call FFmpeg commands
- Parse FFmpeg output for progress tracking
- Handle errors gracefully (missing codecs, corrupt files)
- Support batch processing with queue

#### ✅ Success Criteria
- [ ] Process 5+ test videos
- [ ] Clean README with usage examples
- [ ] GitHub repo published

---

## Week 3: WebRTC Real-Time Streaming

### 🎯 Goal
Understand real-time streaming and build P2P video demo

**Purpose:** WebRTC is for **live streaming** (video calls, gaming). This is different from HLS which is for viewing pre-recorded videos.

### 📖 Core Learning (10-12 hours)

**WebRTC Fundamentals:**
1. **[WebRTC for the Curious](https://webrtcforthecurious.com/)** ⭐
   - Time: 8-10 hours
   - Read: Chapters 1-5 (fundamentals)
   - Focus: signaling, STUN/TURN, media transport, P2P connections

2. **[WebRTC MDN Docs](https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API)** (2 hours)
   - Focus on: RTCPeerConnection, getUserMedia, data channels

**Key Concepts:**
- Signaling (establishing connections)
- ICE candidates (NAT traversal)
- STUN/TURN servers
- Real-time media transport (RTP/RTCP)
- Latency optimization (<500ms)

### 🛠️ Project 2: WebRTC Video Chat Demo
**Time: 12-15 hours**

#### What You'll Build
A peer-to-peer video streaming application demonstrating low-latency streaming.

#### Features
- P2P video/audio streaming between two browsers
- WebSocket signaling server for connection setup
- Screen sharing capability
- Connection quality metrics (latency, packet loss, bitrate)
- Simple web UI

#### Tech Stack
- **Frontend**: Vanilla JavaScript (keep it simple)
- **Signaling Server**: Node.js + Socket.io
- **WebRTC**: Native browser APIs (no external libraries needed)

#### Architecture
```
Browser A ←→ Signaling Server (WebSocket) ←→ Browser B
    ↓                                            ↓
    └────── Direct P2P Media Connection ─────────┘
            (via STUN/TURN servers)
```

#### Project Structure
```
webrtc-video-chat/
├── README.md
├── server.js              # WebSocket signaling server
├── package.json
└── public/
    ├── index.html         # Video chat UI
    ├── style.css
    └── app.js             # WebRTC client logic
```

#### Key Implementation Points
- Create RTCPeerConnection with STUN server configuration
- Handle getUserMedia for camera/mic access
- Implement signaling protocol (offer/answer/ICE candidates)
- Display connection statistics (getStats API)
- Handle connection failures gracefully
- Add screen sharing using getDisplayMedia

#### ✅ Success Criteria
- [ ] P2P video connection working between two browsers
- [ ] Sub-second latency (<500ms)
- [ ] Works across different networks (with STUN)
- [ ] Clean README explaining WebRTC flow
- [ ] GitHub repo with setup instructions

---

## Week 4: HLS Video Player (For Viewing Videos)

### 🎯 Goal
Build an HLS video player to view videos with quality selection (like Netflix/YouTube player)

**Purpose:** This is for **viewing** pre-recorded videos. Later you'll integrate this into your distributed pipeline to view processed videos.

### 📖 Core Learning (10-15 hours)

**HLS/DASH Fundamentals:**
1. **[HTTP Live Streaming Explained](https://www.cloudflare.com/learning/video/what-is-http-live-streaming/)** - Cloudflare (20 min)
   - Learn: How HLS works, playlist formats, segments

2. **[Apple HLS Specification](https://developer.apple.com/streaming/)** (2 hours)
   - Focus on: master playlists, media playlists, variant streams

3. **[DASH vs HLS](https://www.cloudflare.com/learning/video/what-is-mpeg-dash/)** - Cloudflare (15 min)

4. **[HLS.js Documentation](https://github.com/video-dev/hls.js/)** - Read getting started guide

**CDN Concepts:**
- **[How CDNs Work](https://www.cloudflare.com/learning/cdn/what-is-a-cdn/)** - Cloudflare (30 min)
- Read articles on video delivery at scale from AWS Media Blog or Netflix Tech Blog

**Key Concepts:**
- Master playlists (list of quality levels)
- Media playlists (list of segments)
- Adaptive bitrate switching
- Segment sizes and buffering
- CDN caching strategies

### 🛠️ Project 3: HLS Video Player
**Time: 15-20 hours**

#### What You'll Build
A web-based video player that can play HLS videos with multiple quality levels and playback controls.

#### Features
- Play HLS videos with master playlists
- Display available quality levels (1080p, 720p, 480p)
- Manual quality selection
- Automatic quality switching based on bandwidth
- Playback speed controls (0.5x, 1x, 1.5x, 2x)
- Show current bitrate and buffer health
- Clean, responsive UI

#### Tech Stack
- **Backend**: Python Flask or Node.js Express (simple static file server)
- **Player**: HLS.js (industry standard)
- **Frontend**: Plain HTML/CSS/JS

#### Project Structure
```
hls-video-player/
├── README.md
├── server.py (or server.js)      # Static file server
├── generate_sample_hls.sh         # Script to create test HLS files
├── public/
│   ├── index.html                 # Player UI
│   ├── style.css
│   └── player.js                  # HLS.js integration
├── test-videos/
│   └── sample.mp4                 # Source video
└── hls-output/
    ├── master.m3u8
    ├── 1080p/
    ├── 720p/
    └── 480p/
```

#### Generate Test HLS Files
Use FFmpeg with filter_complex to create multi-quality HLS output:
- Generate 3 quality levels (1080p at 5Mbps, 720p at 2.8Mbps, 480p at 1.4Mbps)
- Create master playlist and variant playlists
- Output segments (4 second duration) in separate directories
- Reference the FFmpeg HLS documentation for exact commands

#### Key Implementation Points
- Use HLS.js library to load and play HLS streams
- Implement quality level switching (manual and auto modes)
- Display real-time stats (quality, bitrate, buffer level)
- Add playback speed controls using video.playbackRate
- Handle HLS.js events (LEVEL_SWITCHED, FRAG_LOADED, ERROR)
- Responsive design for different screen sizes
- Error handling for network issues

#### ✅ Success Criteria
- [ ] Video plays smoothly with adaptive switching
- [ ] Can manually select quality levels
- [ ] Auto quality switching works based on bandwidth
- [ ] Playback speed controls work (0.5x to 2x)
- [ ] Shows real-time stats (quality, bitrate, buffer)
- [ ] Clean README with screenshots
- [ ] GitHub repo with clear setup instructions

**Important:** You'll reuse this player in Project 4 to view processed videos!

---

# 🚀 MONTH 2: Distributed Video Processing Pipeline

## Week 5-8: Distributed Video Processing Pipeline (CAPSTONE)

### 🎯 Goal
Build a production-grade video processing system (like YouTube's backend)

### What This System Does:

```
User uploads video (e.g., "vacation.mp4")
        ↓
System automatically:
  1. Transcodes to multiple qualities (1080p, 720p, 480p) in HLS format (using a custom C++/libav engine for transcoding)
  2. Generates thumbnails (preview images)
  3. Extracts metadata (duration, codec, bitrate)
  4. Stores everything in S3
        ↓
User can watch processed video in your HLS player (from Project 3!)
```

### 📖 Core Learning (10-15 hours)

**Distributed Systems:**
1. **[Designing Data-Intensive Applications](https://dataintensive.net/)** - Chapters 1, 5, 11 (6 hours)
   - Focus: reliability, scalability, maintainability, fault tolerance

2. **[System Design Primer](https://github.com/donnemartin/system-design-primer)** - Scalability section (3 hours)

3. **[Microservices Patterns](https://microservices.io/patterns/index.html)** - Message queue patterns (2 hours)

**Message Queues:**
- **[RabbitMQ Tutorials](https://www.rabbitmq.com/getstarted.html)** - Tutorials 1-4 (3 hours)
- Alternative: **[Redis Streams](https://redis.io/docs/data-types/streams/)** (2 hours)

**Key Concepts:**
- Message queues for job distribution
- Worker pools and horizontal scaling
- Retry logic and exponential backoff
- Dead letter queues
- Health monitoring and heartbeats
- Transaction logging

### 🛠️ Project 4: Distributed Video Processing Pipeline (CAPSTONE)
**Time: 30-40 hours over 3 weeks**

#### System Architecture
```
┌─────────────────┐
│  Upload API     │ ← User uploads video here
│  (Flask/Express)│
└────────┬────────┘
         │
         ▼
┌─────────────────┐
│   Message Queue │ ← Jobs queued here (RabbitMQ)
│                 │
└────────┬────────┘
         │
         ├──────────────┬──────────────┐
         ▼              ▼              ▼
┌──────────────┐ ┌──────────────┐ ┌──────────────┐
│  Transcode   │ │  Thumbnail   │ │   Metadata   │ ← Workers process in parallel
│   Workers    │ │   Workers    │ │   Workers    │
│  (C++/libav) │ │  (PIL)       │ │  (FFprobe)   │
└──────┬───────┘ └──────┬───────┘ └──────┬───────┘
       │                │                │
       └────────────────┴────────────────┘
                        ▼
                 ┌──────────────┐
                 │  S3 Storage  │ ← Processed files stored here
                 │   (MinIO)    │
                 └──────┬───────┘
                        │
                        ▼
                 ┌──────────────┐
                 │  HLS Player  │ ← User watches video (Project 3!)
                 │   Gallery    │
                 └──────────────┘
```

#### Features

**Upload & Processing:**
- REST API for video uploads
- Job queue management (RabbitMQ)
- Multiple worker types:
  - **Transcode workers**: Generate HLS with 1080p, 720p, 480p versions with own media pipeline
  - **Thumbnail workers**: Extract preview images (at 10s, 30s, 60s)
  - **Metadata workers**: Extract duration, codec, bitrate, resolution
- S3/MinIO storage integration
- Job status tracking in PostgreSQL

**Fault Tolerance:**
- Automatic retry on failure (exponential backoff: 1s, 2s, 4s)
- Dead letter queue for permanently failed jobs
- Worker health monitoring (heartbeat checks every 30s)
- Transaction logging for debugging
- Graceful degradation under high load

**Viewing Interface:**
- **Integrate your HLS player from Project 3** to view processed videos
- Gallery page showing all uploaded videos with thumbnails
- Click any video to play with quality selection
- Show processing status (queued/processing/completed/failed)
- Filter by status and date

**Monitoring:**
- Real-time dashboard showing:
  - Active/queued/completed/failed jobs
  - Worker status and resource usage (CPU/memory)
  - Error rates and retry counts
  - Processing throughput (videos/hour)
  - Queue depth over time
- Prometheus metrics collection
- Grafana dashboards with graphs

#### Tech Stack
- **API**: Python Flask (simple and clear)
- **Queue**: RabbitMQ (industry standard)
- **Workers**: Python
- **Processing**: FFmpeg (transcoding), PIL/Pillow (thumbnails), FFprobe (metadata)
- **Storage**: MinIO (S3-compatible, runs locally)
- **Database**: PostgreSQL (job metadata and status)
- **Player**: **Your HLS player from Project 3** (reuse it!)
- **Monitoring**: Prometheus + Grafana
- **Orchestration**: Docker Compose

#### Project Structure
```
distributed-video-pipeline/
├── README.md
├── docker-compose.yml              # All services defined here
├── .env.example
├── services/
│   ├── api/
│   │   ├── app.py                  # Upload API + web interface
│   │   ├── models.py               # Job schemas
│   │   ├── database.py             # PostgreSQL client
│   │   ├── templates/
│   │   │   ├── upload.html         # Upload page
│   │   │   ├── gallery.html        # Video gallery
│   │   │   └── player.html         # HLS player (from Project 3!)
│   │   └── requirements.txt
│   ├── workers/
│   │   ├── base_worker.py          # Base worker with retry logic
│   │   ├── transcode_worker.py     # Python wrapper that invokes C++ libav engine
│   │   ├── thumbnail_worker.py     # Image extraction (Python + FFmpeg/Pillow)
│   │   ├── metadata_worker.py      # Metadata extraction (Python + FFprobe)
│   │   └── requirements.txt
│   └── monitoring/
│       ├── prometheus.yml
│       └── grafana/
│           └── dashboards/
├── engine/
│   ├── CMakeLists.txt              # Build config for C++ libav engine
│   ├── include/
│   │   └── transcoder.hpp          # Public interface for the engine
│   └── src/
│       ├── main.cpp                # CLI entry: input file → HLS outputs
│       ├── demux_decode.cpp        # Uses libavformat/libavcodec
│       ├── scale_filter.cpp        # Uses libswscale / optional filters
│       └── encode_mux_hls.cpp      # Encodes and writes HLS segments/playlists
├── shared/
│   ├── queue_client.py             # RabbitMQ wrapper
│   ├── storage_client.py           # MinIO/S3 client
│   └── config.py                   # Shared configuration
├── tests/
│   ├── integration/
│   │   └── test_pipeline.py        # End-to-end tests
│   └── load/
│       └── stress_test.py          # Load testing with locust
└── docs/
    ├── ARCHITECTURE.md             # System design + diagrams
    ├── ENGINE.md                   # C++ libav engine internals + API
    ├── SETUP.md                    # Installation + build guide
    └── OPERATIONS.md               # Troubleshooting + scaling + profiling

```

#### Key Implementation Components

**1. Base Worker Class**
- Abstract base class for all workers
- Connects to RabbitMQ and listens to specific queue
- Implements retry logic with exponential backoff (1s, 2s, 4s)
- Publishes completed jobs to next stage in pipeline
- Sends failed jobs (after max retries) to dead letter queue
- Sends heartbeat signals every 30 seconds

**2.1. Transcode Worker**
- Receives job from RabbitMQ
- Downloads original video from S3
- Invokes the C++ libav engine binary (e.g., ./engine/transcoder) with:
   - input path
   - output directory
   - target resolutions/bitrates
- Checks exit status, logs errors, and publishes next job (thumbnail) if successful
- Handles retries & DLQ via base_worker.py

**2.2. C++17 libav engine (engine/)**

- Uses avformat_open_input / av_read_frame to demux
- Uses avcodec_send_packet / avcodec_receive_frame to decode
- Uses sws_scale (or filters) to scale to 1080p / 720p / 480p
- Creates encoders for each output variant (e.g., libx264)
- Writes encoded packets into HLS segments and playlists:
- master.m3u8
- 1080p/index.m3u8, segment files
- 720p/index.m3u8, segment files
- 480p/index.m3u8, segment files
- Handles FFmpeg errors gracefully and prints logs for troubleshooting

**3. Thumbnail Worker**
- Downloads video from S3
- Extracts frames at 10s, 30s, 60s using FFmpeg
- Generates thumbnail images (e.g., 320x180 JPEGs)
- Uploads thumbnails to S3
- Publishes job to metadata queue
- Handles videos shorter than expected duration

**4. Metadata Worker**
- Uses FFprobe to extract video information
- Stores in PostgreSQL: duration, codec, bitrate, resolution, fps
- Marks job status as "completed"
- Final stage in pipeline - no further publishing

**5. Health Monitor Service**
- Tracks worker heartbeats in Redis
- Detects unresponsive workers (no heartbeat for 60s)
- Logs alerts for manual intervention
- Exposes metrics for Prometheus

**6. API Server**
- Upload endpoint: POST /upload (accepts video file, creates job)
- Gallery page: GET /gallery (lists all videos with thumbnails)
- Player page: GET /watch/<video_id> (embeds HLS player from Project 3)
- Status endpoint: GET /status/<job_id> (check processing status)
- Health check: GET /health

**7. Docker Compose Setup**
Define all services in docker-compose.yml:
- RabbitMQ (with management UI on port 15672)
- PostgreSQL (for job metadata)
- MinIO (S3-compatible storage with console on port 9001)
- API server
- Multiple worker containers:
  - 3x transcode workers (CPU-intensive)
  - 2x thumbnail workers
  - 2x metadata workers (lightweight)
- Prometheus (metrics collection on port 9090)
- Grafana (dashboards on port 3000)

#### Implementation Timeline (3 weeks)

**Week 6: Core Pipeline (Days 1-7)**
- Day 1-2: Set up Docker Compose with RabbitMQ, PostgreSQL, MinIO
- Day 3-4: Build upload API and basic web interface
- Day 5: Implement base worker class with retry logic
- Day 6: Create transcode worker with FFmpeg HLS generation
- Day 7: Test end-to-end flow with one video upload

**Week 7: Additional Workers + Fault Tolerance (Days 8-14)**
- Day 8-9: Implement thumbnail worker
- Day 10: Implement metadata worker
- Day 11: Add dead letter queue handling
- Day 12: Build health monitoring service
- Day 13-14: Test with multiple videos in parallel, simulate failures

**Week 8: Viewing Interface + Monitoring (Days 15-21)**
- Day 15-16: Integrate HLS player from Project 3 into gallery
- Day 17: Build video gallery page with thumbnails
- Day 18: Set up Prometheus + Grafana
- Day 19: Create monitoring dashboards (job metrics, worker health)
- Day 20: Load testing with 100+ videos
- Day 21: Documentation, architecture diagrams, polish

#### Testing Strategy

**Integration Tests:**
- Upload video → Wait for completion → Verify outputs exist (HLS files, thumbnails, metadata)
- Test retry logic: simulate worker crash, verify job completes on retry
- Test dead letter queue: send corrupted file, verify it ends up in DLQ
- Test worker recovery: kill worker, verify health monitor detects it

**Load Tests:**
- Use locust or similar tool
- Upload 100+ videos simultaneously
- Measure: throughput (videos/hour), error rate, queue depth
- Monitor: CPU/memory usage, database connections, S3 operations
- Goal: < 1% failure rate under load

**Manual Tests:**
- Upload various formats: MP4, MOV, AVI, MKV
- Upload different resolutions: 4K, 1080p, 720p, 480p
- Upload edge cases: very short videos (<5s), very long videos (>1hr), corrupted files
- Test HLS player: verify all quality levels work, verify playback controls

#### ✅ Success Metrics
- [ ] Process 100+ videos end-to-end without manual intervention
- [ ] < 1% job failure rate (after retries)
- [ ] Automatic recovery from worker failures (health monitor working)
- [ ] Scale to 10+ worker instances (3 transcode + 2 thumbnail + 2 metadata)
- [ ] End-to-end processing < 5 minutes for 1080p video
- [ ] 99.9% uptime during 24-hour load test
- [ ] All processed videos viewable in HLS player with quality switching
- [ ] Comprehensive monitoring dashboard showing real-time metrics
- [ ] Architecture documentation with clear diagrams

---

## Week 8: Polish & Documentation

### 🎯 Final Polish (10-15 hours)

#### Documentation (6-8 hours)
- [ ] Comprehensive README for each project (CLI, WebRTC, HLS Player, Pipeline)
- [ ] Architecture diagrams using Excalidraw or draw.io:
  - System architecture (all components)
  - Data flow (upload → processing → viewing)
  - Failure scenarios (retry logic, DLQ)
- [ ] Setup instructions for distributed pipeline (Docker Compose)
- [ ] Operations runbook (troubleshooting common issues, scaling guide)
- [ ] API documentation (endpoints, request/response formats)

#### Demo Content (3-4 hours)
- [ ] Record 3-5 min demo video showing complete flow:
  - Upload a video via web interface
  - Show job appearing in RabbitMQ queue
  - Show workers processing (logs)
  - Show processed video in gallery with thumbnail
  - Play video in HLS player with quality switching
  - Show monitoring dashboard
- [ ] Create GIFs showing key features (upload, playback, quality switching)
- [ ] Screenshots for READMEs (architecture, UI, dashboards)

#### Blog Post (4-5 hours)
- [ ] Write 2000+ word technical article
- [ ] Suggested title: "Building a Distributed Video Processing Pipeline: From FFmpeg to Production"
- [ ] Sections:
  - Video encoding fundamentals (codecs, containers, FFmpeg)
  - Real-time vs on-demand streaming (WebRTC vs HLS)
  - Distributed system architecture (message queues, workers)
  - Fault tolerance strategies (retry, DLQ, health checks)
  - Performance optimization and scaling
  - Lessons learned and challenges faced
- [ ] Publish on Medium or Dev.to
- [ ] Share on LinkedIn, Twitter, HackerNews, Reddit r/programming

#### Resume & Portfolio (2-3 hours)
- [ ] Update resume with quantified metrics
- [ ] Update portfolio website with project showcases
- [ ] Prepare 3-minute elevator pitch for each project
- [ ] Create interview talking points document

---

## 📄 Resume Projects Section

```
VIDEO INFRASTRUCTURE PROJECTS

Distributed Video Processing Pipeline | Python, RabbitMQ, FFmpeg, Docker, PostgreSQL, MinIO
[GitHub] [Architecture Doc] [Demo Video]
• Architected fault-tolerant distributed system processing 100+ videos with <1% failure rate
• Designed microservices architecture with message queue (RabbitMQ), worker pools, and S3 storage
• Implemented a custom C++17 transcode engine using FFmpeg libavformat/libavcodec/libswscale to generate HLS multi-bitrate outputs (1080p/720p/480p) with master/variant playlists.
• Implemented automatic retry logic with exponential backoff and dead letter queue handling
• Built real-time monitoring dashboard with Prometheus/Grafana tracking throughput and errors
• Achieved 99.9% uptime during 24-hour load testing with horizontal worker scaling (10+ instances)
• End-to-end pipeline processing 1080p videos in <5 minutes with HLS multi-quality output
• Integrated custom HLS player for viewing processed videos with adaptive quality switching

HLS Video Player | Python, HLS.js, Flask, HTML/CSS/JS
[GitHub] [Live Demo]
• Built adaptive bitrate video player supporting HLS streams with 3 quality levels
• Implemented manual and automatic quality switching based on available bandwidth
• Added playback speed controls (0.5x to 2x) and real-time buffer health monitoring
• Designed responsive UI displaying current quality, bitrate, and buffer statistics
• Integrated into distributed pipeline for viewing processed videos

WebRTC Real-Time Streaming | JavaScript, WebRTC, WebSocket, Node.js
[GitHub] [Demo]
• Developed peer-to-peer video streaming application with <500ms glass-to-glass latency
• Implemented WebSocket signaling server for connection establishment and ICE negotiation
• Integrated STUN servers for NAT traversal enabling cross-network connectivity
• Built connection quality monitoring tracking bitrate, packet loss, and jitter metrics

CLI Video Transcoding Tool | Python, FFmpeg, Click
[GitHub]
• Created production-ready command-line tool for batch video transcoding and format conversion
• Implemented multi-resolution encoding generating 4 quality variants (1080p to 360p)
• Added metadata extraction, progress tracking, and quality preset configurations
• Processed 50+ test videos validating reliability across different codecs and containers
```

---

## ✅ Final Success Checklist

### By Feb 1, 2026

**Core Projects:**
- [ ] CLI Transcoder (GitHub repo with README)
- [ ] WebRTC Demo (GitHub repo + working demo)
- [ ] HLS Player (GitHub repo + working demo)
- [ ] **Distributed Pipeline (GitHub repo + full documentation)** ⭐

**Documentation:**
- [ ] All repos have comprehensive READMEs with setup instructions
- [ ] Architecture diagrams for distributed pipeline showing all components
- [ ] Operations runbook with troubleshooting section
- [ ] Demo videos/GIFs for each major project

**Content:**
- [ ] Technical blog post published (2000+ words)
- [ ] Shared on LinkedIn, Twitter, HackerNews, Reddit

**Career Materials:**
- [ ] Resume updated with quantified achievements
- [ ] Portfolio showcasing all projects with demos
- [ ] Interview prep document with talking points
- [ ] Practice explaining system design on whiteboard

---

## 🔗 Master Resource List

### 📚 Essential Reading
- [Digital Video Introduction](https://github.com/leandromoreira/digital_video_introduction) ⭐
- [FFmpeg libav Tutorial](https://github.com/leandromoreira/ffmpeg-libav-tutorial) ⭐
- [WebRTC for the Curious](https://webrtcforthecurious.com/) ⭐
- [Designing Data-Intensive Applications](https://dataintensive.net/) ⭐
- [System Design Primer](https://github.com/donnemartin/system-design-primer)
- [HLS Specification](https://developer.apple.com/streaming/)

### 📰 Industry Blogs
- [Netflix Tech Blog](https://netflixtechblog.com/)
- [YouTube Engineering](https://blog.youtube/)
- [Twitch Engineering](https://blog.twitch.tv/en/tags/engineering/)
- [Cloudflare Blog - Video](https://blog.cloudflare.com/tag/video/)
- [AWS Media Blog](https://aws.amazon.com/blogs/media/)

### 📚 Documentation
- [FFmpeg Official Docs](https://ffmpeg.org/documentation.html)
- [HLS.js GitHub](https://github.com/video-dev/hls.js/)
- [WebRTC MDN](https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API)
- [RabbitMQ Tutorials](https://www.rabbitmq.com/getstarted.html)
- [Docker Compose Docs](https://docs.docker.com/compose/)

### 👥 Communities
- [r/ffmpeg](https://reddit.com/r/ffmpeg)
- [r/webrtc](https://reddit.com/r/webrtc)
- [Video Dev Slack](https://video-dev.slack.com/)
- [Stack Overflow - video tag](https://stackoverflow.com/questions/tagged/video)

---

## ⏰ Weekly Time Breakdown

### Month 1 (Video Fundamentals):
- **Weeks 1-2** (25-30 hrs): Video internals + CLI transcoder
- **Week 3** (20-25 hrs): WebRTC demo
- **Week 4** (25-30 hrs): HLS player

### Month 2 (Distributed System):
- **Weeks 5-7** (30-35 hrs/week): Distributed pipeline
- **Week 8** (15-20 hrs): Polish & documentation

**Total:** ~180-220 hours over 8 weeks

---

## 💡 Success Tips

1. **Master fundamentals first**: Weeks 1-2 are critical - understand video encoding deeply
2. **WebRTC before HLS makes sense**: Understanding live streaming helps appreciate HLS's design
3. **HLS player is reusable**: Build it well - you'll integrate it into the pipeline
4. **Distributed pipeline is the crown jewel**: Allocate 3 full weeks for quality implementation
5. **Document as you build**: Write architecture docs alongside code, not after
6. **Test at scale**: Use Docker Compose to simulate production with 10+ workers
7. **Measure everything**: Latency, throughput, error rates - metrics make your resume stand out
8. **Share progress weekly**: Post updates on LinkedIn to build your personal brand

---

## 🎯 Interview Talking Points

**"Tell me about your most complex project"**

> "I built a distributed video processing pipeline that handles the complete video lifecycle - from upload to viewing. The system uses RabbitMQ for job distribution across multiple worker types that handle transcoding, thumbnail generation, and metadata extraction. Each worker includes fault tolerance with exponential backoff retries and dead letter queue handling for permanent failures. I designed it to scale horizontally - you can add more workers as load increases. During load testing with 100+ concurrent videos, the system maintained 99.9% uptime with less than 1% job failure rate. Processing 1080p videos takes under 5 minutes end-to-end, generating HLS output with three quality levels. Users can then watch processed videos in a custom HLS player I built with adaptive quality switching."

**"How do you handle failures in distributed systems?"**

> "In my video pipeline, I implemented multiple layers of fault tolerance. First, workers use exponential backoff for retries - if a transcode job fails, it's retried after 1 second, then 2 seconds, then 4 seconds. After 3 retries, the job moves to a dead letter queue where it's logged for manual inspection. Second, I built a health monitoring service that tracks worker heartbeats every 30 seconds - if a worker becomes unresponsive, it's detected and logged. Third, all job state transitions are logged to PostgreSQL, so we can trace any video through the entire pipeline. During testing, I simulated worker crashes and network failures to validate the retry logic worked correctly."

**"What's the difference between WebRTC and HLS?"**

> "I've built projects with both technologies. WebRTC prioritizes ultra-low latency - under 500ms - using UDP with peer-to-peer connections. It's ideal for real-time applications like video calls or live gaming where immediate interaction matters. The tradeoff is higher complexity (signaling, NAT traversal, STUN/TURN) and potential quality issues under poor network conditions. HLS prioritizes reliability and scale, with 6-30 second latency, using HTTP for segment delivery. It's perfect for on-demand video where some buffering is acceptable and you want global CDN caching. In my distributed pipeline, I chose HLS because it's designed for VOD content, works everywhere, and integrates seamlessly with CDN infrastructure."

**"Walk me through your video processing pipeline"**

> "When a user uploads a video through my Flask API, it's stored in MinIO (S3-compatible storage) and a job is published to RabbitMQ with the video ID and storage path. A transcode worker picks up this job and uses FFmpeg to generate HLS output with three quality levels - 1080p at 5 Mbps, 720p at 2.8 Mbps, and 480p at 1.4 Mbps. This creates master playlists, variant playlists, and segments which are uploaded back to S3. The job then moves to a thumbnail worker which extracts frames at 10, 30, and 60 seconds using FFmpeg, creates thumbnail images, and uploads them to S3. Finally, a metadata worker uses FFprobe to extract video information - duration, codec, bitrate, resolution - and stores it in PostgreSQL. Throughout this process, if any worker fails, the job is automatically retried up to 3 times with exponential backoff. Once processing completes, users can watch the video in my HLS player which supports manual quality selection, automatic quality switching based on bandwidth, and playback speed controls."


*Last Updated: December 2025*
*Plan Duration: 2 months (Dec 2025 - Feb 2026)*
*Focus: Video fundamentals + distributed systems at scale*