package com.solar.kitten.menu.ui.listener;

import android.view.View;

public class SolarOnClickListener implements View.OnClickListener {

    public final long nativePeer;

    public SolarOnClickListener(final long nativePeer) {
        this.nativePeer = nativePeer;
    }

    @Override
    public void onClick(View v) {
        Callback(nativePeer);
    }

    @Override
    public void finalize() {
        Callback(nativePeer);
    }

    public native void Callback(final long peer);

}
