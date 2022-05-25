#include "menu.h"

/**
 *
 *  UI Response Is Based On The Answer To This Question
 *
 *  -> https://stackoverflow.com/questions/55543649/how-to-pass-c-callback-as-a-click-handler-of-a-button-in-android
 *
 *******************************************************/

Menu::Menu() {

    this->_env = nullptr;
    this->_object = nullptr;

}

Menu::Menu(JNIEnv *env, jobject obj) {

    this->_env = env;
    this->_object = obj;

}

bool Menu::isValid() {

    return (_env != nullptr && _object != nullptr);

}

void Menu::addSpace(int space) {

    if(isValid()) {

        jclass solarClass     = _env->GetObjectClass(_object);
        jmethodID solarMethod = _env->GetMethodID(solarClass, "addSpace", "(I)V");

        _env->CallVoidMethod(_object, solarMethod, space);

        _env->DeleteLocalRef(solarClass);

    }

}

void Menu::addText(const char *text) {

    if(isValid()) {

        jstring solarText     = _env->NewStringUTF(text);

        jclass solarClass     = _env->GetObjectClass(_object);
        jmethodID solarMethod = _env->GetMethodID(solarClass, "addText", "(Ljava/lang/String;)V");

        _env->CallVoidMethod(_object, solarMethod, solarText);

        _env->DeleteLocalRef(solarText);
        _env->DeleteLocalRef(solarClass);

    }

}

void Menu::addSwitch(const char *text, void *toggle) {

    if(isValid()) {

        jstring solarText     = _env->NewStringUTF(text);

        jclass solarClass     = _env->GetObjectClass(_object);
        jmethodID solarMethod = _env->GetMethodID(solarClass, "addSwitch", "(Ljava/lang/String;J)V");

        _env->CallVoidMethod(_object, solarMethod, solarText, (jlong) toggle);

        _env->DeleteLocalRef(solarText);
        _env->DeleteLocalRef(solarClass);

    }

}

void Menu::addSeekBar(int min, int max, int *value) {

    if(isValid()) {

        jclass solarClass     = _env->GetObjectClass(_object);
        jmethodID solarMethod = _env->GetMethodID(solarClass, "addSeekbar", "(IIJ)V");

        _env->CallVoidMethod(_object, solarMethod, min, max, (jlong) value);

        _env->DeleteLocalRef(solarClass);

    }

}

void Menu::addButton(const char *text, void *callback) {

    if(isValid()) {

        jstring solarText     = _env->NewStringUTF(text);

        jclass solarClass     = _env->GetObjectClass(_object);
        jmethodID solarMethod = _env->GetMethodID(solarClass, "addButton", "(Ljava/lang/String;J)V");

        _env->CallVoidMethod(_object, solarMethod, solarText, (jlong) callback);

        _env->DeleteLocalRef(solarText);
        _env->DeleteLocalRef(solarClass);

    }

}

void Menu::addSpinner(const char *text, std::vector<const char *> features, int *index, void *methodPointer) {

    //TODO: JNI Spinner Implementation

}

void Menu::toast(const char *text) {

    //TODO: JNI Toast Implementation

}

extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_SolarSwitch_ChangeBool(JNIEnv *_env, jobject _object, jlong pointer) {

    long solarPointer = (long) pointer;
    bool* solarBool = (bool *) solarPointer;
    *solarBool = !*solarBool;

}

extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_SolarSlider_ChangeInt(JNIEnv *_env, jobject _object, jlong pointer, jint number) {

    long solarPointer = (long) pointer;
    int* solarInteger = (int *) solarPointer;
    *solarInteger = number;

}

extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_listener_SolarOnClickListener_Callback(JNIEnv *_env, jobject _object, jlong peer) {

    auto solarFunction = (std::function<void(void)>*) peer;
    (*solarFunction)();

}