#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

struct student {
    int sno;
    char name[30];
    float score;
};

void *thread_fun1(void *arg)
{
    // int a = *((int *)arg);
    // printf("a = %d\n", a);
    struct student st = *((struct student *)arg);
    printf("%d %s %f\n", st.sno, st.name, st.score);


    return NULL;
}

int main(int argc, char **argv)
{   
    pthread_t tid1;
    //int a = 100;
    struct student st = {1001, "rose", 78.5};
    // pthread_create(&tid1, NULL, thread_fun1, &a); //创建一个线程,立即返回
    pthread_create(&tid1, NULL, thread_fun1, &st); //创建一个线程,立即返回
    printf("this is sub thread1: %ld\n", tid1);
    pthread_join(tid1, NULL);
    printf("main thread over\n");
    return 0;

}

