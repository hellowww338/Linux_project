#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{   
    FILE *fp = NULL;
    // fp = fopen("a.txt", "r");
    //if (fp == NULL) {
    // if (NULL == fp) {
    if ((fp = fopen("a.txt", "r"))==NULL) {
        perror("fopen fail");
        exit(1); //终止进程 ===return 1
    }
    printf("fopenc success\n");
    fclose(fp);
    return 0;

}
