#ifndef __DEBUG_H__
#define __DEBUG_H__
#include "syscode.h"

#define LOG(num) printf("num = %d\n", (num))
#define CALL(fun, argu) \
do { \
    int rv; \
    rv = fun argu; \
    if(rv != SUCCESS) { \
        printf("error code is: %d\n", rv); \
	} \
} while(0)

#define CALL_NO_ARGU(fun) \
do { \
    int rv; \
    rv = fun (); \
    if(rv != SUCCESS) { \
        printf("error code is: %d\n", rv); \
	} \
} while(0)

extern int log_level;

extern void log_level_dump();
extern int printf_buf(void *buf, int size);

#endif /* __DEBUG_H__ */