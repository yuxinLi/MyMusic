//
// Created by yuxin on 2018-05-31.
//

#ifndef MYMUSIC_ANDROIDLOG_H
#define MYMUSIC_ANDROIDLOG_H

#endif //MYMUSIC_ANDROIDLOG_H

#include <android/log.h>
#define LOGD(FORMAT , ...) __android_log_print(ANDROID_LOG_DEBUG , "lyx" , FORMAT , ##__VA_ARGS__);
