//
// Created by yuxin on 2018-05-31.
//



#include <jni.h>
#include "JavaListener.h"

JavaListener::JavaListener(JavaVM *vm, _JNIEnv *env, jobject obj) {
    jvm = vm;
    jenv = env;
    jobj = obj;

    jclass clz = env->GetObjectClass(jobj);

    if(!clz){
        return ;
    }
    jmid = env->GetMethodID(clz , "onError" ,"(ILjava/lang/String;)V");
    if (!jmid){
        return ;
    }
}

void JavaListener::onError(int type, int code, const char *msg) {

    if(type == 0){
        JNIEnv *env;
        jvm->AttachCurrentThread(&env , 0);
        jstring jmsg = env->NewStringUTF(msg);
        env->CallVoidMethod(jobj , jmid , code , jmsg);
        env->DeleteLocalRef(jmsg);
        jvm->DetachCurrentThread();

    } else if (type == 1){
        jstring jmsg = jenv->NewStringUTF(msg);
        jenv->CallVoidMethod(jobj , jmid , code , jmsg);
        jenv->DeleteLocalRef(jmsg);
    }

}
