package com.example.playerlibrary;

/**
 * 描    述：
 * 作    者：liyx@13322.com
 * 时    间：2018/5/30
 */
public class Demo {


    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");

        System.loadLibrary("avcodec");
        System.loadLibrary("avdevice");
        System.loadLibrary("avfilter");
        System.loadLibrary("avformat");
        System.loadLibrary("avutil");
        System.loadLibrary("swresample");
        System.loadLibrary("swscale");

    }


    public native String stringFromJNI();
}
