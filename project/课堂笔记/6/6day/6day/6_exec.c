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
        sleep(1);
        
        exit(0); //等价return 0
    } else {
        //fork返回子进程代码入口
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());
        // execlp("ls", "ls", "-l", "-a", NULL); //替换子进程的内存映像
        // execl("/usr/bin/ls", "ls", "-l", "-a", NULL);
        // char *argv[] = {"ls", "-l", "-a", NULL};
        // execv("/usr/bin/ls", argv);
        execlp("xxx", "xxx", "-l", "-a", NULL);//执行错误返回
        printf("i am child exit\n");
        exit(1);
    }

}

