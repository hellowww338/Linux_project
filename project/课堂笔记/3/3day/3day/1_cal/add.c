#include "cal.h"

int add(int a, int  b)
{
    int r = a + b;
    if (r > MAX)
	printf("add结果大于MAX\n");
    return r;
}
