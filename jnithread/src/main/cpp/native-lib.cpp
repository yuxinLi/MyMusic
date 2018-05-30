#include <jni.h>
#include <string>
#include <android/log.h>



#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"lyx",FORMAT,##__VA_ARGS__);

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_playerlibrary_Demo_stringFromJNI(JNIEnv *env, jobject instance) {



    std::string hello = "hello form jni 33333";

    return env->NewStringUTF(hello.c_str());
}
