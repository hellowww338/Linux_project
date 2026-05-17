#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char **argv)
{   
    int fd;
    if (argc != 2) {
        printf("Usage:\n %s filename\n", argv[0]);
        exit(1);
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open fail");
        exit(1); //终止进程 ===return 1
    }
    printf("fd= %d\n", fd);
    sleep(1);
    close(fd);
    return 0;


}
