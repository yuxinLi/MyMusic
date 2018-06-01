//
// Created by yuxin on 2018-05-31.
//

#include "WlPlayStatus.h"
#include "WlQueue.h"

WlQueue::WlQueue(WlPlayStatus *playStatus) {

    this->playStatus = playStatus;
    pthread_mutex_init(&mutexPacket , NULL);
    pthread_cond_init(&condPacket , NULL);
}

WlQueue::~WlQueue() {

}

int WlQueue::putAvpacket(AVPacket *packet) {


    pthread_mutex_lock(&mutexPacket);
    queuePacket.push(packet);
    if(LOG_DEBUG)
    {
        LOGD("放入一个AVpacket到队里里面， 个数为：%d", queuePacket.size());
    }
    pthread_cond_signal(&condPacket);

    pthread_mutex_unlock(&mutexPacket);

    return 0;
}

int WlQueue::getAvpacket(AVPacket *packet) {

    pthread_mutex_lock(&mutexPacket);

    while (playStatus != NULL && !playStatus->exit){
        if (queuePacket.size() > 0){
            AVPacket *avPacket = queuePacket.front();
            if (av_packet_ref(packet , avPacket) == 0){
                queuePacket.pop();
            }
            av_packet_free(&avPacket);
            av_free(avPacket);
            avPacket = NULL;
            if(LOG_DEBUG)
            {
                LOGD("从队列里面取出一个AVpacket，还剩下 %d 个", queuePacket.size());
            }
            break;

        } else{
            pthread_cond_wait(&condPacket , &mutexPacket);
        }
    }

    pthread_mutex_unlock(&mutexPacket);

    return 0;
}

int WlQueue::getQueueSize() {

    int size = 0;
    pthread_mutex_lock(&mutexPacket);
    size = queuePacket.size();
    pthread_mutex_unlock(&mutexPacket);

    return size;
}
