#include <jni.h>
#include <iostream>
#include "com_jni_example_TemperatureSampler.h"

JNIEXPORT jfloat JNICALL Java_com_jni_example_TemperatureSampler_getTemperature (JNIEnv * env, jobject thisObject) {
    std::cout << "Returning Simple Temperature..." << std::endl;
    return 27.8;
}

JNIEXPORT jobject JNICALL Java_com_jni_example_TemperatureSampler_getDetailedTemperature (JNIEnv * env, jobject thisObject) {

    // Get the TemperatureData and create an instance of it.
    jclass temperatureDataClass = env->FindClass("com/jni/example/TemperatureData");
    jobject temperatureData = env->AllocObject(temperatureDataClass);

    // We only need TemperatureScale class here, enumeration will be created later.
    jclass temperatureScaleClass = env->FindClass("com/jni/example/TemperatureScale");

    // Get fields of TemperatureData
    jfieldID timestamp = env->GetFieldID(temperatureDataClass, "timestamp", "Ljava/lang/String;");
    jfieldID temperature = env->GetFieldID(temperatureDataClass, "temperature", "F");
    jfieldID scale = env->GetFieldID(temperatureDataClass, "scale", "Lcom/jni/example/TemperatureScale;");

    // Get CELCUIS scale from TemperatureScale enum.
    jfieldID scaleEnumID = env->GetStaticFieldID(temperatureScaleClass, "CELCIUS", "Lcom/jni/example/TemperatureScale;");
    jobject celciusScale = env->GetStaticObjectField(temperatureScaleClass, scaleEnumID);

    // Set TemperatureData fields.
    env->SetObjectField(temperatureData, timestamp, env->NewStringUTF("02-03-2020 17:30:48"));
    env->SetFloatField(temperatureData, temperature, 27.8);
    env->SetObjectField(temperatureData, scale, celciusScale);

    std::cout << "Returning Detailed Temperature..." << std::endl;
    return temperatureData;
}
