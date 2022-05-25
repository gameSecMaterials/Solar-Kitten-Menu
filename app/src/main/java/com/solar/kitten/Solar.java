package com.solar.kitten;

import android.app.Activity;

import com.solar.kitten.menu.Menu;

public class Solar {

    static {
        System.loadLibrary("solar");
    }

    public static void initialize(Object instance) {

        if (instance instanceof Activity) {

            new Menu(instance).show();

        }
    }
}
