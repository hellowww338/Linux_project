#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid, pid2;
    int status;

    if ((pid = fork()) < 0) {
        perror("fork");
        exit(0);
    } else if (pid > 0) {
        if ((pid2 = fork()) < 0) {
            perror("fork");
            exit(0);
        } else if (pid2 == 0) {
            printf("after fork() child2 pid=%d ppid=%d\n", getpid(), getppid());
            exit(16); //8位返回码

        }
        printf("after fork() pid=%d ppid=%d\n", getpid(), getppid());
        wait(&status); //子进程没结束就阻塞WIFEXITED
        printf("parent wait child end, return code: %d\n", WEXITSTATUS(status));
        wait(&status); //子进程没结束就阻塞WIFEXITED
        printf("parent wait child end, return code: %d\n", WEXITSTATUS(status));
        exit(0); //等价return 0
    } else {
        //子进程会先于父进程结束
        printf("after fork() child1 pid=%d ppid=%d\n", getpid(), getppid());
        sleep(1);
        printf("after fork() child1 pid=%d ppid=%d\n", getpid(), getppid());
        exit(17); //8位返回码
    }

}

