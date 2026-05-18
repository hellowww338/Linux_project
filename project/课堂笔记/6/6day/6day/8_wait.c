#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(0);
    } else if (pid > 0) {
        //fork返回父进程代码入口
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());
        wait(&status); //子进程没结束就阻塞WIFEXITED
       
        printf("parent wait child end, return code: %d\n", WEXITSTATUS(status));
        exit(0); //等价return 0
    } else {
        //子进程会先于父进程结束
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());
        sleep(1);
        exit(17); //8位返回码
    }

}

