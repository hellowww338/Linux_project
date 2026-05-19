#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *arg)
{
    int i;
    for (i = 0; i < 3; i++) {
        printf("this is sub thread1---->%d\n", i);
        sleep(1);
    }
    pthread_exit(NULL);
}
void *thread_fun2(void *arg)
{
    int i;
    for (i = 0; i < 4; i++) {
        printf("this is sub thread2---->%d\n", i);
        sleep(1);
    }
    //return NULL;
    pthread_exit(NULL);
}
void *thread_fun3(void *arg)
{
    int i;
    for (i = 0; i < 5; i++) {
        printf("this is sub thread3---->%d\n", i);
        sleep(1);
    }
    // return NULL;
    pthread_exit(NULL);
}


int main(int argc, char **argv)
{   
    pthread_t tid1, tid2, tid3;
    pthread_create(&tid1, NULL, thread_fun1, NULL); //创建一个线程,立即返回
    pthread_create(&tid2, NULL, thread_fun2, NULL); //创建一个线程,立即返回
    pthread_create(&tid3, NULL, thread_fun3, NULL); //创建一个线程,立即返回
    // sleep(1);
    // pthread_exit(NULL);
    pthread_join(tid1, NULL); //等待线程结束,没结束就阻塞
    printf("tid1 return\n");
    pthread_join(tid2, NULL); //等待线程结束,没结束就阻塞
    printf("tid2 return\n");
    pthread_join(tid3, NULL); //等待线程结束,没结束就阻塞
    printf("tid3 return\n");
    printf("main thread over\n");
    return 0;
}

