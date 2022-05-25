package com.solar.kitten.menu;

import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.graphics.PixelFormat;
import android.graphics.PorterDuff;
import android.view.Gravity;
import android.view.LayoutInflater;
import android.view.MotionEvent;
import android.view.View;
import android.view.WindowManager;
import android.webkit.WebView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

import com.solar.kitten.menu.ui.SolarSlider;
import com.solar.kitten.menu.ui.SolarSwitch;
import com.solar.kitten.menu.ui.listener.SolarOnClickListener;

public class Menu {

    private final Context solarContext;
    private final Activity solarActivity;

    private WindowManager windowManager;
    private View floatingView;
    private LinearLayout patches;

    WindowManager.LayoutParams windowManager_params;

    public Menu(Object instance) {

        this.solarContext  = (Context) instance;
        this.solarActivity = (Activity) instance;

    }

    public void show() {

        String[] solarData                   = getData();

        floatingView                         = LayoutInflater.from(solarContext).inflate(getResID("activity_floating", "layout"), null);

        View floater                         = floatingView.findViewById(getID("floater_container"));
        View menu                            = floatingView.findViewById(getID("menu_container"));
        patches                              = floatingView.findViewById(getID("patches"));
        WebView webView                      = floatingView.findViewById(getID("webv"));
        TextView mClose                      = floatingView.findViewById(getID("mclose"));
        TextView mStop                       = floatingView.findViewById(getID("mstop"));

        windowManager                        = solarActivity.getWindowManager();

        windowManager_params                 = new WindowManager.LayoutParams(WindowManager.LayoutParams.WRAP_CONTENT, WindowManager.LayoutParams.WRAP_CONTENT, 0, 0, WindowManager.LayoutParams.TYPE_APPLICATION, WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE, PixelFormat.TRANSLUCENT);
        windowManager_params.gravity         = Gravity.START | Gravity.TOP;

        windowManager.addView(floatingView, windowManager_params);

        webView.setBackgroundColor(Color.BLACK);
        webView.setVerticalScrollBarEnabled(false);
        webView.loadData("<html><head><style>body{color: white;font-weight:bold;font-family:Courier, monospace;}</style></head><body><marquee class=\"GeneratedMarquee\" direction=\"left\" scrollamount=\"4\" behavior=\"scroll\">" + solarData[0] + "</marquee></body></html>", "text/html", "utf-8");

        mClose.setText(solarData[1]);
        mClose.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                floater.setVisibility(View.VISIBLE);
                menu.setVisibility(View.GONE);

            }

        });

        mStop.setText(solarData[2]);
        mStop.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                windowManager.removeView(floatingView);

            }

        });

        floatingView.setOnTouchListener(new View.OnTouchListener() {

            private int initialX;
            private int initialY;

            private float initialTouchX;
            private float initialTouchY;

            @Override
            public boolean onTouch(View v, MotionEvent event) {

                switch (event.getAction()) {

                    case MotionEvent.ACTION_DOWN:

                        initialX = windowManager_params.x;
                        initialY = windowManager_params.y;

                        initialTouchX = event.getRawX();
                        initialTouchY = event.getRawY();

                        return true;

                    case MotionEvent.ACTION_UP:

                        v.performClick();

                        int differenceX = (int) Math.abs(initialTouchX - event.getRawX());
                        int differenceY = (int) Math.abs(initialTouchY - event.getRawY());

                        if (differenceX < 10 && differenceY < 10 && floater.getVisibility() == View.VISIBLE) {

                            floater.setVisibility(View.GONE);
                            menu.setVisibility(View.VISIBLE);

                        }

                        return true;

                    case MotionEvent.ACTION_MOVE:

                        windowManager_params.x = initialX + (int) (event.getRawX() - initialTouchX);
                        windowManager_params.y = initialY + (int) (event.getRawY() - initialTouchY);

                        windowManager.updateViewLayout(floatingView, windowManager_params);

                        return true;

                }

                return false;

            }
        });

        solarModules();

    }
    
    private void addSpace(int space) {
        View separator = new View(solarContext);
        LinearLayout.LayoutParams params = setParams();
        params.height = space;
        separator.setLayoutParams(params);
        separator.setBackgroundColor(Color.TRANSPARENT);
        patches.addView(separator);
    }

    private void addSwitch(String name, long pointer) {

        addSpace(5);

        SolarSwitch solarSwitch = new SolarSwitch(solarContext, pointer);
        solarSwitch.setText(name);
        solarSwitch.setTextColor(Color.BLACK);
        solarSwitch.getThumbDrawable().setColorFilter(Color.WHITE, PorterDuff.Mode.MULTIPLY);
        solarSwitch.setLayoutParams(setParams());
        solarSwitch.setPadding(5,0,5,0);
        solarSwitch.setOnClickListener(new View.OnClickListener() {

            @Override
            public void onClick(View view) {

                if (solarSwitch.isChecked()) {

                    solarSwitch.getThumbDrawable().setColorFilter(Color.BLACK, PorterDuff.Mode.MULTIPLY);

                } else {

                    solarSwitch.getThumbDrawable().setColorFilter(Color.WHITE, PorterDuff.Mode.MULTIPLY);

                }
            }
        });

        patches.addView(solarSwitch);

    }

    private void addSeekbar(int min, int max, long pointer) {

        addSpace(5);

        SolarSlider solarSlider = new SolarSlider(solarContext, pointer);
        solarSlider.setMax(max);
        solarSlider.setLayoutParams(setParams());

        patches.addView(solarSlider);
    }

    private void addText(String text) {

        addSpace(5);

        TextView solarText = new TextView(solarContext);
        solarText.setText(text);
        solarText.setTextColor(Color.BLACK);
        solarText.setLayoutParams(setParams());
        solarText.setPadding(5,0,5,0);

        patches.addView(solarText);
    }

    private void addButton(String text, long pointer) {

        addSpace(5);

        Button solarButton = new Button(solarContext);
        solarButton.setText(text);
        solarButton.setBackgroundColor(Color.BLACK);
        solarButton.setTextColor(Color.WHITE);
        solarButton.setLayoutParams(setParams());
        solarButton.setAllCaps(false);
        solarButton.setOnClickListener(new SolarOnClickListener(pointer));
        solarButton.setPadding(5,0,5,0);

        patches.addView(solarButton);
    }

    private LinearLayout.LayoutParams setParams() {
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(LinearLayout.LayoutParams.MATCH_PARENT, LinearLayout.LayoutParams.MATCH_PARENT);
        params.gravity = Gravity.CENTER_VERTICAL;
        return params;
    }

    private native void solarModules();

    private native String[] getData();

    private int getResID(String name, String type) {
        return solarContext.getResources().getIdentifier(name, type, solarContext.getPackageName());
    }

    private int getID(String name) {
        return getResID(name, "id");
    }

}