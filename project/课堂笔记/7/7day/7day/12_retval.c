#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *arg)
{
    int *pa = malloc(sizeof(int));
    *pa = 200;
    
    return pa;
}

int main(int argc, char **argv)
{   
    pthread_t tid1;
    int *pi;
    pthread_create(&tid1, NULL, thread_fun1, NULL); //创建一个线程,立即返回
    printf("this is sub thread1: %ld\n", tid1);
    pthread_join(tid1, (void **)&pi);
    printf("线程函数的返回值: %d\n", *pi);
    return 0;

}

