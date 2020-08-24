#ifndef __DEBUG_H__
#define __DEBUG_H__
#include "syscode.h"

uint8 log_level;
#define INFO_LEVEL 0x01
#define WAR_LEVEL 0x02
#define ERR_LEVEL 0x04

#define LOG_INFO(fmt, args...) \
do { \
        if(log_level & INFO_LEVEL) { \
            printf("INFO::[%s, %d]::" fmt , __FUNCTION__, __LINE__, ##args); \
    } \
} while(0)

#define LOG_WAR(fmt, args...) \
do { \
        if(log_level & WAR_LEVEL) { \
            printf("WAR::[%s, %d]::" fmt , __FUNCTION__, __LINE__, ##args); \
    } \
} while(0)

#define LOG_ERR(fmt, args...) \
do { \
        if(log_level & ERR_LEVEL) { \
            printf("ERR::[%s, %d]::" fmt , __FUNCTION__, __LINE__, ##args); \
    } \
} while(0)

#define CALL(fun, argu) \
do { \
    int _rv; \
    _rv = fun argu; \
    if(_rv != SUCCESS) { \
        printf("error code is: %d\n", _rv); \
	} \
} while(0)

#define CALL_NO_ARGU(fun) \
do { \
    int _rv; \
    _rv = fun (); \
    if(_rv != SUCCESS) { \
        printf("error code is: %d\n", _rv); \
	} \
} while(0)

extern void log_level_dump();
extern int printf_buf(void *buf, int size);

#endif /* __DEBUG_H__ */