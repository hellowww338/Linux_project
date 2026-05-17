
#include "../include/fun.h"

int sub(int a, int b)
{
    int r = a - b;
    if (r > MAX) {
	printf("r>MAX\n");
    }
    return r;

}


