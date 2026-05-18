#include <stdio.h>
#include <unistd.h>
int main(void)
{
    //同一个程序执行两个不同的进程
    printf("before fork() pid=%d ppid=%d\n", getpid(), getppid());
    fork();
    fork();
    printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());

    sleep(1000000);

    return 0;
}

