
#include "libsigma/src/params.h"
#include "CoreJni.h"
#include "com_zcoin_sigma_Params.h"

extern "C" {

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Params_jGetDefault
        (JNIEnv *env, jclass thisClass) {
    auto params = sigma::Params::get_default();
    return (jlong) params;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Params_jGet_1g
        (JNIEnv *env, jobject thisObject) {
    auto *params = (sigma::Params *) getJNIReference(env, thisObject);
    return (jlong) &(params->get_g());
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Params_jGet_1h0
        (JNIEnv *env, jobject thisObject) {
    auto *params = (sigma::Params *) getJNIReference(env, thisObject);
    return (jlong) &(params->get_h0());
}

JNIEXPORT jlongArray JNICALL Java_com_zcoin_sigma_Params_jGet_1h
        (JNIEnv *env, jobject thisObject) {
    auto *params = (sigma::Params *) getJNIReference(env, thisObject);
    std::vector<GroupElement> groupElements = params->get_h();

    jlongArray result = env->NewLongArray(groupElements.size());
    env->SetLongArrayRegion(result, 0, groupElements.size(), (jlong *) &groupElements[0]);
    return result;
}

}