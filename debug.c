#include <stdio.h>
#include <stdio.h>
#include "debug.h"
#include "syscode.h"

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