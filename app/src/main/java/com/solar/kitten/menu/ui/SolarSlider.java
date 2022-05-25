package com.solar.kitten.menu.ui;

import android.annotation.SuppressLint;
import android.content.Context;
import android.widget.SeekBar;

@SuppressLint({"AppCompatCustomView", "ViewConstructor"})
public class SolarSlider extends SeekBar {

    private final long nativePeer;

    public SolarSlider(Context context, long pointer) {
        super(context);

        nativePeer = pointer;

        this.setOnSeekBarChangeListener(new OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                ChangeInt(nativePeer, i);
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }

    private native void ChangeInt(long pointer, int number);
}
