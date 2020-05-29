
#include "libsigma/src/coin.h"
#include "CoreJni.h"
#include "com_zcoin_sigma_PublicCoin.h"

extern "C" {

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PublicCoin_jCreatePublicCoin
        (JNIEnv *env, jclass thisClass) {
    auto *publicCoin = new sigma::PublicCoin();
    return (jlong) publicCoin;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PublicCoin_jCreatePublicCoinFromGroupElementAndDenomination
        (JNIEnv *env, jclass thisClass, jlong groupElementId, jlong denominationValue) {
    sigma::CoinDenomination coinDenomination;
    sigma::IntegerToDenomination((int64_t) denominationValue, coinDenomination);

    auto *groupElement = (GroupElement *) groupElementId;
    auto *publicCoin = new sigma::PublicCoin(*groupElement, coinDenomination);

    return (jlong) publicCoin;
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PublicCoin_jGetValue
        (JNIEnv *env, jobject thisObject) {
    auto *publicCoin = (sigma::PublicCoin *) getJNIReference(env, thisObject);
    return (jlong) &publicCoin->getValue();
}

JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_PublicCoin_jGetDenomination
        (JNIEnv *env, jobject thisObject) {
    auto *publicCoin = (sigma::PublicCoin *) getJNIReference(env, thisObject);
    int64_t denominationValue;
    sigma::DenominationToInteger(publicCoin->getDenomination(), denominationValue);
    return (jlong) denominationValue;
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_PublicCoin_jOperatorEqual
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *publicCoin = (sigma::PublicCoin *) getJNIReference(env, thisObject);
    auto *otherPublicCoin = (sigma::PublicCoin *) otherId;
    return (jboolean) (*publicCoin == *otherPublicCoin);
}

JNIEXPORT jboolean JNICALL Java_com_zcoin_sigma_PublicCoin_jOperatorNotEqual
        (JNIEnv *env, jobject thisObject, jlong otherId) {
    auto *publicCoin = (sigma::PublicCoin *) getJNIReference(env, thisObject);
    auto *otherPublicCoin = (sigma::PublicCoin *) otherId;
    return (jboolean) (*publicCoin != *otherPublicCoin);
}
}