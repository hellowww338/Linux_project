#include "stdio.h"

int main(void)
{
    char a[5]="hello";
    char b[5];
    char *p=NULL;
    p=&b;
    char i;
    for(i=0;i<5;i++)
    {
	b[i]=a[i];
    }
    printf("a copy b;b=%s\n",b);
    return 0;
}
