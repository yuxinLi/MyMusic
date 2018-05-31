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
    public native void mutexThread();

    private OnErrerListener onErrerListener;

    public void setOnErrerListener(OnErrerListener onErrerListener) {
        this.onErrerListener = onErrerListener;
    }

    public void onError(int code, String msg)
    {
        if(onErrerListener != null)
        {
            onErrerListener.onError(code, msg);
        }
    }

    public interface OnErrerListener
    {
        void onError(int code, String msg);
    }

    public native void callbackFromC();
}
