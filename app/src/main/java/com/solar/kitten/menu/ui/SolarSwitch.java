package com.solar.kitten.menu.ui;

import android.annotation.SuppressLint;
import android.content.Context;
import android.util.AttributeSet;
import android.widget.Switch;

@SuppressLint({"UseSwitchCompatOrMaterialCode", "ViewConstructor"})
public class SolarSwitch extends Switch {

    private final long nativePeer;

    public SolarSwitch(Context context, long pointer) {
        super(context);nativePeer = pointer;
    }

    public SolarSwitch(Context context, AttributeSet attrs, long pointer) {
        super(context, attrs); nativePeer = pointer;
    }

    public SolarSwitch(Context context, AttributeSet attrs, int defStyleAttr, long pointer) {
        super(context, attrs, defStyleAttr); nativePeer = pointer;
    }

    @Override
    public void setChecked(boolean checked) {
        super.setChecked(checked);
        if(nativePeer != 0 && init) {
            ChangeSwitch(nativePeer);
        } else {
            init = true;
        }

    }

    private native void ChangeSwitch(long pointer);
    private boolean init;
}
