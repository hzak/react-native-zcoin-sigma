package com.zcoin.sigma;

public class Sigma {

    public static String createMintCommitment(CoinDenomination denomination, String privateKey, int index) {
        return jCreateMintCommitment(denomination.getValue(), privateKey, index);
    }

    public static String createSpendProof(CoinDenomination denomination, String privateKey, int index,
                                          String[] anonymitySet, int groupId,
                                          String blockHash, String txHash) {
        return jCreateSpendProof(denomination.getValue(), privateKey, index,
                anonymitySet, groupId, blockHash, txHash);
    }

    public static String getSerialNumber(CoinDenomination denomination, String privateKey, int index) {
        return jGetSerialNumber(denomination.getValue(), privateKey, index);
    }

    private static native String jCreateMintCommitment(long coinDenomination, String privateKey, int index);

    private static native String jCreateSpendProof(long coinDenomination, String privateKey, int index,
                                                   String[] anonymitySet, int groupId, String blockHash, String txHash);

    private static native String jGetSerialNumber(long coinDenomination, String privateKey, int index);
}
