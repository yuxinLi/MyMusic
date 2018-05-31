package com.example.jnithread;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;

public class MainActivity extends AppCompatActivity {


    private ThreadDemo threadDemo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        threadDemo = new ThreadDemo();
        setContentView(R.layout.activity_main);
    }



    public void normal(View view) {
        threadDemo.normalThread();
    }
}
