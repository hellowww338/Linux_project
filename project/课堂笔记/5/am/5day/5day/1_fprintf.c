#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{   
    int ret;
    int a = 100;
    char b = 'b';
    float c = 3.14;
    FILE *fp = NULL;
    if (argc != 2) {
        printf("Usage:\n %s filename\n", argv[0]);
        exit(1);
    }
    if ((fp = fopen(argv[1], "w+"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
   
    ret = fprintf(fp, "%d %c %f\n", a, b, c);
    ret = fprintf(fp, "%d %c %f\n", a, b, c);
    printf("ret=%d\n", ret);
    fclose(fp);
    return 0;


}
