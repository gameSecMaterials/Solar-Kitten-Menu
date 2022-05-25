#include "main.h"

extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_solar_kitten_menu_Menu_getData(JNIEnv *env, jobject) {

    jobjectArray solarArray;

    const char *data[]= {Solar::Info::m_bSolarMarquee, "Close", "Stop"};

    int totalSize = (sizeof data / sizeof data[0]);

    solarArray = (jobjectArray)env->NewObjectArray(totalSize,env->FindClass("java/lang/String"),env->NewStringUTF(""));

    for(int i = 0; i < totalSize; i++) {

        env->SetObjectArrayElement(solarArray, i, env->NewStringUTF(data[i]));

    }

    return solarArray;
}

extern "C"
JNIEXPORT void JNICALL
Java_com_solar_kitten_menu_Menu_solarModules(JNIEnv *solarEnv, jobject solarObject) {

    auto solar = Menu(solarEnv, solarObject);

    solar.addText("JNI Text");

    solar.addSwitch("JNI Toggle 1", &Solar::Modules::m_bToggle);
    solar.addSwitch("JNI Toggle 2", &Solar::Modules::m_bToggle_);
    solar.addSwitch("JNI Toggle 3", &Solar::Modules::m_bToggle__);

    solar.addText("JNI Slider 1");
    solar.addSeekBar(0, 5, &Solar::Modules::m_bSeekBar);

    solar.addText("JNI Slider 2");
    solar.addSeekBar(0, 15, &Solar::Modules::m_bSeekBar_);

    solar.addButton("Log Values", new std::function<void(void)>([] {

        LOGI("Solar Kitten");

        LOGI("JNI Toggle 1 - %d", Solar::Modules::m_bToggle);
        LOGI("JNI Toggle 2 - %d", Solar::Modules::m_bToggle_);
        LOGI("JNI Toggle 3 - %d", Solar::Modules::m_bToggle__);

        LOGI("JNI Slider 1 - %d", Solar::Modules::m_bSeekBar);
        LOGI("JNI Slider 2 - %d", Solar::Modules::m_bSeekBar_);

        LOGI("---------------------------------------------------");

    }));
    
}
