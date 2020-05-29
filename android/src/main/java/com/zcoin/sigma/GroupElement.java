package com.zcoin.sigma;

public class GroupElement extends RNativeObject {
    protected GroupElement(long id) {
        super(id);
    }

    public GroupElement() {
        super(jCreateGroupElement());
    }

    public void release() {
        jRelease();
    }

    public GroupElement(GroupElement other) {
        super(jCopyConstructor(other.getId()));
    }

    public GroupElement(char x, char y, int base) {
        super(jCreateGroupElement(x, y, base));
    }

    public void operatorAssignment(GroupElement other) {
        jOperatorAssignment(other.getId());
    }

    public GroupElement operatorMultiply(GroupElement other) {
        return new GroupElement(jOperatorMultiply(other.getId()));
    }

    public void operatorMultiplyAndAssign(GroupElement other) {
        jOperatorMultiplyAndAssign(other.getId());
    }

    public GroupElement operatorPlus(GroupElement other) {
        return new GroupElement(jOperatorPlus(other.getId()));
    }

    public void operatorPlusAndAssign(GroupElement other) {
        jOperatorPlusAndAssign(other.getId());
    }

    public GroupElement inverse() {
        return new GroupElement(jInverse());
    }

    public void square() {
        jSquare();
    }

    public boolean operatorEqual(GroupElement other) {
        return jOperatorEqual(other.getId());
    }

    public boolean operatorNotEqual(GroupElement other) {
        return jOperatorNotEqual(other.getId());
    }

    public GroupElement generate(String seed) {
        return new GroupElement(jGenerate(seed));
    }

    public void sha256(String result) {
        jSha256(result);
    }

    public void randomize() {
        jRandomize();
    }

    public String getHex() {
        return jGetHex();
    }

    public byte[] getvch() {
        return jGetvch();
    }

    private static native long jCreateGroupElement();

    private native void jRelease();

    private static native long jCopyConstructor(long otherId);

    private static native long jCreateGroupElement(char x, char y, int base);

    private native void jOperatorAssignment(long otherId);

    private native long jOperatorMultiply(long otherId);

    private native void jOperatorMultiplyAndAssign(long otherId);

    private native long jOperatorPlus(long otherId);

    private native void jOperatorPlusAndAssign(long otherId);

    private native long jInverse();

    private native void jSquare();

    private native boolean jOperatorEqual(long otherId);

    private native boolean jOperatorNotEqual(long otherId);

    private native long jGenerate(String seed);

    private native void jSha256(String result);

    private native void jRandomize();

    private native String jGetHex();

    private native byte[] jGetvch();
}
