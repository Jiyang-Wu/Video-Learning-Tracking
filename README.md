# 3-Month Video Infrastructure Engineering Study Plan

> **Goal**: Build production-ready portfolio projects + master practical video systems by Feb 2026
> 
> **Target Roles**: Data Infrastructure, Media Infrastructure, Backend/Systems Engineering
> 
> **Time Commitment**: 25-35 hours/week

---

## 📅 Timeline Overview

| Phase | Dates | Focus | Milestone |
|-------|-------|-------|-----------|
| **Month 1** | Dec 1-31, 2025 | Fundamentals + HLS Demo | ✅ Mini HLS demo |
| **Month 2** | Jan 1-31, 2026 | Cloud Infrastructure | ✅ Production deployment |
| **Month 3** | Feb 1-28, 2026 | Real-time + Portfolio | ✅ Resume-ready materials |

---

# 📚 MONTH 1: Foundations + First Demo

## Week 1-2: Video Processing Fundamentals

### 🎯 Goal
Understand codecs, containers, compression, and FFmpeg

### 📖 Core Learning Resources

#### Primary Resource (MUST READ) ⭐
- **[Digital Video Introduction](https://github.com/leandromoreira/digital_video_introduction)**
  - ⏱️ Time: 6-8 hours
  - 📖 Read: Chapters 1-6 (Intro through Codecs)
  - 💡 Interactive, practical, industry-focused
  - ✅ Action: Clone repo, run the examples

#### FFmpeg Mastery ⭐
- **[FFmpeg libav Tutorial](https://github.com/leandromoreira/ffmpeg-libav-tutorial)**
  - ⏱️ Time: 4-6 hours
  - 💻 Hands-on C examples
  - ✅ Action: Code along with examples 0-3

- **[FFmpeg Official Documentation](https://ffmpeg.org/ffmpeg.html)**
  - 📚 Reference as needed
  - 🎯 Focus on: `-i`, `-c:v`, `-c:a`, `-b:v`, `-r`, `-s` flags

- **[FFmpeg Encoding and Editing Course](https://www.youtube.com/watch?v=MPV7JXTWPWI)** (YouTube)
  - ⏱️ Time: 3 hours
  - 💼 Practical command-line usage

### 🎥 Video Tutorials & Tech Talks

#### Fundamentals (Watch 3-4 of these)
- **[How Video Compression Works](https://www.youtube.com/watch?v=QoZ8pccsYo4)** - Branch Education (15 min)
- **[H.264 is Magic](https://www.youtube.com/watch?v=cWX8HqJIaBw)** - Computerphile (10 min)
- **[Understanding Video Codecs](https://www.youtube.com/watch?v=sisvOeZItb4)** - Vox (8 min)
- **[How do Video Codecs Work?](https://www.youtube.com/watch?v=C7gPM4Q1c4g)** - Reducible (20 min)
- **[AV1 vs H.265 vs H.264](https://www.youtube.com/watch?v=hok1-7_V0x4)** - Linus Tech Tips (12 min)

#### Deep Dives (Pick 1-2)
- **[Netflix: Per-Title Encode Optimization](https://netflixtechblog.com/per-title-encode-optimization-7e99442b62a2)** (Blog post, 15 min)
- **[YouTube: Shadow Ban System & Video Processing](https://www.youtube.com/watch?v=eIho2S0ZahI)** (35 min)
- **[Bitmovin: Video Encoding Basics](https://www.youtube.com/watch?v=3DQn4OfNmxU)** (20 min)

### 🛠️ Project 1.1: CLI Video Transcoder Tool

#### 📦 Deliverable
Production-ready CLI tool on GitHub

#### ✅ Requirements
- Convert between formats (MP4, WebM, MKV, AVI)
- Generate multiple resolutions (1080p, 720p, 480p, 360p)
- Extract video metadata (codec, bitrate, duration, fps)
- Show progress bar with ETA
- Batch processing support
- Quality presets (high/medium/low)
- Audio track handling

#### 🔧 Tech Stack
- **Language**: Python (Click/Typer for CLI) OR Node.js (Commander.js)
- **Processing**: FFmpeg (subprocess calls)
- **UI**: Rich (Python) / Inquirer (Node.js)

#### 📁 Project Structure
```
video-transcoder/
├── README.md (with examples, screenshots)
├── requirements.txt / package.json
├── src/
│   ├── transcoder.py (main logic)
│   ├── presets.py (encoding profiles)
│   └── utils.py (metadata extraction)
├── tests/
│   └── test_transcoder.py
├── examples/
│   └── sample_output.mp4
└── docs/
    └── architecture.md
```

#### 🔗 Resources for Building
- [Click Documentation](https://click.palletsprojects.com/) (Python CLI)
- [Commander.js](https://github.com/tj/commander.js) (Node.js CLI)
- [Rich - Beautiful terminal output](https://github.com/Textualize/rich)
- [FFmpeg Python wrapper](https://github.com/kkroening/ffmpeg-python)

#### ✅ Success Criteria
- [ ] Process 10+ test videos successfully
- [ ] Clean README with usage examples
- [ ] Error handling (missing codecs, invalid files)
- [ ] Published to GitHub with MIT license

---

## Week 3-4: Adaptive Streaming (HLS/DASH)

### 🎯 Goal
Build mini HLS demo (🎯 **DEC 1 MILESTONE**)

### 📖 Core Learning Resources

#### HLS/DASH Fundamentals ⭐
- **[Apple HLS Specification](https://developer.apple.com/streaming/)**
  - ⏱️ Time: 3 hours (skim technical sections)
  - 🎯 Focus on: playlist formats, segment structure, variant streams

- **[HTTP Live Streaming Explained](https://www.cloudflare.com/learning/video/what-is-http-live-streaming/)** - Cloudflare
  - ⏱️ Time: 20 min
  - 📊 Great visual overview

- **[DASH vs HLS](https://www.cloudflare.com/learning/video/what-is-mpeg-dash/)** - Cloudflare
  - ⏱️ Time: 15 min

- **[HLS.js Documentation](https://github.com/video-dev/hls.js/)** ⭐
  - 📚 Reference for building player

- **[Video.js Documentation](https://videojs.com/guides/)**
  - 🎬 Alternative player library

### 🎥 Video Tutorials & Tech Talks

#### HLS/ABR Streaming (Watch 3-5)
- **[HTTP Live Streaming Tutorial](https://www.youtube.com/watch?v=A2qOAyU26xE)** - Alex Pham (25 min)
- **[Adaptive Bitrate Streaming Explained](https://www.youtube.com/watch?v=JC4kZDhVQp4)** - AWS (15 min)
- **[Building a Video Streaming Platform](https://www.youtube.com/watch?v=sCA4l3Bw01w)** - Hussein Nasser (40 min)
- **[HLS vs DASH vs WebRTC](https://www.youtube.com/watch?v=3DQn4OfNmxU)** - Bitmovin (22 min)

#### Production-Scale Streaming
- **[Twitch: Low Latency HLS](https://blog.twitch.tv/en/2020/03/04/introducing-low-latency-hls/)** (Blog, 10 min)
- **[Netflix: Streaming at Scale](https://www.youtube.com/watch?v=6oPj-DW_6R4)** - QCon (45 min)
- **[YouTube's Video Infrastructure](https://www.youtube.com/watch?v=lWO8n_RSVqg)** - Strange Loop (50 min)
- **[Mux: Video Streaming Architecture](https://www.youtube.com/watch?v=Fq4VwBeMjrA)** (35 min)

### 🛠️ Project 1.2: Mini HLS Demo System

#### 📦 Deliverable
Working adaptive streaming demo (🎯 **DEC 1 MILESTONE**)

#### ✅ Requirements
- FFmpeg pipeline generating HLS segments
- Master playlist with 3+ quality levels (1080p, 720p, 480p)
- Generate .m3u8 playlists + .ts segments
- Web-based video player (HLS.js or Video.js)
- Local server (Express/Flask)
- Bitrate switching visualization
- Architecture documentation

#### 🔧 Tech Stack
- **Backend**: Node.js (Express) OR Python (Flask)
- **Player**: HLS.js or Video.js
- **Processing**: FFmpeg
- **Frontend**: Plain HTML/CSS/JS (keep it simple)

#### 💻 Key FFmpeg Command
```bash
# Generate HLS with multiple bitrates
ffmpeg -i input.mp4 \
  -filter_complex "[0:v]split=3[v1][v2][v3]; \
    [v1]scale=w=1920:h=1080[v1out]; \
    [v2]scale=w=1280:h=720[v2out]; \
    [v3]scale=w=854:h=480[v3out]" \
  -map "[v1out]" -c:v:0 libx264 -b:v:0 5M \
  -map "[v2out]" -c:v:1 libx264 -b:v:1 2.8M \
  -map "[v3out]" -c:v:2 libx264 -b:v:2 1.4M \
  -map a:0 -c:a aac -b:a 128k \
  -f hls -hls_time 4 -hls_playlist_type vod \
  -hls_segment_filename "stream_%v/data%03d.ts" \
  -master_pl_name master.m3u8 \
  -var_stream_map "v:0,a:0 v:1,a:0 v:2,a:0" stream_%v.m3u8
```

#### 📁 Project Structure
```
hls-demo/
├── README.md
├── server.js / app.py
├── package.json
├── public/
│   ├── index.html (video player)
│   ├── style.css
│   └── player.js
├── videos/
│   └── sample.mp4
├── output/
│   ├── master.m3u8
│   ├── stream_0/ (1080p segments)
│   ├── stream_1/ (720p segments)
│   └── stream_2/ (480p segments)
├── scripts/
│   └── generate_hls.sh
└── docs/
    └── ARCHITECTURE.md (with diagrams!)
```

#### 🔗 Tutorials for Building
- **[Building an HLS Video Server](https://www.youtube.com/watch?v=ZjSYxDzH-IY)** (YouTube, 30 min)
- **[HLS.js Quickstart](https://github.com/video-dev/hls.js/#getting-started)**
- **[Express.js Static File Serving](https://expressjs.com/en/starter/static-files.html)**

#### 🎁 Bonus Features (if time permits)
- Quality level selector UI
- Bandwidth simulation (throttle network)
- Analytics (track quality switches)
- Thumbnail generation for seek preview

#### ✅ Success Criteria
- [ ] Video plays in browser with adaptive switching
- [ ] Clean architecture diagram (use Excalidraw/draw.io)
- [ ] GitHub repo with demo GIF/video
- [ ] Can explain in interviews: "I built an HLS streaming system..."

---

# 🚀 MONTH 2: Cloud Infrastructure & Production System

## Week 5-6: Cloud Architecture & Distributed Processing

### 🎯 Goal
Move from local to cloud, understand scale

### 📖 Core Learning Resources

#### Distributed Systems Fundamentals ⭐
- **[Designing Data-Intensive Applications](https://www.oreilly.com/library/view/designing-data-intensive-applications/9781491903063/)** (Book)
  - ⏱️ Time: 12 hours (selective reading)
  - 📖 Read: Chapter 1 (Foundations), Chapter 3 (Storage), Chapter 5 (Replication)
  - ⏭️ Skip: Chapters on transactions, consistency (not critical for video)

- **[System Design Primer](https://github.com/donnemartin/system-design-primer)** (GitHub) ⭐
  - 📖 Section: Scalability, Load Balancing, CDNs
  - ⏱️ Time: 4-6 hours

#### Cloud Video Services
- **[AWS Elemental MediaConvert Docs](https://docs.aws.amazon.com/mediaconvert/)**
  - ⏱️ Time: 2 hours (overview only)

- **[GCP Transcoder API Overview](https://cloud.google.com/transcoder/docs/concepts/overview)**
  - ⏱️ Time: 1 hour

- **[Azure Media Services](https://learn.microsoft.com/en-us/azure/media-services/)**
  - ⏱️ Time: 1 hour (optional, for comparison)

#### CDN & Delivery
- **[How CDNs Work](https://www.cloudflare.com/learning/cdn/what-is-a-cdn/)** - Cloudflare
  - ⏱️ Time: 30 min

- **[AWS CloudFront Documentation](https://docs.aws.amazon.com/cloudfront/)**
  - 🎯 Focus on: Origins, behaviors, cache policies

- **[Fastly: Edge Computing for Video](https://www.fastly.com/blog/video-streaming-at-the-edge)**
  - ⏱️ Time: 20 min

### 🎥 Video Tutorials & Tech Talks

#### Cloud Architecture (Watch 4-6)
- **[Scalable Video Processing on AWS](https://www.youtube.com/watch?v=KfxgfgwYqzE)** - AWS re:Invent (45 min)
- **[Serverless Video Processing](https://www.youtube.com/watch?v=lAYIv95WdDU)** - AWS (35 min)
- **[Building a Video Streaming Service](https://www.youtube.com/watch?v=psQzyFfsUGU)** - Hussein Nasser (50 min)
- **[Netflix Cloud Architecture](https://www.youtube.com/watch?v=CZ3wIuvmHeM)** - InfoQ (40 min)
- **[Designing for Scale](https://www.youtube.com/watch?v=modXC5IWTJI)** - GitHub (30 min)

#### CDN & Performance
- **[How Cloudflare Works](https://www.youtube.com/watch?v=aeZVn3STojA)** (20 min)
- **[CDN Architecture Deep Dive](https://www.youtube.com/watch?v=8zX0rue2Hic)** - Fastly (35 min)
- **[Video Delivery Optimization](https://www.youtube.com/watch?v=3DQn4OfNmxU)** - Bitmovin (30 min)

### 🛠️ Project 2.1: Cloud Video Processing Pipeline

#### 📦 Deliverable
Serverless video transcoding system

#### ✅ Requirements
- S3/GCS bucket for video uploads
- Lambda/Cloud Functions triggered on upload
- Transcode to HLS/DASH in cloud
- Store output in CDN-backed storage
- Async job queue (SQS/Pub-Sub)
- Signed URLs for secure access
- Basic API (upload, status, download)

#### 🔧 Tech Stack
- **Cloud**: AWS (Lambda, S3, CloudFront, SQS) OR GCP
- **Backend**: Python (Boto3) or Node.js
- **Transcoding**: FFmpeg layer or cloud service
- **Queue**: AWS SQS or GCP Pub/Sub
- **API**: API Gateway or Cloud Functions

#### 🏗️ Architecture Pattern
```
Upload → S3 → EventBridge → Lambda (Job Creator) → SQS
                                                      ↓
                                         Lambda (Worker) → Transcode
                                                      ↓
                                         S3 (Output) → CloudFront
```

#### 🔗 Tutorials for Building
- **[Serverless Video Transcoding Tutorial](https://aws.amazon.com/blogs/media/processing-user-generated-content-using-aws-lambda-and-ffmpeg/)** - AWS Blog
- **[Building with AWS Lambda Layers](https://www.youtube.com/watch?v=LVNUv1TGPbA)** (YouTube, 25 min)
- **[S3 Event Notifications](https://docs.aws.amazon.com/AmazonS3/latest/userguide/NotificationHowTo.html)**
- **[Cloud Functions Tutorial](https://www.youtube.com/watch?v=1nzjLBM3hbE)** (GCP, 20 min)

#### 💻 Key Implementation Pattern
```python
# Lambda function structure
def lambda_handler(event, context):
    # 1. Parse S3 event
    # 2. Download video from S3
    # 3. Transcode with FFmpeg
    # 4. Upload segments to S3
    # 5. Update job status in DynamoDB
    # 6. Send completion webhook
```

#### ✅ Success Criteria
- [ ] Upload video via API → automatic transcoding
- [ ] Multiple concurrent jobs handled
- [ ] CDN delivers content globally
- [ ] Cost tracking (storage + bandwidth)

---

## Week 7-8: Production Features & Monitoring

### 🎯 Goal
Build dashboard + observability (🎯 **JAN 5 MILESTONE**)

### 📖 Core Learning Resources

#### Observability & Monitoring ⭐
- **[Google SRE Book](https://sre.google/sre-book/table-of-contents/)**
  - ⏱️ Time: 6 hours
  - 📖 Read: Chapter 4 (Service Level Objectives), Chapter 6 (Monitoring)

- **[Prometheus Documentation](https://prometheus.io/docs/introduction/overview/)**
  - ⏱️ Time: 3 hours
  - 🎯 Focus on: Metrics types, PromQL basics

- **[Grafana Fundamentals](https://grafana.com/tutorials/grafana-fundamentals/)**
  - ⏱️ Time: 2 hours
  - 💻 Hands-on tutorial

#### Video Quality Metrics
- **[Netflix: VMAF](https://netflixtechblog.com/toward-a-practical-perceptual-video-quality-metric-653f208b9652)** (Blog, 15 min)
- **[Understanding PSNR and SSIM](https://www.streamingmedia.com/Articles/Editorial/What-Is-.../What-Is-PSNR-and-Why-Does-It-Matter-145664.aspx)** (Article, 10 min)
- **[FFmpeg Quality Metrics](https://trac.ffmpeg.org/wiki/FilteringGuide#QualityMetrics)**

### 🎥 Video Tutorials & Tech Talks

#### Production Engineering (Watch 4-5)
- **[Monitoring & Observability](https://www.youtube.com/watch?v=1wjovFSCGhE)** - Charity Majors (45 min)
- **[Prometheus & Grafana Tutorial](https://www.youtube.com/watch?v=h4Sl21AKiDg)** - TechWorld with Nana (30 min)
- **[Building Production-Ready Systems](https://www.youtube.com/watch?v=sQF0cDQYXv4)** (40 min)
- **[Mux: Video Analytics Architecture](https://www.youtube.com/watch?v=Fq4VwBeMjrA)** (35 min)

#### Dashboard & API Design
- **[Building Admin Dashboards](https://www.youtube.com/watch?v=OBOiTVVWCXs)** (React, 50 min)
- **[REST API Best Practices](https://www.youtube.com/watch?v=6a59roRIXiY)** (30 min)
- **[WebSocket for Real-time Updates](https://www.youtube.com/watch?v=1BfCnjr_Vjg)** (25 min)

### 🛠️ Project 2.2: Production Dashboard System

#### 📦 Deliverable
Full-stack video platform (🎯 **JAN 5 MILESTONE**)

#### ✅ Requirements
- Web dashboard (React/Next.js/Vue)
- Video upload interface with drag-drop
- Real-time job status tracking
- Quality metrics visualization
- CDN analytics (bandwidth, cache hits)
- Job retry + error handling
- Webhook notifications
- Cost tracking dashboard
- Prometheus metrics + Grafana
- Load test (20+ concurrent videos)

#### 🔧 Tech Stack
- **Frontend**: React + TailwindCSS OR Next.js
- **Backend**: Node.js (Express) or Python (FastAPI)
- **Database**: PostgreSQL (job metadata) + Redis (cache)
- **Monitoring**: Prometheus + Grafana
- **Deployment**: Docker Compose or Kubernetes

#### 📱 Dashboard Features

**Pages Structure:**
1. **Upload Page**
   - Drag-drop interface
   - Multi-file support
   - Progress bars

2. **Jobs Dashboard**
   - Table of all transcode jobs
   - Status (queued/processing/completed/failed)
   - Real-time updates (WebSocket)
   - Retry failed jobs

3. **Analytics Page**
   - Total videos processed
   - Average transcode time
   - Quality metrics charts (VMAF, file size)
   - CDN bandwidth usage
   - Cost breakdown

4. **Video Library**
   - Grid view of processed videos
   - Preview + download links
   - Quality variants selector

5. **System Health**
   - Grafana embedded dashboard
   - Worker status
   - Queue depth
   - Error rates

#### 📊 Monitoring Stack
```yaml
# docker-compose.yml snippet
services:
  prometheus:
    image: prom/prometheus
    volumes:
      - ./prometheus.yml:/etc/prometheus/prometheus.yml
  
  grafana:
    image: grafana/grafana
    ports:
      - "3000:3000"
  
  app:
    build: .
    environment:
      - METRICS_ENABLED=true
```

#### 📈 Metrics to Track
```python
# Prometheus metrics examples
transcode_duration_seconds = Histogram('transcode_duration', 'Transcode time')
transcode_total = Counter('transcode_total', 'Total transcodes', ['status'])
queue_depth = Gauge('queue_depth', 'Jobs in queue')
output_file_size_bytes = Histogram('output_size', 'Output file size')
vmaf_score = Histogram('vmaf_score', 'Video quality score')
```

#### 🔗 Tutorials for Building
- **[Building a Video Upload Platform](https://www.youtube.com/watch?v=Jm9jXYxe09k)** (YouTube, 45 min)
- **[React Dashboard Tutorial](https://www.youtube.com/watch?v=0cPCMIuDk2I)** (1 hour)
- **[Prometheus + Node.js](https://www.youtube.com/watch?v=TpMxvHJ8KN8)** (30 min)
- **[Docker Compose Full Tutorial](https://www.youtube.com/watch?v=DM65_JyGxCo)** (40 min)

#### 🧪 Load Testing
```bash
# Use Apache Bench or k6
k6 run --vus 20 --duration 30s load-test.js

# Or custom script
for i in {1..20}; do
  curl -F "video=@test$i.mp4" http://localhost:3000/upload &
done
```

#### ✅ Success Criteria
- [ ] Can upload + process 20 videos simultaneously
- [ ] Dashboard updates in real-time
- [ ] Grafana shows system health
- [ ] Professional UI (looks like a real product)
- [ ] Deployed to cloud (AWS/GCP/DigitalOcean)
- [ ] Can demo live in interviews

---

# ⚡ MONTH 3: Real-time Systems & Portfolio Polish

## Week 9-10: Real-time Video Processing

### 🎯 Goal
Add live streaming OR real-time features

### 📖 Core Learning Resources

#### WebRTC Fundamentals ⭐
- **[WebRTC for the Curious](https://webrtcforthecurious.com/)**
  - ⏱️ Time: 6-8 hours
  - 📖 Read: Chapters 1-4 (Intro through Media Communication)
  - 💻 Hands-on examples

- **[MDN WebRTC API](https://developer.mozilla.org/en-US/docs/Web/API/WebRTC_API)**
  - 📚 Reference guide

#### Low-Latency Streaming
- **[Apple LL-HLS Spec](https://developer.apple.com/documentation/http_live_streaming/protocol_extension_for_low-latency_hls_preliminary_specification)**
  - ⏱️ Time: 2 hours (technical, skim)

- **[RTMP vs HLS vs WebRTC](https://www.wowza.com/blog/streaming-protocols)** (Article, 15 min)
- **[WebRTC vs RTMP](https://bloggeek.me/webrtc-vs-rtmp/)** (Article, 10 min)

### 🎥 Video Tutorials & Tech Talks

#### Real-time Streaming (Watch 5-7)
- **[WebRTC Crash Course](https://www.youtube.com/watch?v=WmR9IMUD_CY)** - Traversy Media (30 min)
- **[Building Live Streaming with WebRTC](https://www.youtube.com/watch?v=QsH8FL0952k)** - Hussein Nasser (45 min)
- **[Discord: WebRTC at Scale](https://www.youtube.com/watch?v=UrdvXHN2Aq8)** (35 min)
- **[Live Streaming Architecture](https://www.youtube.com/watch?v=73QwBxb_jYo)** (40 min)
- **[OBS + RTMP Tutorial](https://www.youtube.com/watch?v=eeKv2lIy2O8)** (25 min)
- **[Low Latency HLS Explained](https://www.youtube.com/watch?v=Oc5Xn6FXr7Y)** (20 min)

#### Advanced Topics
- **[Zoom: Video Conferencing at Scale](https://www.youtube.com/watch?v=7vP0vSXYPho)** (45 min)
- **[Google Meet Architecture](https://www.youtube.com/watch?v=7vP0vSXYPho)** (30 min)

### 🛠️ Project 3.1: Real-time Video System

#### 📦 Choose ONE Option:

---

### OPTION A: Live Streaming Platform (Recommended)

#### ✅ Requirements
- RTMP server accepting live streams
- Real-time transcoding to HLS/DASH
- <5 second glass-to-glass latency
- Simple broadcast UI (OBS → Server → Viewers)
- Multiple concurrent streams
- Chat integration (optional)
- Stream recording/VOD

#### 🔧 Tech Stack
- **RTMP**: Node-Media-Server or nginx-rtmp
- **Backend**: Node.js or Go
- **Player**: Video.js with HLS plugin
- **Frontend**: React for viewer page

#### 🔗 Tutorials
- **[Build a Live Streaming Server](https://www.youtube.com/watch?v=RlAe3CqFNJ4)** (YouTube, 50 min)
- **[RTMP Server Setup](https://www.youtube.com/watch?v=Suu6E_V6Z9Q)** (30 min)
- **[OBS to Custom RTMP](https://www.youtube.com/watch?v=cXIxJbq2DhY)** (20 min)

---

### OPTION B: Real-time Video Processing API

#### ✅ Requirements
- WebRTC-based video upload
- Real-time filters/effects (grayscale, blur, overlay)
- Sub-second latency
- Browser → Server → Processed → Browser
- Multiple effect pipelines

#### 🔧 Tech Stack
- **WebRTC**: Simple-peer or PeerJS
- **Backend**: Node.js with ws (WebSocket)
- **Processing**: FFmpeg or OpenCV
- **Frontend**: Plain JS with Canvas API

#### 🔗 Tutorials
- **[WebRTC Video Processing](https://www.youtube.com/watch?v=QsH8FL0952k)** (45 min)
- **[Canvas Video Manipulation](https://www.youtube.com/watch?v=x_dRUQxmT1U)** (30 min)
- **[Real-time Filters with OpenCV](https://www.youtube.com/watch?v=5h0TBr7mDlY)** (35 min)

---

### OPTION C: Adaptive Bitrate Optimizer

#### ✅ Requirements
- ML/heuristic algorithm for quality selection
- Network condition measurement
- Dynamic quality switching
- A/B test vs fixed ladder
- Analytics on user experience

#### 🔧 Tech Stack
- **Backend**: Python (FastAPI) + ML library
- **Player**: Custom HLS.js integration
- **Analytics**: PostgreSQL + Grafana
- **Network simulation**: Network throttling

---

#### ✅ Success Criteria (Any Option)
- [ ] Working demo with <5s latency
- [ ] Handles 10+ concurrent users
- [ ] Clean architecture
- [ ] Recorded demo video

---

## Week 11-12: Portfolio Polish & Content Creation

### 🎯 Goal
Package everything for job applications (🎯 **JAN 31 MILESTONE**)

---

### 📝 GitHub Repository Polish

#### For BOTH Repos: HLS Pipeline + Real-time System

**Polish Checklist:**
- [ ] Comprehensive README with:
  - [ ] Banner image/logo
  - [ ] Clear problem statement
  - [ ] Architecture diagram (Excalidraw/draw.io)
  - [ ] Installation guide (Docker Compose one-liner)
  - [ ] Usage examples with screenshots
  - [ ] API documentation
  - [ ] Performance benchmarks (table format)
  - [ ] Tech stack badges
- [ ] CONTRIBUTING.md
- [ ] LICENSE (MIT)
- [ ] Clean code with comments
- [ ] CI/CD pipeline (GitHub Actions):
  - [ ] Linting
  - [ ] Tests
  - [ ] Docker build
- [ ] Demo deployed (free tier: Render, Railway, Fly.io)
- [ ] Demo video/GIF in README

#### 🎨 Diagram Tools
- **[Excalidraw](https://excalidraw.com/)** - Hand-drawn style diagrams
- **[draw.io](https://draw.io)** - Professional diagrams
- **[tldraw](https://www.tldraw.com/)** - Simple sketches

#### 🔗 README Resources
- **[How to Write Great README](https://www.youtube.com/watch?v=E6NO0rgFub4)** (15 min)
- **[Best GitHub README Templates](https://github.com/othneildrew/Best-README-Template)**
- **[GitHub Actions CI/CD](https://www.youtube.com/watch?v=R8_veQiYBjI)** (30 min)

---

### 📝 Medium Blog Post (2000-2500 words)

#### Title Ideas
- "Building a Cloud Video Streaming Platform from Scratch"
- "What I Learned Building Netflix's Pipeline (in 3 Months)"
- "A New Grad's Guide to Video Infrastructure Engineering"
- "From FFmpeg to Production: Scaling Adaptive Streaming"

#### Article Structure
```markdown
# Introduction (200 words)
- Hook: "Video streaming is everywhere, but how does it work?"
- Your motivation
- What you built

# The Problem (300 words)
- Why video streaming is hard
- Technical challenges (bandwidth, latency, quality)
- Industry context (Netflix, YouTube scale)

# Architecture (600 words)
- System design diagram
- Component breakdown:
  - Upload pipeline
  - Transcoding workers
  - Adaptive streaming
  - CDN delivery
- Tech stack decisions

# Technical Deep Dives (800 words)
Pick 2-3 interesting problems you solved:
- "Challenge 1: Optimizing Encoding for Quality vs Speed"
- "Challenge 2: Handling Failed Jobs at Scale"
- "Challenge 3: Real-time Quality Switching"

Each with:
- Problem description
- Solution approach
- Code snippets (syntax highlighted)
- Results/metrics

# Results & Learnings (400 words)
- Performance metrics:
  - X videos processed
  - Y concurrent streams
  - Z% bandwidth savings
  - Latency numbers
- What surprised you
- What you'd do differently

# Conclusion (200 words)
- Key takeaways
- Resources for readers
- Call to action (check out repos)
```

#### 🔗 Writing Resources
- **[Technical Writing Tips](https://www.youtube.com/watch?v=YODPgBadj80)** (15 min)
- **[Medium's Partner Program](https://medium.com/creators)** (monetization)
- **[Dev.to Writing Guide](https://dev.to/t/writing)**

#### 📢 Distribution Strategy
- **Post on**: Medium, Dev.to, Hashnode, HackerNoon
- **Share on**: LinkedIn, Twitter, Reddit (r/programming, r/webdev)
- **Submit to**: HackerNews, Lobsters

---

### 🎨 Portfolio Website Updates

#### Project Page Template
```html
<section class="project">
  <h2>Cloud Video Streaming Platform</h2>
  
  <!-- Hero image/demo GIF -->
  <img src="demo.gif" alt="Live demo">
  
  <!-- Quick stats -->
  <div class="stats">
    <span>1000+ videos processed</span>
    <span>50 concurrent streams</span>
    <span>40% bandwidth savings</span>
  </div>
  
  <!-- Architecture diagram -->
  <img src="architecture.png" alt="System design">
  
  <!-- Tech stack -->
  <div class="tech-stack">
    <span>FFmpeg</span>
    <span>AWS Lambda</span>
    <span>React</span>
    <span>Docker</span>
  </div>
  
  <!-- Links -->
  <a href="github.com/...">View Code</a>
  <a href="demo.com">Live Demo</a>
  <a href="medium.com/...">Read Article</a>
</section>
```

#### 🔗 Portfolio Builders
- **[Vercel Portfolio Template](https://vercel.com/templates/next.js/portfolio-starter-kit)**
- **[Gatsby Portfolio Themes](https://www.gatsbyjs.com/starters/?c=Portfolio)**
- **Simple HTML/CSS** (if you want full control)

---

### 📄 Resume Updates

#### Project Section Format

```
PROJECTS

Cloud Video Streaming Platform | Python, FFmpeg, AWS, React, Docker
[GitHub Link] [Live Demo] [Blog Post]
• Built adaptive bitrate streaming system processing 1,000+ videos with HLS/DASH support
• Architected serverless pipeline on AWS (Lambda, S3, CloudFront) achieving <2s global CDN delivery
• Implemented real-time monitoring dashboard tracking quality metrics (VMAF, bitrate, latency)
• Achieved 40% bandwidth reduction through per-title encoding optimization
• Deployed production system handling 50 concurrent streams with 99.9% uptime

Real-time Video Processing Engine | Node.js, WebRTC, RTMP, Redis
[GitHub Link] [Live Demo]
• Developed low-latency live streaming platform with <3s glass-to-glass latency
• Designed RTMP ingestion pipeline handling 20+ concurrent broadcast streams
• Built adaptive quality algorithm reducing buffering by 35% under network congestion
• Integrated WebSocket-based real-time analytics tracking 10+ performance metrics
```

#### Key Metrics to Include
- Number of videos/streams processed
- Latency numbers
- Bandwidth/cost savings
- Concurrent users/streams
- Performance improvements (%)
- Uptime/reliability stats

#### 🔗 Resume Resources
- **[Tech Resume Template](https://www.overleaf.com/latex/templates/jakes-resume/syzfjbzwjncs)** (LaTeX)
- **[Resume Review Subreddit](https://www.reddit.com/r/EngineeringResumes/)**
- **[ATS-Friendly Formatting](https://www.jobscan.co/blog/ats-friendly-resume/)**

---

### 🎥 Demo Videos

#### Record 2-3 Short Videos

**Video 1: System Overview (2-3 min)**
```
Script:
1. Quick intro: "I built a cloud video streaming platform"
2. Show architecture diagram
3. Live demo:
   - Upload video
   - Show transcoding in progress
   - Play adaptive stream
   - Show quality switching
4. Mention tech stack
5. CTA: "Check out the code on GitHub"
```

**Video 2: Technical Deep Dive (5 min)**
```
Script:
1. Code walkthrough
2. Explain key algorithms
3. Show monitoring dashboard
4. Discuss challenges solved
```

#### 🎬 Recording Tools
- **Loom** (easy screen recording)
- **OBS Studio** (professional recording)
- **DaVinci Resolve** (free editing)

---

## ✅ Final Checklist (Jan 31 Deadline)

### GitHub
- [ ] 2 repos with 100+ commits total
- [ ] Comprehensive READMEs with diagrams
- [ ] CI/CD pipelines passing
- [ ] Live demos deployed
- [ ] MIT License added
- [ ] Tagged releases (v1.0.0)

### Content
- [ ] 2000+ word Medium article published
- [ ] Shared on LinkedIn, Twitter, Reddit
- [ ] Submitted to HackerNews/Lobsters
- [ ] Cross-posted to Dev.to

### Portfolio
- [ ] Projects page updated with new work
- [ ] Architecture diagrams added
- [ ] Demo videos embedded
- [ ] Performance metrics highlighted

### Resume
- [ ] Projects section updated
- [ ] Quantified achievements added
- [ ] Tech stack aligned with job descriptions
- [ ] ATS-optimized formatting
- [ ] Exported as PDF

### Demo Materials
- [ ] 3-5 min video walkthrough recorded
- [ ] Screenshots for presentations
- [ ] Talking points for interviews
- [ ] Practice explaining system design

---

## 📊 Success Metrics

### By Feb 1, 2026, you should have:
- ✅ 2 production-quality GitHub repos (aim for 100+ stars)
- ✅ 1 technical blog post (aim for 1000+ views)
- ✅ Working demos (live URLs you can share)
- ✅ Resume with quantified impact
- ✅ Portfolio showcasing video systems expertise

### Interview-Ready Materials:
- ✅ Can explain entire system in 5 minutes
- ✅ Can discuss tradeoffs and alternatives
- ✅ Can walk through code architecture
- ✅ Can answer: "Why video infrastructure?"

---

## 🔗 Master Resource List

### 📚 Essential Bookmarks
- [Digital Video Introduction](https://github.com/leandromoreira/digital_video_introduction)
- [FFmpeg libav Tutorial](https://github.com/leandromoreira/ffmpeg-libav-tutorial)
- [WebRTC for the Curious](https://webrtcforthecurious.com/)
- [System Design Primer](https://github.com/donnemartin/system-design-primer)
- [Designing Data-Intensive Applications](https://dataintensive.net/)

### 📰 Follow These Blogs
- [Netflix Tech Blog](https://netflixtechblog.com/)
- [YouTube Engineering Blog](https://blog.youtube/)
- [Twitch Engineering Blog](https://blog.twitch.tv/en/tags/engineering/)
- [Mux Blog](https://mux.com/blog/)
- [Cloudflare Blog - Video](https://blog.cloudflare.com/tag/video/)
- [AWS Media Blog](https://aws.amazon.com/blogs/media/)

### 👥 Communities
- [r/ffmpeg](https://reddit.com/r/ffmpeg)
- [r/webdev](https://reddit.com/r/webdev)
- [Video Dev Slack](https://video-dev.slack.com/)
- [HackerNews](https://news.ycombinator.com/)

---

## ⏰ Weekly Time Breakdown

### Typical Week (25-35 hours):
- **Learning** (10-15 hrs): Reading docs, watching talks, tutorials
- **Building** (15-20 hrs): Hands-on coding, debugging, deploying
- **Documentation** (2-3 hrs): README, blog drafts, comments
- **Review** (2 hrs): Code review, testing, performance tuning

### Adjust based on schedule:
- **Winter break?** → Front-load to 40 hrs/week
- **Full-time student?** → 20-25 hrs/week, extend timeline

---

## 💡 Pro Tips

1. **Start small, iterate fast**: Get something working in Week 1, then improve
2. **Document as you go**: Write README sections after each feature
3. **Ask for help**: Reddit, Discord, StackOverflow are your friends
4. **Share progress**: Tweet/LinkedIn updates build your brand
5. **Focus on one project at a time**: Finish before moving to next
6. **Test with real videos**: Use diverse content (short/long, different codecs)
7. **Measure everything**: Metrics make your projects impressive
8. **Keep it simple**: Working > perfect

---

## 🎯 Next Steps

### Tomorrow (Day 1):
1. ⏰ Block out 2 hours in your calendar
2. 📖 Start reading: [Digital Video Introduction](https://github.com/leandromoreira/digital_video_introduction)
3. 💻 Clone the repo and run the examples
4. 📝 Create a GitHub repo for Project 1.1 (CLI Transcoder)

### This Week:
- [ ] Complete Digital Video Introduction reading
- [ ] Watch 3-4 fundamental video tutorials
- [ ] Start building CLI transcoder tool
- [ ] Set up development environment (FFmpeg, Python/Node.js)

### Week 2 Goal:
- [ ] Complete CLI transcoder with all features
- [ ] Polish README with examples
- [ ] Push to GitHub
- [ ] Share on LinkedIn

---

**This plan is aggressive but achievable. You've got this! 🚀**

**Start tomorrow with the Digital Video Introduction repo. Set a timer for 2 hours and just begin.**

---

*Last Updated: November 2025*
*Plan Duration: 3 months (Dec 2025 - Feb 2026)*
*Target: Video Infrastructure Engineering Roles*
