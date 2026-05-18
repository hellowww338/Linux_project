#include <stdio.h>
#include <unistd.h>
int main(void)
{

    while (1) {
        printf("pid=%d ppid=%d\n", getpid(), getppid());
        sleep(1);

    }

}

