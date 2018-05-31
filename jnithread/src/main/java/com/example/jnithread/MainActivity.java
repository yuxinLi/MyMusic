package com.example.jnithread;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {


    private ThreadDemo threadDemo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        threadDemo = new ThreadDemo();
        setContentView(R.layout.activity_main);

        threadDemo.setOnErrerListener(new ThreadDemo.OnErrerListener() {
            @Override
            public void onError(int code, String msg) {
                Log.d("lyx", "code = " + code + " msg = " + msg);
            }
        });
    }



    public void normal(View view) {
        threadDemo.normalThread();
    }

    public void mutexThread(View view) {
        threadDemo.mutexThread();
    }

    public void calbackThread(View view) {

        threadDemo.callbackFromC();

    }
}
