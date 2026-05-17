#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 10

int main(int argc, char **argv)
{   
    int ret;
    int cnt = 0;
    int fd, fdw;
    char buf[SIZE];
    if (argc != 3) {
        printf("Usage:\n %s src dst\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open fail");
        exit(1); //终止进程 ===return 1
    }
    fdw = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0664);
    if (fdw == -1) {
        perror("open fail");
        exit(1); //终止进程 ===return 1
    }
    printf("fd=%d fdw=%d\n", fd, fdw);

    while (1) {
        memset(buf, 0, SIZE);
        ret = read(fd, buf, SIZE);
        if (ret < 0) {
            perror("read");
            exit(1);
        } else if (ret == 0) {
            
            printf("read file over\n");
            break;
        } else {

            //write(STDOUT_FILENO, buf, ret); //读多少就写多少
            write(fdw, buf, ret);
            cnt++;
            printf("cnt=%d ret=%d\n", cnt, ret);
        }
    }
    
    close(fdw);
    close(fd);
    return 0;

}
