#include "stdio.h"
#include "string.h"

int main(void)
{
    char a[]="hello,world,ok";
    char * p;
    char *b=",";
    for(p=strtok(a,b);p!=NULL;p=strtok(NULL,b))    
    printf("%s\n",p);
    return 0;
}
