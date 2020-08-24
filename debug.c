#include <stdio.h>
#include <stdio.h>
#include "debug.h"
#include "syscode.h"

//uint8 log_level = 1;

void log_level_dump()
{
	printf("log_level = %d\n", log_level);
}

int printf_buf(void *buf, int size)
{
	int i;
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