package com.zcoin.sigma;

import java.util.List;

public class CoinSpend extends RNativeObject {
    protected CoinSpend(long id) {
        super(id);
    }

    public CoinSpend(Params params, PrivateCoin privateCoin, List<PublicCoin> anonymitySet, SpendMetaData spendMetaData) {
        super(jCreateCoinSpend(params.getId(), privateCoin.getId(), Util.toIdList(anonymitySet), spendMetaData.getId()));
    }

    public void updateMetaData(PrivateCoin privateCoin, SpendMetaData spendMetaData) {
        jUpdateMetaData(privateCoin.getId(), spendMetaData.getId());
    }

    public Scalar getCoinSerialNumber() {
        return new Scalar(jGetCoinSerialNumber());
    }

    public CoinDenomination getDenomination() {
        return CoinDenomination.integerToDenomination(jGetDenomination());
    }

    public void setVersion(int version) {
        jSetVersion(version);
    }

    public int getVersion() {
        return jGetVersion();
    }

    public boolean hasValidSerial() {
        return jHasValidSerial();
    }

    public boolean verify(List<PublicCoin> anonymitySet, SpendMetaData spendMetaData) {
        return jVerify(Util.toIdList(anonymitySet), spendMetaData.getId());
    }

    private static native long jCreateCoinSpend(long paramsIs, long privateCoinId,
                                                long[] anonymitySet,
                                                long spendMetaDataId);

    private native void jUpdateMetaData(long privateCoinId, long spendMetaDataId);

    private native long jGetCoinSerialNumber();

    private native long jGetDenomination();

    private native void jSetVersion(int version);

    private native int jGetVersion();

    private native boolean jHasValidSerial();

    private native boolean jVerify(long[] anonymitySet, long spendMetaDataId);
}
