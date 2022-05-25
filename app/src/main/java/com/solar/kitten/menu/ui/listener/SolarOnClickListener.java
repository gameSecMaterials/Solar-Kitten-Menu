package com.solar.kitten.menu.ui.listener;

import android.view.View;

public class SolarOnClickListener implements View.OnClickListener {
    public final long nativePeer;

    public SolarOnClickListener(final long nativePeer) {
        this.nativePeer = nativePeer;
    }

    @Override
    public void onClick(View v) {
        OnClick(nativePeer);
    }

    @Override
    public void finalize() {
        Release(nativePeer);
    }

    public native void OnClick(final long peer);

    public native void Release(final long peer);

}
