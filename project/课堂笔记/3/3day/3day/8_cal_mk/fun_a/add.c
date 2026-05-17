#include "../include/fun.h"
int add(int a, int b)
{
    int r = a + b;
    if (r > MAX) {
	printf("r>MAX\n");
    }
    return r;

}
