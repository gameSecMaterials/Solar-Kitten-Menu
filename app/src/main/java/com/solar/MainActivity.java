package com.solar;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.solar.kitten.Solar;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_main);

        Solar.initialize(this);

    }
}