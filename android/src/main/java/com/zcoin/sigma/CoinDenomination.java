package com.zcoin.sigma;

import static com.zcoin.sigma.Util.CENT;
import static com.zcoin.sigma.Util.COIN;

public enum CoinDenomination {
    SIGMA_DENOM_0_05(5 * CENT),
    SIGMA_DENOM_0_1(10 * CENT),
    SIGMA_DENOM_0_5(50 * CENT),
    SIGMA_DENOM_1(1 * COIN),
    SIGMA_DENOM_10(10 * COIN),
    SIGMA_DENOM_25(25 * COIN),
    SIGMA_DENOM_100(100 * COIN);

    private long value;

    CoinDenomination(long value) {
        this.value = value;
    }

    public long getValue() {
        return value;
    }

    public static CoinDenomination integerToDenomination(long value) {
        for (CoinDenomination coinDenomination : values()) {
            if (coinDenomination.value == value) {
                return coinDenomination;
            }
        }
        return null;
    }
}
