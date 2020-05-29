package com.zcoin.sigma;

public class SigmaPrimitives {

    public static GroupElement commit(GroupElement g, Scalar m, GroupElement h, Scalar r) {
        return new GroupElement(jCommit(g.getId(), m.getId(), h.getId(), r.getId()));
    }

    private static native long jCommit(long gId, long mId, long hId, long rId);
}
