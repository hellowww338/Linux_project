#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(void)
{
    const char *str = "call write\n";
    printf("call printf"); // stdout -> 1
    sleep(1);
    // 操作提供的systemcall
    write(1, str, strlen(str)); // 1
    sleep(1);
    fork();

    return 0;
}

