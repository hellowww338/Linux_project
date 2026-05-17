#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{   
    int ch; //保存读到的字符
    int cnt = 0;
    FILE *fp_r = NULL, *fp_w;
    if (argc != 3) {
        printf("Usage:\n %s src dst\n", argv[0]);
        exit(1);
    }
    if ((fp_r = fopen(argv[1], "r"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
    if ((fp_w = fopen(argv[2], "w"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
    

    while ((ch = fgetc(fp_r)) != EOF) {
        cnt++;
        fputc(ch, fp_w);
    }
    printf("copy over: %d\n", cnt);

    fclose(fp_w);
    fclose(fp_r);

    return 0;

}
