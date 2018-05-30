package com.example.jnithread;

/**
 * 描    述：
 * 作    者：liyx@13322.com
 * 时    间：2018/5/30
 */
public class ThreadDemo {

    static {
        System.loadLibrary("native-lib");
    }


    public native void normalThread();

}
