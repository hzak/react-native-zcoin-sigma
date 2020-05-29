
#include "Utils.h"
#include "CoreJni.h"
#include "com_zcoin_sigma_Sigma.h"

extern "C" {
JNIEXPORT jstring JNICALL Java_com_zcoin_sigma_Sigma_jCreateMintCommitment
        (JNIEnv *env, jclass thisClass, jlong denominationValue,
         jstring jPrivateKey, jint index) {
    sigma::CoinDenomination coinDenomination;
    sigma::IntegerToDenomination((int64_t) denominationValue, coinDenomination);

    const char *privateKey = env->GetStringUTFChars(jPrivateKey, nullptr);

    const char* commitment = CreateMintCommitment(coinDenomination, privateKey, index);

    return env->NewStringUTF(commitment);
}

JNIEXPORT jstring JNICALL Java_com_zcoin_sigma_Sigma_jCreateSpendProof
        (JNIEnv *env, jclass thisClass, jlong denominationValue, jstring jPrivateKey, jint index,
                jobjectArray jAnonymitySet, jint groupId, jstring jBlockHash, jstring jTxHash) {
    sigma::CoinDenomination coinDenomination;
    sigma::IntegerToDenomination((int64_t) denominationValue, coinDenomination);

    const char *privateKey = env->GetStringUTFChars(jPrivateKey, nullptr);

    std::vector<const char *> anonymitySet;
    int anonymitySetSize = env->GetArrayLength(jAnonymitySet);
    for (int i = 0; i < anonymitySetSize; i++) {
        auto string = (jstring) (env->GetObjectArrayElement(jAnonymitySet, i));
        const char *rawString = env->GetStringUTFChars(string, nullptr);
        anonymitySet.push_back(rawString);
    }

    const char *blockHash = env->GetStringUTFChars(jBlockHash, nullptr);
    const char *txHash = env->GetStringUTFChars(jTxHash, nullptr);

    const char *spendProof = CreateSpendProof(coinDenomination, privateKey, index,
                                                anonymitySet, groupId, blockHash, txHash);

    return env->NewStringUTF(spendProof);
}

JNIEXPORT jstring JNICALL Java_com_zcoin_sigma_Sigma_jGetSerialNumber
        (JNIEnv *env, jclass thisClass, jlong denominationValue,
         jstring jPrivateKey, jint index) {
    sigma::CoinDenomination coinDenomination;
    sigma::IntegerToDenomination((int64_t) denominationValue, coinDenomination);

    const char *privateKey = env->GetStringUTFChars(jPrivateKey, nullptr);

    const char *serialNumber = GetSerialNumber(coinDenomination, privateKey, index);

    return env->NewStringUTF(serialNumber);
}

}