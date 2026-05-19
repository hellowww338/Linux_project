#include <stdio.h>
#include <unistd.h>
#include <signal.h>

//2.定义信号处理函数
void sig_ctrl_c_handler(int signo) 
{
    if (signo == SIGINT) {
        printf("收到ctrl+c信号, 但不会终止进程...\n");
    }
}

int main(int argc, char **argv)
{   
    //1.注册信号
    signal(SIGINT, sig_ctrl_c_handler);

    while (1) {
        printf("我在等ctrl+c信号...\n");
        sleep(1);
    }

    return 0;

}

