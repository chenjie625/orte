/*
 *  $Id: orteping.c,v 0.0.0.1           2003/10/07 
 *
 *  DEBUG:  section                     orteping
 *  AUTHOR: Petr Smolik                 petr.smolik@wo.cz
 *
 *  ORTE - OCERA Real-Time Ethernet     http://www.ocera.org/
 *  --------------------------------------------------------------------
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *  
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *  
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#ifndef _WIN32
  #include <signal.h>
#endif
#include "orte_api.h"

Boolean                 quite=ORTE_FALSE;

void
recvCallBack(const ORTERecvInfo *info,void *vinstance, void *recvCallBackParam) {
  u_int32_t *instance=(u_int32_t*)vinstance;
  
  switch (info->status) {
    case NEW_DATA:
      if (!quite)
        printf("received fresh issue %d\n",*instance);
      break;
    case DEADLINE:
      printf("deadline occured\n");
      break;
  }
}

void
sendCallBack(const ORTESendInfo *info,void *vinstance, void *sendCallBackParam) {
  u_int32_t *instance=(u_int32_t*)vinstance;
  
  switch (info->status) {
    case NEED_DATA:
      (*instance)++;
      if (!quite)
        printf("sent issue %d\n",*instance);
      break;
    case CQL:  //criticalQueueLevel
      break;
  }
}

static void usage(void) {
  printf("usage: ORTEPing <parameters> \n");
  printf("  -d, --domain <domain>         working manager domain\n");
  printf("  -p, --publisher               create publisher Ping,PingData\n");
  printf("  -S, --strength                strength of publisher <1>\n");
  printf("  -D, --delay <ms>              delay between two publications <1000>\n");
  printf("  -s, --subscriber              create subscriber Ping,PingData\n");
  printf("  -R, --refresh <s>             refresh period of application\n");
  printf("  -P, --purge <s>               purge time for services\n");
  printf("  -E, --expiration <s>          expiration time of application\n");
  printf("  -m, --minimumSeparation <s>   minimumSeparation between two issues\n");
  printf("  -v, --verbosity <level>       set verbosity level SECTION, up to LEVEL:...\n");
  printf("      examples: ORTEManager -v 51,7:32,5 sections 51 and 32\n");
  printf("                ORTEManager -v ALL,7     all sections up to level 7\n");
  printf("  -q  --quiet                   \n");
  printf("  -l, --logfile <filename>      set log file name\n");
  printf("  -V, --version                 show version\n");
  printf("  -h, --help                    this usage screen\n");
}

int main(int argc,char *argv[]) {
  static struct option long_opts[] = {
    { "domain",1,0, 'd' },
    { "publisher",0,0, 'p' },
    { "strength",1,0, 'S' },
    { "subscriber",0,0, 's' },
    { "refresh",1,0, 'R' },
    { "purge",1,0, 'P' },
    { "expiration",1,0, 'E' },
    { "minimumSeparation",1,0, 'm' },
    { "delay",1,0, 'D' },
    { "verbosity",1,0, 'v' },
    { "quiet",0,0, 'q' },
    { "logfile",1,0, 'l' },
    { "version",0,0, 'V' },
    { "help",  0, 0, 'h' },
    { 0, 0, 0, 0}
  };
  ORTEDomain              *d;
  ORTEDomainProp          dp; 
  ORTEPublication         *p=NULL;
  ORTESubscription        *s=NULL;
  int                     opt,domain=ORTE_DEFAULT_DOMAIN;
  int32_t                 strength=1;
  int32_t                 instanceSend=0,instanceRecv=0;
  NtpTime                 persistence,deadline,minimumSeparation,delay;
  Boolean                 havePublisher=ORTE_FALSE;
  Boolean                 haveSubscriber=ORTE_FALSE;
  
  ORTEInit();
  ORTEDomainPropDefaultGet(&dp);
  NTPTIME_BUILD(minimumSeparation,0); 
  NTPTIME_BUILD(delay,1); //1s
 
  while ((opt = getopt_long(argc, argv, "m:S:d:v:R:E:P:l:D:Vhpsq",&long_opts[0], NULL)) != EOF) {
    switch (opt) {
      case 'S':
        strength=strtol(optarg,NULL,0);
        break;
      case 'd':
        domain=strtol(optarg,NULL,0);
        break;
      case 'p':
          havePublisher=ORTE_TRUE;
        break;
      case 's':
          haveSubscriber=ORTE_TRUE;
        break;
      case 'v':
        ORTEVerbositySetOptions(optarg);
        break;
      case 'R':
        NtpTimeAssembFromMs(dp.baseProp.refreshPeriod,strtol(optarg,NULL,0),0);
        break;
      case 'P':
        NtpTimeAssembFromMs(dp.baseProp.purgeTime,strtol(optarg,NULL,0),0);
        break;
      case 'E':
        NtpTimeAssembFromMs(dp.baseProp.expirationTime,strtol(optarg,NULL,0),0);
        break;
      case 'm':
        NtpTimeAssembFromMs(minimumSeparation,strtol(optarg,NULL,0),0);
        break;
      case 'D':
        NtpTimeAssembFromMs(delay,strtol(optarg,NULL,0)/1000,strtol(optarg,NULL,0)%1000);
        break;
      case 'l':
        ORTEVerbositySetLogFile(optarg);
      case 'q':
        quite=ORTE_TRUE;
        break;
      case 'V':
        printf("Ocera Real-Time Ethernet (%s).\n",dp.version);
        exit(0);
        break;
      case 'h':
      default:
        usage();
        exit(opt == 'h' ? 0 : 1);
    }
  }
  //Create application     
  d=ORTEDomainAppCreate(domain,&dp,NULL,ORTE_FALSE);
  //Register ser./deser. rutines with maximal size 4 Bytes
  ORTETypeRegisterAdd(d,"PingData",NULL,NULL,4);   
  //Create publisher
  if (havePublisher) {
    NTPTIME_BUILD(persistence,5); 
    p=ORTEPublicationCreate(
         d,
         "Ping",
         "PingData",
         &instanceSend,
         &persistence,
         strength,
         sendCallBack,
         NULL,
         &delay);
  }
  if (haveSubscriber) {
    NTPTIME_BUILD(deadline,3); 
    s=ORTESubscriptionCreate(
         d,
         IMMEDIATE,
         BEST_EFFORTS,
         "Ping",
         "PingData",
         &instanceRecv,
         &deadline,
         &minimumSeparation,
         recvCallBack,
         NULL);
  }
  //never ending loop
  while (1) 
    ORTESleepMs(1000);
  exit(0);
}
