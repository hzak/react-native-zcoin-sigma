
#include "libsigma/secp256k1/include/secp256k1_group.hpp"
#include "CoreJni.h"
#include "com_zcoin_sigma_GroupElement.h"
#include "Utils.h"

extern "C" {

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jCreateGroupElement__
        (JNIEnv *env, jclass thisClass) {
    auto *groupElement = new secp_primitives::GroupElement();
    return (jlong) groupElement;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jRelease
        (JNIEnv *env, jobject thisObject) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    delete groupElement;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jCopyConstructor
        (JNIEnv *env, jclass thisClass, jlong otherId) {
    auto *otherGroupElement = (secp_primitives::GroupElement *) otherId;
    auto *groupElement = new secp_primitives::GroupElement(*otherGroupElement);
    return (jlong) groupElement;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jCreateGroupElement__CCI
        (JNIEnv *env, jclass thisClass, jchar x, jchar y, jint base) {
    auto *groupElement = new secp_primitives::GroupElement(reinterpret_cast<const char *>(&x),
                                                           reinterpret_cast<const char *>(&y),
                                                           base);
    return (jlong) groupElement;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorAssignment
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *otherGroupElement = (secp_primitives::GroupElement *) otherId;
    *groupElement = *otherGroupElement;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorMultiply
        (JNIEnv *env, jobject thisObject, jlong multiplierId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *scalar = (secp_primitives::Scalar *) multiplierId;
    auto result = *groupElement * *scalar;
    return (jlong) &result;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorMultiplyAndAssign
        (JNIEnv *env, jobject thisObject, jlong multiplierId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *scalar = (secp_primitives::Scalar *) multiplierId;
    *groupElement *= *scalar;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorPlus
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *otherGroupElement = (secp_primitives::GroupElement *) otherId;
    auto result = *groupElement + *otherGroupElement;
    return (jlong) &result;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorPlusAndAssign
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *otherGroupElement = (secp_primitives::GroupElement *) otherId;
    *groupElement += *otherGroupElement;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jInverse
        (JNIEnv *env, jobject thisObject) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto result = groupElement->inverse();
    return (jlong) &result;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jSquare
        (JNIEnv *env, jobject thisObject) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    groupElement->square();
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorEqual
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *otherGroupElement = (secp_primitives::GroupElement *) otherId;
    return (jboolean) (*groupElement == *otherGroupElement);
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_GroupElement_jOperatorNotEqual
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    auto *otherGroupElement = (secp_primitives::GroupElement *) otherId;
    return (jboolean) (*groupElement != *otherGroupElement);
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_GroupElement_jGenerate
        (JNIEnv *env, jobject thisObject, jstring seedStr) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    jboolean isCopy = 0;
    const char *seed = env->GetStringUTFChars(seedStr, &isCopy);
    return (jlong) &(groupElement->generate((unsigned char *) seed));
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jSha256
        (JNIEnv *env, jobject thisObject, jstring resultStr) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    jboolean isCopy = 0;
    const char *result = env->GetStringUTFChars(resultStr, &isCopy);
    groupElement->sha256((unsigned char *) result);
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_GroupElement_jRandomize
        (JNIEnv *env, jobject thisObject) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    groupElement->randomize();
}

JNIEXPORT jstring JNICALL Java_com_zcoin_sigma_GroupElement_jGetHex
        (JNIEnv *env, jobject thisObject) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    return env->NewStringUTF(groupElement->GetHex().c_str());
}

JNIEXPORT jbyteArray JNICALL Java_com_zcoin_sigma_GroupElement_jGetvch
        (JNIEnv *env, jobject thisObject) {
    auto *groupElement = (secp_primitives::GroupElement *) getJNIReference(env, thisObject);
    std::vector<unsigned char> charsVector = groupElement->getvch();
    jbyteArray scriptArray = env->NewByteArray(charsVector.size());
    env->SetByteArrayRegion(scriptArray, 0, charsVector.size(), (jbyte*) charsVector.data());
    return scriptArray;
}

}