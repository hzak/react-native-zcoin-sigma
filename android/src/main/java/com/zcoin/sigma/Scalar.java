package com.zcoin.sigma;

public class Scalar extends RNativeObject {
    public Scalar() {
        super(jCreateScalar());
    }

    public Scalar(long id) {
        super(id);
    }

    public Scalar(Scalar other) {
        super(jCopyConstructor(other.getId()));
    }

    public Scalar(String str) {
        super(jCreateScalar(str));
    }

    public Scalar createScalarFromValue(long value) {
        return new Scalar(jCreateScalar(value));
    }

    public void release() {
        jRelease();
    }

    public void operatorAssignment(Scalar other) {
        jOperatorAssignment(other.getId());
    }

    public void operatorAssignmentInt(int i) {
        jOperatorAssignmentInt(i);
    }

    public void operatorAssignmentString(String bin) {
        jOperatorAssignmentString(bin);
    }

    public Scalar operatorMultiply(Scalar other) {
        return new Scalar(jOperatorMultiply(other.getId()));
    }

    public void operatorMultiplyAndAssign(Scalar other) {
        jOperatorMultiplyAndAssign(other.getId());
    }

    public Scalar operatorPlus(Scalar other) {
        return new Scalar(jOperatorPlus(other.getId()));
    }

    public void operatorPlusAndAssign(Scalar other) {
        jOperatorPlusAndAssign(other.getId());
    }

    public Scalar operatorMinus(Scalar other) {
        return new Scalar(jOperatorMinus(other.getId()));
    }

    public void operatorMinusAndAssign(Scalar other) {
        jOperatorMinusAndAssign(other.getId());
    }

    public boolean operatorEqual(Scalar other) {
        return jOperatorEqual(other.getId());
    }

    public boolean operatorNotEqual(Scalar other) {
        return jOperatorNotEqual(other.getId());
    }

    public Scalar inverse() {
        return new Scalar(jInverse());
    }

    public Scalar negate() {
        return new Scalar(jNegate());
    }

    public Scalar square() {
        return new Scalar(jSquare());
    }

    public Scalar exponent(Scalar exp) {
        return new Scalar(jExponent(exp.getId()));
    }

    public Scalar exponent(long exponent) {
        return new Scalar(jExponentInt64(exponent));
    }

    public Scalar randomize() {
        return new Scalar(jRandomize());
    }

    public Scalar generate(String seed) {
        return new Scalar(jGenerate(seed));
    }

    public Scalar mod_p() {
        return new Scalar(jMod_p());
    }

    public boolean isMember() {
        return jIsMember();
    }

    public String getHex() {
        return jGetHex();
    }

    public void setHex(String str) {
        jSetHex(str);
    }

    public byte[] serialize() {
        return jSerialize();
    }

    private static native long jCreateScalar();

    private static native long jCreateScalar(long value);

    private static native long jCopyConstructor(long otherId);

    private static native long jCreateScalar(String str);

    private native void jRelease();

    private native void jOperatorAssignment(long otherId);

    private native void jOperatorAssignmentInt(int i);

    private native void jOperatorAssignmentString(String bin);

    private native long jOperatorMultiply(long otherId);

    private native void jOperatorMultiplyAndAssign(long otherId);

    private native long jOperatorPlus(long otherId);

    private native void jOperatorPlusAndAssign(long otherId);

    private native long jOperatorMinus(long otherId);

    private native void jOperatorMinusAndAssign(long otherId);

    private native boolean jOperatorEqual(long otherId);

    private native boolean jOperatorNotEqual(long otherId);

    private native long jInverse();

    private native long jNegate();

    private native long jSquare();

    private native long jExponent(long expId);

    private native long jExponentInt64(long exponent);

    private native long jRandomize();

    private native long jGenerate(String seed);

    private native long jMod_p();

    private native boolean jIsMember();

    private native String jGetHex();

    private native void jSetHex(String str);

    private native byte[] jSerialize();
}
