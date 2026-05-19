#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *thread_fun1(void *arg)
{
    int i;
    pthread_t tid = pthread_self();
    pthread_detach(tid); //线程分离
    for (i = 0; i < 5; i++) {
        printf("this is sub thread1---->%d\n", i);
        sleep(1);
    }
    return NULL;
}

int main(int argc, char **argv)
{   
    pthread_t tid1;
    pthread_create(&tid1, NULL, thread_fun1, NULL); //创建一个线程,立即返回
    sleep(2);
    pthread_cancel(tid1);
   
    return 0; //exit(0)

}

