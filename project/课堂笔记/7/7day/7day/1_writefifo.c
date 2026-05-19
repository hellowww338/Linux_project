#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#define SIZE 1024
int main(int argc, char **argv)
{   
    int fd;
    char buf[SIZE];
    if (argc != 2) {
        printf("Usage:\n %s fifoname\n", argv[0]);
        exit(1);
    }
    if (mkfifo(argv[1], 0664) < 0 ) {
        perror("mkfifo");
        if (errno == EEXIST)
            printf("%s is exists\n", argv[1]);
        else
            exit(1); 
        
    }

    if ((fd = open(argv[1], O_RDWR)) < 0) {
        perror("open fail");
        exit(1);
    }

    while (1) {
        memset(buf, 0, SIZE);
        fgets(buf, SIZE, stdin);
        write(fd, buf, strlen(buf));
        if (strncmp(buf, "quit\n", 5) == 0 ) break;
    }
    close(fd);

    
    //remove(argv[1]);
    return 0;

}

