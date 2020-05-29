package com.zcoin.sigma;

public abstract class RNativeObject {
    protected long id;

    protected RNativeObject(long id) {
        this.id = id;
    }

    public long getId() {
        return this.id;
    }
}
