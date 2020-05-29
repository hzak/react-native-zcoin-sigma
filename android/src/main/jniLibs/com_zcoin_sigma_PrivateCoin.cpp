
#include "libsigma/src/coin.h"
#include "CoreJni.h"
#include "com_zcoin_sigma_PrivateCoin.h"
#include "Utils.h"

extern "C" {

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PrivateCoin_jCreatePrivateCoinFromParamsAndDenomination
        (JNIEnv *env, jclass thisClass, jlong paramsId, jlong denominationValue) {
    sigma::CoinDenomination coinDenomination;
    sigma::IntegerToDenomination((int64_t) denominationValue, coinDenomination);

    auto *params = (sigma::Params *) paramsId;
    auto *privateCoin = new sigma::PrivateCoin(params, coinDenomination, ZEROCOIN_TX_VERSION_3);

    return (jlong) privateCoin;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PrivateCoin_jCreatePrivateCoinFromParamsAndDenominationAndValue
        (JNIEnv *env, jclass thisClass, jlong paramsId, jlong denominationValue, jint value) {
    sigma::CoinDenomination coinDenomination;
    sigma::IntegerToDenomination((int64_t) denominationValue, coinDenomination);

    auto *params = (sigma::Params *) paramsId;
    auto *privateCoin = new sigma::PrivateCoin(params, coinDenomination, value);

    return (jlong) privateCoin;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PrivateCoin_jGetParams
        (JNIEnv *env, jobject thisObject) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    return (jlong) privateCoin->getParams();
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PrivateCoin_jGetPublicCoin
        (JNIEnv *env, jobject thisObject) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    return (jlong) &(privateCoin->getPublicCoin());
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PrivateCoin_jGetSerialNumber
        (JNIEnv *env, jobject thisObject) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    return (jlong) &(privateCoin->getSerialNumber());
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PrivateCoin_jGetRandomness
        (JNIEnv *env, jobject thisObject) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    return (jlong) &(privateCoin->getRandomness());
}

JNIEXPORT jint JNICALL Java_com_zcoin_sigma_PrivateCoin_jGetVersion
        (JNIEnv *env, jobject thisObject) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    return privateCoin->getVersion();
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_PrivateCoin_jSetPublicCoin
        (JNIEnv *env, jobject thisObject, jlong publicCoinId) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    auto *publicCoin = (sigma::PublicCoin *) publicCoinId;
    privateCoin->setPublicCoin(*publicCoin);
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_PrivateCoin_jSetRandomness
        (JNIEnv *env, jobject thisObject, jlong scalarId) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    auto *scalar = (Scalar *) scalarId;
    privateCoin->setRandomness(*scalar);
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_PrivateCoin_jSetSerialNumber
        (JNIEnv *env, jobject thisObject, jlong scalarId) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    auto *scalar = (Scalar *) scalarId;
    privateCoin->setSerialNumber(*scalar);
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_PrivateCoin_jSetVersion
        (JNIEnv *env, jobject thisObject, jint version) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    privateCoin->setVersion(version);
}

JNIEXPORT jbyteArray JNICALL Java_com_zcoin_sigma_PrivateCoin_jGetEcdsaSeckey
        (JNIEnv *env, jobject thisObject) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    jbyteArray ecdsaSeckey = env->NewByteArray(32);
    env->SetByteArrayRegion(ecdsaSeckey, 0, 32, (jbyte*) privateCoin->getEcdsaSeckey());
    return ecdsaSeckey;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_PrivateCoin_jSetEcdsaSeckey
        (JNIEnv *env, jobject thisObject, jbyteArray seckey) {
    auto *privateCoin = (sigma::PrivateCoin *) getJNIReference(env, thisObject);
    int size = env->GetArrayLength(seckey);
    auto* buf = new unsigned char[size];
    env->GetByteArrayRegion(seckey, 0, size, reinterpret_cast<jbyte*>(buf));
    std::vector<unsigned char> charArray = std::vector<unsigned char>();
    for (int i = 0; i < size; i++) {
        charArray.push_back(buf[i]);
    }
    privateCoin->setEcdsaSeckey(charArray);
}
}