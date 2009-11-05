/* JORTESubscriptionDestroy.c */

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


#include <stdlib.h>
// library header file's path
#include "orte.h"
// enable TEST_STAGE run level
#include "jorte/4all.h"
// pregenerated header
#include "jorte/org_ocera_orte_Subscription.h"
//
#include "jorte/jorte_typedefs_defines.h"

JNIEXPORT jboolean JNICALL
Java_org_ocera_orte_Subscription_jORTESubscriptionDestroy
(JNIEnv *env, jobject obj, jint subs_handle)
{
  int8_t        b;
  jint          h;
  jclass        cls;
  jfieldID      fid;
  int           flag_ok = 0;

  #ifdef TEST_STAGE
    printf(":c: ORTESubscriptionDestroy() called.. \n");
  #endif

  do
  {
    // free callBack object
    // find cls
    cls = (*env)->GetObjectClass(env, obj);
    if(cls == 0)
    {
     #ifdef TEST_STAGE
       printf(":!c: cls = NULL! \n");
     #endif
     break;
    }
    // fieldID
    fid = (*env)->GetFieldID(env,
                             cls,
                             "callbackContextHandle",
                             "I");
    if(fid == 0)
    {
     #ifdef TEST_STAGE
       printf(":!c: fid = NULL! \n");
     #endif
     break;
    }
    // get value
    h = (*env)->GetIntField(env, obj, fid);
    if(h)
    {
      //JavaVM *jvm;
      //jint ret;
      JORTECallbackContext_t *ctx = (JORTECallbackContext_t*)h;
      if(ctx->obj)
      {
        #ifdef TEST_STAGE
          printf(":c: deleting ctx->obj \n");
        #endif
        (*env)->DeleteLocalRef(env, ctx->obj);
      }
      if(ctx->rinfo)
      {
        #ifdef TEST_STAGE
          printf(":c: deleting ctx->rinfo\n");
        #endif
        (*env)->DeleteLocalRef(env, ctx->rinfo);
      }
      //
      free((void*)h);
    }
    //
    if(subs_handle)
    {
      // free data buffer
      free(ORTESubscriptionGetInstance((ORTESubscription *) subs_handle));
      // call ORTE function
      b = ORTESubscriptionDestroy((ORTESubscription *) subs_handle);
      if (b == ORTE_BAD_HANDLE)
      {
        printf(":!c: subscription destroy failed! [bad sub handle] \n");
        break;
      }
      #ifdef TEST_STAGE
        printf(":c: subscription destroy succesfuly.. \n");
      #endif
    }
    // set flag
    flag_ok = 1;
  } while(0);

  #ifdef TEST_STAGE
     printf(":c: flag_ok = %d \n",flag_ok);
  #endif

  if(flag_ok == 0)
  {
    return 0;
  }

  return 1;

}