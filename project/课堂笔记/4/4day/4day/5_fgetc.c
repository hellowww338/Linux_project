#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{   
    int ch; //保存读到的字符
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

    while ((ch = fgetc(fp)) != EOF) {
        //  printf("%c", ch);
        //fputc(ch, stdout);
        putchar(ch);
        //  printf("0x%x\n", ch);
    }

#if 0
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
    ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
     ch = fgetc(fp);
    printf("%c\n", ch);
    printf("0x%x\n", ch);
#endif
    fclose(fp);

    return 0;

}
