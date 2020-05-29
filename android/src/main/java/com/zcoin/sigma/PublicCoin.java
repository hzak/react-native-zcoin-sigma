package com.zcoin.sigma;

public class PublicCoin extends RNativeObject {

    protected PublicCoin(long id) {
        super(id);
    }

    public PublicCoin() {
        super(jCreatePublicCoin());
    }

    public PublicCoin(GroupElement groupElement, CoinDenomination coinDenomination) {
        super(jCreatePublicCoinFromGroupElementAndDenomination(groupElement.getId(), coinDenomination.getValue()));
    }

    public GroupElement getValue() {
        return new GroupElement(jGetValue());
    }

    public CoinDenomination getDenomination() {
        return CoinDenomination.integerToDenomination(jGetDenomination());
    }

    public boolean operatorEqual(PublicCoin other) {
        return jOperatorEqual(other.getId());
    }

    public boolean operatorNotEqual(PublicCoin other) {
        return jOperatorNotEqual(other.getId());
    }

    private static native long jCreatePublicCoin();

    private static native long jCreatePublicCoinFromGroupElementAndDenomination(long groupElementId, long coinDenomination);

    public native long jGetValue();

    public native long jGetDenomination();

    public native boolean jOperatorEqual(long otherId);

    public native boolean jOperatorNotEqual(long otherId);
}
