#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{   
    char buf[BUFSIZ]; //系统缓冲区大小8KB
    
    int year = 2026, month=6, day =1;
    // sprintf(buf, "%d-%02d-%02d", year,month, day);
    snprintf(buf, BUFSIZ, "%d-%02d-%02d", year,month, day);
    printf("%s\n", buf);

    char uart_data[] = "12 34 ac"; //0x12 0x34 0xac
    unsigned char arr[3];
    sscanf(uart_data, "%x%x%x", (unsigned int *)&arr[0], 
        (unsigned int *)&arr[1], (unsigned int *)&arr[2]);
    printf("%d %d %d\n", arr[0], arr[1], arr[2]);

    return 0;


}
