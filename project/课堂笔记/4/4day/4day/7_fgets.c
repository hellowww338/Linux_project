#include <stdio.h>
#include <string.h>
#define SIZE 5
int main(void)
{   
    char buf[SIZE];
    memset(buf, 0, SIZE);
    // fgets(buf, SIZE, stdin);
    gets(buf);

    printf("%s", buf);

    return 0;

}
