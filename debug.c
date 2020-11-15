#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "debug.h"
#include "syscode.h"

#define SYSTEM_LOG_MAX          (5000)
#define SYSTEM_LOG_BUF_LEN      (1024)

static int system_log_fd = -1;
static char system_log_path[] = "./log/system.log";
static uint64 syslog_len = 0;

void debug_level_init(uint8 level)
{
	log_level = (level & 0xF);
}

void log_level_dump()
{
	printf("log_level = %d\n", log_level);
}

int32 printf_buf(void *buf, uint32 size)
{
	uint32 i;
	char *head;
	if (buf == NULL || size < 0) {
        return ERROR;
	}

    head = (char *)buf;
    for(i = 0; i < size; i++) {
        printf("%c", head[i]);
	}
	printf("\n");

	return SUCCESS;
}

void system_log_fd_open(void)
{
    /* create file for logging tm reg info */
    system_log_fd = open(system_log_path, O_CREAT | O_RDWR | O_TRUNC, 06666);
    if (system_log_fd == -1) {
        /* DO NOT RETURN HERE */
        LOG_ERR("open file %s fail\n", system_log_path);
    }
}

void system_log_fd_close(void)
{
    if (system_log_fd == -1) {
        /* DO NOT RETURN HERE */
	    close(system_log_fd);
        LOG_INFO("file %s close\n", system_log_path);
    }
}

void system_log_info_save(const char *fmt, ...)
{
    va_list     args;
    uint32     res;
    char        *log_buf;
 
    if (system_log_fd == -1) {
        return;
    }

    if(syslog_len >= SYSTEM_LOG_MAX) {
        syslog_len = 0;
		return;
    }
    syslog_len ++;

    log_buf = (char *)malloc(SYSTEM_LOG_BUF_LEN);
    if (log_buf == NULL) {
        return;
    }
    memset(log_buf, 0, SYSTEM_LOG_BUF_LEN);
 
    va_start(args, fmt);
    res = vsprintf(log_buf, fmt, args);
    if (res <= 0) {
        free(log_buf);
        return;
    }
    va_end(args);
 
    res = write(system_log_fd, log_buf, strlen(log_buf));
    free(log_buf);
    if (res == -1) {
        return;
    }
}