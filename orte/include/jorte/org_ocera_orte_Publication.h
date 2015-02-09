/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class org_ocera_orte_Publication */

#ifndef _Included_org_ocera_orte_Publication
#define _Included_org_ocera_orte_Publication
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationCreate
 * Signature: (JLjava/lang/String;Ljava/lang/String;ILjava/nio/ByteBuffer;Lorg/ocera/orte/types/NtpTime;I)J
 */
JNIEXPORT jlong JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationCreate
  (JNIEnv *, jobject, jlong, jstring, jstring, jobject, jobject, jint);

/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationDestroy
 * Signature: (J)Z
 */
JNIEXPORT jboolean JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationDestroy
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationSend
 * Signature: (JLorg/ocera/orte/types/MessageData;)Z
 */
JNIEXPORT jboolean JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationSend
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationPropertiesGet
 * Signature: (J)Lorg/ocera/orte/types/PublProp;
 */
JNIEXPORT jobject JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationPropertiesGet
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationPropertiesSet
 * Signature: (JLorg/ocera/orte/types/PublProp;)Z
 */
JNIEXPORT jboolean JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationPropertiesSet
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationGetStatus
 * Signature: (J)Lorg/ocera/orte/types/Status;
 */
JNIEXPORT jobject JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationGetStatus
  (JNIEnv *, jobject, jlong);

/*
 * Class:     org_ocera_orte_Publication
 * Method:    jORTEPublicationWaitForSubscriptions
 * Signature: (JLorg/ocera/orte/types/NtpTime;JJ)I
 */
JNIEXPORT jint JNICALL
Java_org_ocera_orte_Publication_jORTEPublicationWaitForSubscriptions
  (JNIEnv *, jobject, jlong, jobject, jlong, jlong);

#ifdef __cplusplus
}
#endif
#endif /* ifndef _Included_org_ocera_orte_Publication */
