package com.zcoin.sigma;

import java.util.ArrayList;
import java.util.List;

public class Params extends RNativeObject {
    protected Params(long id) {
        super(id);
    }

    public Params() {
        super(jGetDefault());
    }

    public GroupElement getG() {
        return new GroupElement(jGet_g());
    }

    public GroupElement getH0() {
        return new GroupElement(jGet_h0());
    }

    public List<GroupElement> getH() {
        long[] ids = jGet_h();
        List<GroupElement> result = new ArrayList<>();
        for (long id : ids) {
            result.add(new GroupElement(id));
        }
        return result;
    }

    private static native long jGetDefault();

    private native long jGet_g();

    private native long jGet_h0();

    private native long[] jGet_h();
}
