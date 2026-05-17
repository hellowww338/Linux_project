#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define SIZE 7

int main(int argc, char **argv)
{   
    int ret;
    int fd;
    char buf[SIZE];
    if (argc != 2) {
        printf("Usage:\n %s filename\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open fail");
        exit(1); //终止进程 ===return 1
    }
    
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
            write(STDOUT_FILENO, buf, SIZE);
        }
    }
    close(fd);
    return 0;

}
