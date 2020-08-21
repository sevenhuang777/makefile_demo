#ifndef __DEBUG_H__
#define __DEBUG_H__

#define LOG(num) printf("num = %d\n", (num))

extern int log_level;

extern void log_level_dump();

#endif /* __DEBUG_H__ */