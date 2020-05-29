
#include "libsigma/secp256k1/include/secp256k1_scalar.hpp"
#include "CoreJni.h"
#include "com_zcoin_sigma_Scalar.h"
#include "Utils.h"

extern "C" {
JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jCreateScalar__
        (JNIEnv *env, jclass thisClass) {
    auto *scalar = new secp_primitives::Scalar();
    return (jlong) scalar;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jCreateScalar__J
        (JNIEnv *env, jclass thisClass, jlong value) {
    auto *scalar = new secp_primitives::Scalar((uint64_t) value);
    return (jlong) scalar;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jCopyConstructor
        (JNIEnv *env, jclass thisClass, jlong otherId) {
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    auto *scalar = new secp_primitives::Scalar(*otherScalar);
    return (jlong) scalar;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jCreateScalar__Ljava_lang_String_2
        (JNIEnv *env, jclass thisClass, jstring str) {
    const char *nativeString = env->GetStringUTFChars(str, 0);
    auto *scalar = new secp_primitives::Scalar(
            reinterpret_cast<const unsigned char *>(nativeString));
    return (jlong) scalar;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jRelease
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    delete scalar;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jOperatorAssignment
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    *scalar = *otherScalar;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jOperatorAssignmentInt
        (JNIEnv *env, jobject thisObject, jint i) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    *scalar = (unsigned int) i;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jOperatorAssignmentString
        (JNIEnv *env, jobject thisObject, jstring binStr) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    jboolean isCopy = 0;
    const char *bin = env->GetStringUTFChars(binStr, &isCopy);
    *scalar = (unsigned char *) bin;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jOperatorMultiply
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    auto result = *scalar * *otherScalar;
    return (jlong) &result;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jOperatorMultiplyAndAssign
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    *scalar *= *otherScalar;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jOperatorPlus
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    auto result = *scalar + *otherScalar;
    return (jlong) &result;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jOperatorPlusAndAssign
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    *scalar += *otherScalar;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jOperatorMinus
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    auto result = *scalar - *otherScalar;
    return (jlong) &result;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jOperatorMinusAndAssign
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    *scalar -= *otherScalar;
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_Scalar_jOperatorEqual
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    return (jboolean) (*scalar == *otherScalar);
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_Scalar_jOperatorNotEqual
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    return (jboolean) (*scalar != *otherScalar);
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jInverse
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto result = scalar->inverse();
    return (jlong) &result;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jNegate
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto result = scalar->negate();
    return (jlong) &result;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jSquare
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto result = scalar->square();
    return (jlong) &result;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jExponent
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto *otherScalar = (secp_primitives::Scalar *) otherId;
    auto result = scalar->exponent(*otherScalar);
    return (jlong) &result;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jExponentInt64
        (JNIEnv *env, jobject thisObject, jlong exponent) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto result = scalar->exponent((uint64_t) exponent);
    return (jlong) &result;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jRandomize
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    return (jlong) &(scalar->randomize());
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jGenerate
        (JNIEnv *env, jobject thisObject, jstring buffStr) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    jboolean isCopy = 0;
    const char *buff = env->GetStringUTFChars(buffStr, &isCopy);
    return (jlong) &(scalar->generate((unsigned char *) buff));
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_Scalar_jMod_1p
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    return (jlong) &(scalar->mod_p());
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_Scalar_jIsMember
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    return (jboolean) scalar->isMember();
}

JNIEXPORT jstring JNICALL Java_com_zcoin_sigma_Scalar_jGetHex
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    return env->NewStringUTF(scalar->GetHex().c_str());
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_Scalar_jSetHex
        (JNIEnv *env, jobject thisObject, jstring str) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    jboolean isCopy = 0;
    const char *nativeStr = env->GetStringUTFChars(str, &isCopy);
    scalar->SetHex(nativeStr);
}

JNIEXPORT jbyteArray JNICALL Java_com_zcoin_sigma_Scalar_jSerialize
        (JNIEnv *env, jobject thisObject) {
    auto *scalar = (secp_primitives::Scalar *) getJNIReference(env, thisObject);
    auto* buffer = new unsigned char[32];
    scalar->serialize(buffer);
    jbyteArray serialized = env->NewByteArray(32);
    env->SetByteArrayRegion(serialized, 0, 32, (jbyte*) buffer);
    return serialized;
}

}