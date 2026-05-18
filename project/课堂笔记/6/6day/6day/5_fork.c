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
        //执行shell命令函数
        system("ps -o  pid,ppid,state,tty,command");
        exit(0); //等价return 0
    } else {
        //子进程会先于父进程结束
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());
        exit(1);
    }

}

