#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *arg)
{
    int i;
    for (i = 0; i < 500; i++) {
        printf("this is sub thread1---->%d\n", i);
        sleep(1);
    }
    return NULL;
}
void *thread_fun2(void *arg)
{
    int i;
    for (i = 0; i < 500; i++) {
        printf("this is sub thread2---->%d\n", i);
        sleep(1);
    }
    return NULL;
}
void *thread_fun3(void *arg)
{
    int i;
    for (i = 0; i < 500; i++) {
        printf("this is sub thread3---->%d\n", i);
        sleep(1);
    }
    return NULL;
}


int main(int argc, char **argv)
{   
    pthread_t tid1, tid2, tid3;
    int i;
    pthread_create(&tid1, NULL, thread_fun1, NULL); //创建一个线程,立即返回
    pthread_create(&tid2, NULL, thread_fun2, NULL); //创建一个线程,立即返回
    pthread_create(&tid3, NULL, thread_fun3, NULL); //创建一个线程,立即返回
    for (i = 0; i < 3; i++) {
        printf("this is main thread---->%d\n", i);
        sleep(1);
    }
    
    return 0; //exit(0)

}

