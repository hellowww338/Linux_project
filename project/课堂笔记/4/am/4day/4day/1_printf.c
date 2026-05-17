#include <stdio.h>
#include <unistd.h>
int main(void)
{   
    int i = 0;
    while (1) {
        printf("hello world");
         fflush(stdout); //强制刷新 标准输出文件流 stdout
        i++;
        sleep(1);
        if (i == 3) break;
    }

}
