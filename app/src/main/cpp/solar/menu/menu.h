#pragma once

#include <jni.h>
#include <vector>

 /**
 *
 *  UI Response Is Based On The Answer To This Question
 *
 *  -> https://stackoverflow.com/questions/55543649/how-to-pass-c-callback-as-a-click-handler-of-a-button-in-android
 *
 *******************************************************/

class Menu {

private:

    JNIEnv *_env{};
    jobject _object{};

public:

    Menu();

    Menu(JNIEnv *env, jobject obj);

    bool isValid();

    void addSpace(int space);

    void addText(const char *text);

    void addSwitch(const char *text, void *toggle);

    void addSeekBar(int min, int max, int* value);

    void addButton(const char *text, void *callback);

    void addSpinner(const char* text, std::vector<const char*> features, int* index, void* methodPointer = nullptr);

    void toast(const char *text);

};
