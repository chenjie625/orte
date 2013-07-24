/* JORTETypeRegisterAdd.c */

/**
  * This code provides conversion between JAVA a C environments.
  * The C functions are calling here and results are send to JAVA
  * native functions. It uses the header pregenerated by JAVA
  * (by command 'javah -jni class_with_native_function')
  *
  * @author Lukas Pokorny (lukas_pokorny@centrum.cz)
  * @author CTU FEE Prague - Department of Control Engineering (dce.felk.cvut.cz)
  * @author Project ORTE - OCERA Real Time Ethernet (www.ocera.org)
  * @author dedication to Kj
  * @version 0.1
  *
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation; either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  * GNU General Public License for more details.
  *
  */

#include <jni.h>
#include <string.h>
// library header file's path
#include "orte.h"
// pregenerated header
#include "jorte/org_ocera_orte_DomainApp.h"
#include "jorte/jorte_protos_api.h"
#include "jorte/4all.h"

extern JavaVM *javavm;
static jobject byte_buf;

void deserialize(CDR_Codec *cdrCodec, void *instance) {
  JNIEnv        *env = 0;
  jclass         cls = 0;
  jfieldID       fid = 0;
  jmethodID      mid = 0;
  jobject        obj_bo = 0;

  //set byte order only once
  if(byte_buf) {
    // get environment
    (*javavm)->AttachCurrentThread(javavm, (void **)&env, NULL);
    if(env == 0)
    {
      #ifdef TEST_STAGE
       printf(":!c: env = NULL \n");
      #endif
    }

    //prepare ByteOrder
    cls = (*env)->FindClass(env, "java/nio/ByteOrder");
    if (cls == 0) {
      #ifdef TEST_STAGE
        printf(":!c: cls = NULL \n");
      #endif
    }
    if(cdrCodec->data_endian == BigEndian) {
      fid = (*env)->GetStaticFieldID(env,
    		                         cls,
    		                         "BIG_ENDIAN",
    		                         "Ljava/nio/ByteOrder;");
    }
    else {
      fid = (*env)->GetStaticFieldID(env,
    		                         cls,
    		                         "LITTLE_ENDIAN",
    		                         "Ljava/nio/ByteOrder;");
    }
    if(fid == 0) {
      #ifdef TEST_STAGE
	    printf(":!c: fid = NULL \n");
	  #endif
    }
    obj_bo = (*env)->GetStaticObjectField(env, cls, fid);
    if(obj_bo == 0) {
      #ifdef TEST_STAGE
	    printf(":!c: cls = NULL \n");
	  #endif
    }

    // set byte order to ByteBuffer
    // get BB class
    cls = (*env)->GetObjectClass(env, byte_buf);
    if(cls == 0)
    {
      #ifdef TEST_STAGE
        printf(":!c: cls = NULL \n");
      #endif
    }
    // get methodID - order(ByteOrder)
    mid = (*env)->GetMethodID(env,
                             cls,
                             "order",
                             "(Ljava/nio/ByteOrder;)Ljava/nio/ByteBuffer;");
    if(mid == 0)
    {
      #ifdef TEST_STAGE
        printf(":!c: mid = NULL \n");
      #endif
    }

    // set ByteOrder
    if((*env)->CallObjectMethod(env,byte_buf,mid,obj_bo) == 0)
    {
      #ifdef TEST_STAGE
        printf(":!c: set byte order failed.. \n");
      #endif
    }

    // delete global reference
    (*env)->DeleteGlobalRef(env, byte_buf);
    byte_buf = 0;

    (*javavm)->DetachCurrentThread(javavm);
  }

  //copy over the message instance
  memcpy(instance,
         cdrCodec->buffer,
         cdrCodec->buf_len);
}

JNIEXPORT jint JNICALL
Java_org_ocera_orte_DomainApp_jORTETypeRegisterAdd
(JNIEnv *env, jclass cls, jlong handle, jstring jname, jlong jlength, jobject obj_bb)
{
  const char     *name;
  int            b;

  // get type name from JAVA env
  name = (*env)->GetStringUTFChars(env,jname,0);
  // call ORTE function
  b = ORTETypeRegisterAdd((ORTEDomain *) handle,
                          name,
                          NULL,
                          (ORTETypeDeserialize)deserialize,
                          NULL,
                          (unsigned int) jlength);
  // free memmory space
  (*env)->ReleaseStringUTFChars(env,jname,name);

  byte_buf = (*env)->NewGlobalRef(env, obj_bb);

  #ifdef TEST_STAGE
  printf(":c: jORTETypeRegisterAdd vraci %d [%d = ORTE_OK, %d = ORTE_BAD_HANDLE] \n",
         b,ORTE_OK,ORTE_BAD_HANDLE);
  #endif
  return b;

}
