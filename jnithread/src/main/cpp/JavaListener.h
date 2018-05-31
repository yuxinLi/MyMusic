//
// Created by yuxin on 2018-05-31.
//

#include <jni.h>

#ifndef MYMUSIC_JAVALISTENER_H
#define MYMUSIC_JAVALISTENER_H


class JavaListener{

public:
    JavaVM *jvm;
    _JNIEnv *jenv;
    jobject jobj;
    jmethodID jmid;

public:
    JavaListener(JavaVM *vm , _JNIEnv *env ,  jobject obj);
    ~JavaListener();

    /**
     * 1:主线程
     * 0：子线程
     * @param type
     * @param code
     * @param msg
     */
    void onError(int type, int code, const char *msg);

};



#endif //MYMUSIC_JAVALISTENER_H


