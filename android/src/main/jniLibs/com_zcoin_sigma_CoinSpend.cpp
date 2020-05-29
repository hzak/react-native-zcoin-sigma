
#include "libsigma/src/coinspend.h"
#include "CoreJni.h"
#include "com_zcoin_sigma_CoinSpend.h"
#include "Utils.h"
#include <android/log.h>

extern "C" {

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_CoinSpend_jCreateCoinSpend
        (JNIEnv *env, jclass thisClass, jlong paramsId, jlong privateCoinId,
         jlongArray anonymitySet, jlong spendMetaDataId) {
    auto *params = (sigma::Params *) paramsId;
    auto *privateCoin = (sigma::PrivateCoin *) privateCoinId;
    auto *spendMetaData = (sigma::SpendMetaData *) spendMetaDataId;

    jsize size = env->GetArrayLength(anonymitySet);
    std::vector<sigma::PublicCoin> anonymity_set(size);
    env->GetLongArrayRegion(anonymitySet, 0, size, (jlong *) &anonymity_set[0]);

    auto *coinSpend = new sigma::CoinSpend(params, *privateCoin, anonymity_set, *spendMetaData, true);

    return (jlong) coinSpend;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_CoinSpend_jUpdateMetaData
        (JNIEnv *env, jobject thisObject, jlong privateCoinId, jlong spendMetaDataId) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    auto *privateCoin = (sigma::PrivateCoin *) privateCoinId;
    auto *spendMetaData = (sigma::SpendMetaData *) spendMetaDataId;
    coinSpend->updateMetaData(*privateCoin, *spendMetaData);
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_CoinSpend_jGetCoinSerialNumber
        (JNIEnv *env, jobject thisObject) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    return (jlong) &(coinSpend->getCoinSerialNumber());
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_CoinSpend_jGetDenomination
        (JNIEnv *env, jobject thisObject) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    int64_t denominationValue;
    sigma::DenominationToInteger(coinSpend->getDenomination(), denominationValue);
    return (jlong) denominationValue;
}

JNIEXPORT void JNICALL Java_com_zcoin_sigma_CoinSpend_jSetVersion
        (JNIEnv *env, jobject thisObject, jint version) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    coinSpend->setVersion(version);
}

JNIEXPORT jint JNICALL Java_com_zcoin_sigma_CoinSpend_jGetVersion
        (JNIEnv *env, jobject thisObject) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    return coinSpend->getVersion();
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_CoinSpend_jHasValidSerial
        (JNIEnv *env, jobject thisObject) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    return (jboolean) coinSpend->HasValidSerial();
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_CoinSpend_jVerify
        (JNIEnv *env, jobject thisObject, jlongArray anonymitySet, jlong spendMetaDataId) {
    auto *coinSpend = (sigma::CoinSpend *) getJNIReference(env, thisObject);
    auto *spendMetaData = (sigma::SpendMetaData *) spendMetaDataId;

    jsize size = env->GetArrayLength(anonymitySet);
    std::vector<sigma::PublicCoin> anonymity_set(size);
    env->GetLongArrayRegion(anonymitySet, 0, size, (jlong *) &anonymity_set[0]);

    return (jboolean) coinSpend->Verify(anonymity_set, *spendMetaData, true);
}
}