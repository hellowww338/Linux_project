#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define SIZE 5

int main(int argc, char **argv)
{   
    int ret;
    char buf[SIZE];
    memset(buf, 0, SIZE);

    ret = read(STDIN_FILENO, buf, SIZE);
    printf("read ret=%d\n", ret);

    ret = write(STDOUT_FILENO, buf ,SIZE);
    printf("write ret=%d\n", ret);

    return 0;


}
