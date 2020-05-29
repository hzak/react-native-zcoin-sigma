import { NativeModules } from 'react-native';

const { RNZcoinSigma } = NativeModules;

function sigmaMint(denomination, privateKey, index) {
    return new Promise((resolve, reject) => {
        RNZcoinSigma.getMintCommitment(denomination, privateKey, index, (commitment, serialNumber) => {
            resolve({ commitment, serialNumber })
        })
    })
}

function sigmaSpend(denomination, privateKey, index, anonymitySet, groupId, blockHash, txHash) {
    return new Promise((resolve, reject) => {
        RNZcoinSigma.getSpendProof(denomination, privateKey, index, anonymitySet, groupId, blockHash, txHash, (proof) => {
            resolve(proof)
        })
    })
}

export default RNZcoinSigma