
#ifndef SIMGA_WRAPPER_COREJNI_H
#define SIMGA_WRAPPER_COREJNI_H

#include <jni.h>

/**
 *
 * @param env
 * @param thisObject
 * @return
 */
extern void *getJNIReference (
        JNIEnv *env,
        jobject thisObject);

#endif //SIMGA_WRAPPER_COREJNI_H
