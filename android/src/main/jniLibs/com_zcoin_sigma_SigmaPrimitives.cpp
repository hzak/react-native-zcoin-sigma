#include "libsigma/src/sigma_primitives.h"
#include "libsigma/secp256k1/include/secp256k1_group.hpp"
#include "libsigma/secp256k1/include/secp256k1_scalar.hpp"
#include "CoreJni.h"
#include "com_zcoin_sigma_SigmaPrimitives.h"

extern "C" {
JNIEXPORT jlong JNICALL Java_com_zcoin_sigma_SigmaPrimitives_jCommit
        (JNIEnv *env, jclass thisClass, jlong gId, jlong mId, jlong hId, jlong rId) {
    auto *g = (secp_primitives::GroupElement *) gId;
    auto *m = (secp_primitives::Scalar *) mId;
    auto *h = (secp_primitives::GroupElement *) hId;
    auto *r = (secp_primitives::Scalar *) rId;
    auto commit = sigma::SigmaPrimitives<secp_primitives::Scalar, secp_primitives::GroupElement>::commit(*g, *m, *h, *r);
    return (jlong) &commit;
}
}
