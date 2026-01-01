CC := gcc
TARGET := ffmpeg-output


SRC_DIR := src
INC_DIR := inc
SRC = $(SRC_DIR)/ffmpeg-practice.c

PKG_CONFIG := pkg-config
FFMPEG_LIBS := libavcodec libavutil libavformat

CFLAGS := -std=c11 -Wall -Wextra \
		$(shell $(PKG_CONFIG) --cflags $(FFMPEG_LIBS))

LDLIBS := $(shell $(PKG_CONFIG) --libs $(FFMPEG_LIBS))

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -f $(TARGET)

.PHONY: all clean