#include <stdio.h>
#include "debug.h"

int log_level = 1;

void log_level_dump()
{
	printf("log_level = %d\n", log_level);
}