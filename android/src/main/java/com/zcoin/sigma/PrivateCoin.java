package com.zcoin.sigma;

public class PrivateCoin extends RNativeObject {

    protected PrivateCoin(long id) {
        super(id);
    }

    public PrivateCoin(Params params, CoinDenomination coinDenomination) {
        super(jCreatePrivateCoinFromParamsAndDenomination(params.getId(), coinDenomination.getValue()));
    }

    public PrivateCoin(Params params, CoinDenomination coinDenomination, int version) {
        super(jCreatePrivateCoinFromParamsAndDenominationAndValue(params.getId(), coinDenomination.getValue(), version));
    }

    public Params getParams() {
        return new Params(jGetParams());
    }

    public PublicCoin getPublicCoin() {
        return new PublicCoin(jGetPublicCoin());
    }

    public Scalar getSerialNumber() {
        return new Scalar(jGetSerialNumber());
    }

    public Scalar getRandomness() {
        return new Scalar(jGetRandomness());
    }

    public int getVersion() {
        return jGetVersion();
    }

    public void setPublicCoin(PublicCoin publicCoin) {
        jSetPublicCoin(publicCoin.getId());
    }

    public void setRandomness(Scalar scalar) {
        jSetRandomness(scalar.getId());
    }

    public void setSerialNumber(Scalar scalar) {
        jSetSerialNumber(scalar.getId());
    }

    public void setVersion(int version) {
        jSetVersion(version);
    }

    public byte[] getEcdsaSeckey() {
        return jGetEcdsaSeckey();
    }

    public void setEcdsaSeckey(byte[] seckey) {
        jSetEcdsaSeckey(seckey);
    }

    private static native long jCreatePrivateCoinFromParamsAndDenomination(long paramsId, long coinDenomination);

    private static native long jCreatePrivateCoinFromParamsAndDenominationAndValue(long paramsId, long coinDenomination, int value);

    private native long jGetParams();

    private native long jGetPublicCoin();

    private native long jGetSerialNumber();

    private native long jGetRandomness();

    private native int jGetVersion();

    private native void jSetPublicCoin(long publicCoinId);

    private native void jSetRandomness(long scalarId);

    private native void jSetSerialNumber(long scalarId);

    private native void jSetVersion(int version);

    private native byte[] jGetEcdsaSeckey();

    private native void jSetEcdsaSeckey(byte[] seckey);
}
