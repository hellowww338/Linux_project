#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *arg)
{
    //char str[] = "hello thread"; //局部变量
    char *str = "hello thread"; //放在常量区
    
    pthread_exit(str);
}

int main(int argc, char **argv)
{   
    pthread_t tid1;
    char *p;
    pthread_create(&tid1, NULL, thread_fun1, NULL); //创建一个线程,立即返回
    printf("this is sub thread1: %ld\n", tid1);
    pthread_join(tid1, (void **)&p);
    printf("线程函数的返回值: %s\n", p);
    return 0;

}

