#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 5
int main(int argc, char *argv[])
{   
    FILE *fp;
    if (argc != 2) {
        printf("Usage:\n %s filename\n", argv[0]);
        exit(1);
    }
    //char buf[SIZE] = "ab\nc";
    char buf[SIZE] = {'1','2','\0','3', '\0'};
    if ((fp = fopen(argv[1], "w"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
    fputs(buf, fp);
    puts(buf); //自带换行符
    fputs(buf, stdout);//不带换行符
    printf("game over\n");
    return 0;

}
