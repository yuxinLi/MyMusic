//
// Created by yuxin on 2018-05-31.
//

#ifndef MYMUSIC_WLQUEUE_H
#define MYMUSIC_WLQUEUE_H

#include "queue"
#include "pthread.h"
#include "AndroidLog.h"
#include "WlPlayStatus.h"

extern "C"{
#include "libavcodec/avcodec.h"
};


class WlQueue{

public:
    std::queue<AVPacket*> queuePacket;
    pthread_mutex_t mutexPacket;
    pthread_cond_t condPacket;
    WlPlayStatus *playStatus = NULL;

public:
    WlQueue(WlPlayStatus *playStatus);
    ~WlQueue();

    int putAvpacket(AVPacket *packet);
    int getAvpacket(AVPacket *packet);

    int getQueueSize();
};


#endif //MYMUSIC_WLQUEUE_H


















