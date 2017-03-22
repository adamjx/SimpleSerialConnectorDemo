/* jSSC (Java Simple Serial Connector) - serial port communication library.
 * © Alexey Sokolov (scream3r), 2010-2014.
 *
 * This file is part of jSSC.
 *
 * jSSC is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * jSSC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with jSSC.  If not, see <http://www.gnu.org/licenses/>.
 *
 * If you use jSSC in public project you can inform me about this by e-mail,
 * of course if you want it.
 *
 * e-mail: scream3r.org@gmail.com
 * web-site: http://scream3r.org | http://code.google.com/p/java-simple-serial-connector/
 */
/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jssc_SerialNativeInterface */

#ifndef _Included_jssc_SerialNativeInterface
#define _Included_jssc_SerialNativeInterface
#ifdef __cplusplus
extern "C" {
#endif

#undef jSSC_NATIVE_LIB_VERSION
#define jSSC_NATIVE_LIB_VERSION "2.8"

#undef jssc_SerialNativeInterface_OS_LINUX
#define jssc_SerialNativeInterface_OS_LINUX 0L
#undef jssc_SerialNativeInterface_OS_WINDOWS
#define jssc_SerialNativeInterface_OS_WINDOWS 1L
#undef jssc_SerialNativeInterface_OS_SOLARIS
#define jssc_SerialNativeInterface_OS_SOLARIS 2L
#undef jssc_SerialNativeInterface_OS_MAC_OS_X
#define jssc_SerialNativeInterface_OS_MAC_OS_X 3L
#undef jssc_SerialNativeInterface_ERR_PORT_BUSY
#define jssc_SerialNativeInterface_ERR_PORT_BUSY -1LL
#undef jssc_SerialNativeInterface_ERR_PORT_NOT_FOUND
#define jssc_SerialNativeInterface_ERR_PORT_NOT_FOUND -2LL
#undef jssc_SerialNativeInterface_ERR_PERMISSION_DENIED
#define jssc_SerialNativeInterface_ERR_PERMISSION_DENIED -3LL
#undef jssc_SerialNativeInterface_ERR_INCORRECT_SERIAL_PORT
#define jssc_SerialNativeInterface_ERR_INCORRECT_SERIAL_PORT -4LL
/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getNativeLibraryVersion
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_getNativeLibraryVersion
  (JNIEnv *, jobject);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    openPort
 * Signature: (Ljava/lang/String;Z)J
 */
JNIEXPORT jlong JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_openPort
  (JNIEnv *, jobject, jstring, jboolean);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setParams
 * Signature: (JIIIIZZI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_setParams
  (JNIEnv *, jobject, jlong, jint, jint, jint, jint, jboolean, jboolean, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    purgePort
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_purgePort
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    closePort
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_closePort
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setEventsMask
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_setEventsMask
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getEventsMask
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_getEventsMask
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    waitEvents
 * Signature: (J)[[I
 */
JNIEXPORT jobjectArray JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_waitEvents
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setRTS
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_setRTS
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setDTR
 * Signature: (JZ)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_setDTR
  (JNIEnv *, jobject, jlong, jboolean);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    readBytes
 * Signature: (JI)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_readBytes
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    writeBytes
 * Signature: (J[B)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_writeBytes
  (JNIEnv *, jobject, jlong, jbyteArray);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getBuffersBytesCount
 * Signature: (J)[I
 */
JNIEXPORT jintArray JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_getBuffersBytesCount
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    setFlowControlMode
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_setFlowControlMode
  (JNIEnv *, jobject, jlong, jint);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getFlowControlMode
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_getFlowControlMode
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getSerialPortNames
 * Signature: ()[Ljava/lang/String;
 */
JNIEXPORT jobjectArray JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_getSerialPortNames
  (JNIEnv *, jobject);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    getLinesStatus
 * Signature: (J)[I
 */
JNIEXPORT jintArray JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_getLinesStatus
  (JNIEnv *, jobject, jlong);

/*
 * Class:     jssc_SerialNativeInterface
 * Method:    sendBreak
 * Signature: (JI)Z
 */
JNIEXPORT jboolean JNICALL Java_com_example_gourdboy_serialportdemo_jssc_SerialNativeInterface_sendBreak
  (JNIEnv *, jobject, jlong, jint);

#ifdef __cplusplus
}
#endif
#endif
