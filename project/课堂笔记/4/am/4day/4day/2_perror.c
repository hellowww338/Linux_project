#include <stdio.h>
#include <unistd.h>
int main(void)
{   
    while (1) {
        perror("hello world"); //字符串写入标准出错文件中
        sleep(1);
    }

}
