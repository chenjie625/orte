/* orte/include/config.h.  Generated by configure.  */
/* orte/include/config.h.in.  Generated from configure.in by autoheader.  */

/* Define if linux kernel is found */
#define CONFIG_ORTE_KERNEL 1

/* Define to enable ORTE's RT support */
#define CONFIG_ORTE_RT 1

/* Define if kernel is RTAI patched */
/* #undef CONFIG_ORTE_RTAI */

/* Define if kernel is RTLinux patched */
#define CONFIG_ORTE_RTL 1

/* Define if is target a unix system */
/* #undef CONFIG_ORTE_UNIX */

/* Define if is target windows */
/* #undef CONFIG_ORTE_WIN */

/* Define to 1 if you have the <arpa/inet.h> header file. */
/* #undef HAVE_ARPA_INET_H */

/* Define to 1 if you have the <asm/byteorder.h> header file. */
#define HAVE_ASM_BYTEORDER_H 1

/* Define to 1 if you have the <byteswap.h> header file. */
/* #undef HAVE_BYTESWAP_H */

/* Define to 1 if you have the <ctype.h> header file. */
/* #undef HAVE_CTYPE_H */

/* Define to 1 if you have the <fcntl.h> header file. */
/* #undef HAVE_FCNTL_H */

/* Define to 1 if you have the `gethostbyname' function. */
/* #undef HAVE_GETHOSTBYNAME */

/* Define to 1 if you have the <getopt.h> header file. */
/* #undef HAVE_GETOPT_H */

/* Define to 1 if you have the `pthread' library (-lpthread). */
/* #undef HAVE_LIBPTHREAD */

/* Define to 1 if you have the `ws2_32' library (-lws2_32). */
/* #undef HAVE_LIBWS2_32 */

/* Define to 1 if you have the <linux/ctype.h> header file. */
#define HAVE_LINUX_CTYPE_H 1

/* Define to 1 if you have the <linux/if.h> header file. */
#define HAVE_LINUX_IF_H 1

/* Define to 1 if you have the <linux/in.h> header file. */
#define HAVE_LINUX_IN_H 1

/* Define to 1 if you have the <linux/module.h> header file. */
#define HAVE_LINUX_MODULE_H 1

/* Define to 1 if you have the <linux/socket.h> header file. */
#define HAVE_LINUX_SOCKET_H 1

/* Define to 1 if you have the <linux/string.h> header file. */
#define HAVE_LINUX_STRING_H 1

/* Define to 1 if you have the <linux/time.h> header file. */
#define HAVE_LINUX_TIME_H 1

/* Define to 1 if you have the <linux/types.h> header file. */
#define HAVE_LINUX_TYPES_H 1

/* Define to 1 if you have the <netdb.h> header file. */
/* #undef HAVE_NETDB_H */

/* Define to 1 if you have the <netinet/in.h> header file. */
/* #undef HAVE_NETINET_IN_H */

/* Define to 1 if you have the <net/if.h> header file. */
/* #undef HAVE_NET_IF_H */

/* Define to 1 if you have the <nictab.h> header file. */
#define HAVE_NICTAB_H 1

/* Define to 1 if you have the <nic.h> header file. */
#define HAVE_NIC_H 1

/* Define to 1 if you have the <pthread.h> header file. */
#define HAVE_PTHREAD_H 1

/* Define to 1 if you have the <rtl.h> header file. */
#define HAVE_RTL_H 1

/* Define to 1 if you have the <rtl_malloc.h> header file. */
#define HAVE_RTL_MALLOC_H 1

/* Define to 1 if you have the <rtnet.h> header file. */
/* #undef HAVE_RTNET_H */

/* Define to 1 if you have the <semaphore.h> header file. */
#define HAVE_SEMAPHORE_H 1

/* Define to 1 if you have the <signal.h> header file. */
/* #undef HAVE_SIGNAL_H */

/* Define to 1 if you have the <stdarg.h> header file. */
/* #undef HAVE_STDARG_H */

/* Define to 1 if you have the <stdio.h> header file. */
/* #undef HAVE_STDIO_H */

/* Define to 1 if you have the <stdlib.h> header file. */
/* #undef HAVE_STDLIB_H */

/* Define to 1 if you have the `strdup' function. */
/* #undef HAVE_STRDUP */

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/ioctl.h> header file. */
/* #undef HAVE_SYS_IOCTL_H */

/* Define to 1 if you have the <sys/socket.h> header file. */
/* #undef HAVE_SYS_SOCKET_H */

/* Define to 1 if you have the <sys/time.h> header file. */
/* #undef HAVE_SYS_TIME_H */

/* Define to 1 if you have the <sys/types.h> header file. */
/* #undef HAVE_SYS_TYPES_H */

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if you have the <udp.h> header file. */
#define HAVE_UDP_H 1

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the <windows.h> header file. */
/* #undef HAVE_WINDOWS_H */

/* Define to 1 if you have the <winsock2.h> header file. */
/* #undef HAVE_WINSOCK2_H */

/* Define to 1 if you have the <ws2tcpip.h> header file. */
/* #undef HAVE_WS2TCPIP_H */

/* Name of package */
#define ORTE_PACKAGE "orte"

/* Define to the address where bug reports for this package should be sent. */
#define ORTE_PACKAGE_BUGREPORT "petr.smolik@wo.cz"

/* Define to the full name of this package. */
#define ORTE_PACKAGE_NAME "orte"

/* Define to the full name and version of this package. */
#define ORTE_PACKAGE_STRING "orte 0.2.1"

/* Define to the one symbol short name of this package. */
#define ORTE_PACKAGE_TARNAME "orte"

/* Define to the version of this package. */
#define ORTE_PACKAGE_VERSION "0.2.1"

/* Define to 1 if you have the ANSI C header files. */
/* #undef STDC_HEADERS */

/* Version number of package */
#define ORTE_VERSION "0.2.1"

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */


#ifndef _GNU_SOURCE
  #define _GNU_SOURCE
#endif


/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
