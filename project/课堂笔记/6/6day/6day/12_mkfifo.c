#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv)
{   
    if (argc != 2) {
        printf("Usage:\n %s fifoname\n", argv[0]);
        exit(1);
    }
    if (mkfifo(argv[1], 0664) < 0 ) {
        perror("mkfifo");
        exit(1);
    }
    sleep(5);
    // system("rm fifo");
    remove(argv[1]);
    return 0;

  

}

