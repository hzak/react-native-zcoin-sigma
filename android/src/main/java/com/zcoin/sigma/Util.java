package com.zcoin.sigma;

import java.util.List;

public class Util {

    public static final long CENT = 1000000;
    public static final long COIN = 100000000;

    public static long[] toIdList(List<? extends RNativeObject> list) {
        long[] ids = new long[list.size()];
        for (int i = 0; i < list.size(); i++) {
            ids[i] = list.get(i).getId();
        }
        return ids;
    }
}
