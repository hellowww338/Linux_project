#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(0);
    } else if (pid > 0) {
        //fork返回父进程代码入口
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());

    } else {
        //这样会产生孤儿进程
        sleep(1);
        //fork返回子进程代码入口
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());

    }

    return 0;
}

