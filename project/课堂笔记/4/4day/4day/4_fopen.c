#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{   
#if 0
    int i;
    printf("argc=%d\n", argc);
    for (i = 0; i < argc; i++)
        printf("argv[%d]=%s\n", i, argv[i]);
#endif
    FILE *fp = NULL;
    if (argc != 2) {
        printf("Usage:\n %s filename\n", argv[0]);
        exit(1);
    }
    if ((fp = fopen(argv[1], "r"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
    printf("fopenc %s success\n", argv[1]);
    fclose(fp);
    return 0;

}
