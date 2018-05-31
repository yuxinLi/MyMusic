//
// Created by yuxin on 2018-05-31.
//

#ifndef MYMUSIC_WLFFMPEG_H
#define MYMUSIC_WLFFMPEG_H


#include "WlCallJava.h"
#include "pthread.h"
#include "WlAudio.h"
#include "WlPlayStatus.h"

extern "C"{
#include "libavformat/avformat.h"
};

class WlFFmpeg{

public:
    WlCallJava *callJava = NULL;
    const char* url = NULL;
    pthread_t decodeThread;
    AVFormatContext *pFormatCtx = NULL;
    WlAudio *audio = NULL;

    WlPlayStatus *playStatus = NULL;

public:
    WlFFmpeg(WlPlayStatus *playstatus , WlCallJava *callJava, const char *url);
    ~WlFFmpeg();

    void parpared();
    void decodeFFmpegThread();
    void start();

};


#endif //MYMUSIC_WLFFMPEG_H
