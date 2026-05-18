#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#define SIZE 1024
int main(void)
{
    pid_t pid;
    char buf[SIZE];
    memset(buf, 0, SIZE);
    printf("%% ");
    while (fgets(buf, SIZE, stdin) != NULL) {
        //printf("you input command:%s", buf);
        if (buf[strlen(buf)-1] == '\n') //把换行符去掉
            buf[strlen(buf)-1] = '\0';

        if ((pid = fork()) < 0) {
            perror("fork");
            exit(0);
        } else if (pid == 0) {
            //子进程代码入口
            //execlp(buf, buf, NULL); 
            execl("/bin/sh", "sh", "-c", buf,(char *)0);
            printf("%s: command not found\n", buf);
            exit(1);
        } 
        waitpid(pid, NULL ,0);
        printf("%% ");
    }

    printf("bye\n");


}

