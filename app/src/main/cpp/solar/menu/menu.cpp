#include "menu.h"

/**
 *
 *  UI Response Is Based On The Answer To This Question
 *
 *  -> https://stackoverflow.com/questions/55543649/how-to-pass-c-callback-as-a-click-handler-of-a-button-in-android
 *
 *******************************************************/

Menu::Menu() = default;

bool Menu::initSolar(JNIEnv *env, jobject obj) {

    if(env != nullptr && obj != nullptr) {

        if(!checkExc(env)) {

            solarEnv    = env;
            solarObject = obj;

        }

        return true;

    }

    return false;

}

bool Menu::checkExc(JNIEnv *env) {

    if(env->ExceptionCheck()) {

        env->ExceptionDescribe();
        env->ExceptionClear();

        return true;

    }

    return false;

}

void Menu::addSpace(int space) {

    jclass solarClass     = solarEnv->GetObjectClass(solarObject);
    jmethodID solarMethod = solarEnv->GetMethodID(solarClass, "addSpace", "(I)V");

    solarEnv->CallVoidMethod(solarObject, solarMethod, space);

    solarEnv->DeleteLocalRef(solarClass);

}

void Menu::addText(const char *text) {

    jstring solarText     = solarEnv->NewStringUTF(text);

    jclass solarClass     = solarEnv->GetObjectClass(solarObject);
    jmethodID solarMethod = solarEnv->GetMethodID(solarClass, "addText", "(Ljava/lang/String;)V");

    solarEnv->CallVoidMethod(solarObject, solarMethod, solarText);

    solarEnv->DeleteLocalRef(solarText);
    solarEnv->DeleteLocalRef(solarClass);

}

void Menu::addSwitch(const char *text, void *toggle) {

    jstring solarText     = solarEnv->NewStringUTF(text);

    jclass solarClass     = solarEnv->GetObjectClass(solarObject);
    jmethodID solarMethod = solarEnv->GetMethodID(solarClass, "addSwitch", "(Ljava/lang/String;J)V");

    solarEnv->CallVoidMethod(solarObject, solarMethod, solarText, (jlong) toggle);

    solarEnv->DeleteLocalRef(solarText);
    solarEnv->DeleteLocalRef(solarClass);

}

void Menu::addSeekBar(int min, int max, int *value) {

    jclass solarClass     = solarEnv->GetObjectClass(solarObject);
    jmethodID solarMethod = solarEnv->GetMethodID(solarClass, "addSeekbar", "(IIJ)V");

    solarEnv->CallVoidMethod(solarObject, solarMethod, min, max, (jlong) value);

    solarEnv->DeleteLocalRef(solarClass);

}

void Menu::addButton(const char *text, void *callback) {

    jstring solarText     = solarEnv->NewStringUTF(text);

    jclass solarClass     = solarEnv->GetObjectClass(solarObject);
    jmethodID solarMethod = solarEnv->GetMethodID(solarClass, "addButton", "(Ljava/lang/String;J)V");

    solarEnv->CallVoidMethod(solarObject, solarMethod, solarText, (jlong) callback);

    solarEnv->DeleteLocalRef(solarText);
    solarEnv->DeleteLocalRef(solarClass);

}

void Menu::addSpinner(const char *text, std::vector<const char *> features, int *index, void *methodPointer) {

    //TODO: JNI Spinner Implementation

}

void Menu::toast(const char *text) {

    //TODO: JNI Toast Implementation

}

extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_SolarSwitch_ChangeSwitch(JNIEnv *solarEnv, jobject solarObject, jlong pointer) {

    long solarPointer = (long) pointer;
    bool* solarBool = (bool *) solarPointer;
    *solarBool = !*solarBool;

}

extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_SolarSlider_ChangeInt(JNIEnv *solarEnv, jobject solarObject, jlong pointer, jint number) {

    long solarPointer = (long) pointer;
    int* solarInteger = (int *) solarPointer;
    *solarInteger = number;

}
extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_listener_SolarOnClickListener_OnClick(JNIEnv *solarEnv, jobject solarObject, jlong peer) {

    auto solarFunction = (std::function<void(void)>*) peer;
    (*solarFunction)();

}
extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_ui_listener_SolarOnClickListener_Release(JNIEnv *solarEnv, jobject solarObject, jlong peer) {

    auto solarFunction = (std::function<void(void)>*) peer;
    (*solarFunction)();

}