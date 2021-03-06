/* JORTEVerbositySetLogFile.c */

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


// library header file's path
#include "orte.h"
// pregenerated header
#include "jorte/org_ocera_orte_JOrte.h"


/* native function - prototype declared in pregenerated header */
JNIEXPORT void JNICALL
Java_org_ocera_orte_JOrte_jORTEVerbositySetLogFile
  (JNIEnv *env, jclass cls, jstring j_logfile)
{
  const char *logfile;

  // get logfile
  logfile = (*env)->GetStringUTFChars(env, j_logfile, 0);
  // call ORTE function
  ORTEVerbositySetLogFile(logfile);
  // free memory
  (*env)->ReleaseStringUTFChars(env, j_logfile, logfile);
  return;
}
