#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *arg)
{
    int i;
    pthread_t tid = pthread_self();
    for (i = 0; i < 500; i++) {
        printf("this is sub thread1: %ld---->%d\n", tid, i);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char **argv)
{   
    pthread_t tid1;
    int i;
    pthread_create(&tid1, NULL, thread_fun1, NULL); //创建一个线程,立即返回
    printf("this is sub thread1: %ld\n", tid1);
    for (i = 0; i < 500; i++) {
        printf("this is main thread: %ld---->%d\n", pthread_self(), i);
        sleep(1);
    }
    
    return 0;

}

