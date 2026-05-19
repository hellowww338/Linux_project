
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <pthread.h>
int a = 100;
int money = 0;

void *thread1_fun(void *arg)
{
	while(1)
	{
		
		printf("thread1_fun is running a=%d money=%d\n", a, money);
		if(a>0)
		{
			a--;
			money += 1;
		}
		else
		{
			a=0;
			printf("fun1 ticket is sold out\n");
			break;
		}
		sleep(2);
	}
	return NULL;
}

void *thread2_fun(void *arg)
{
	while(1)
	{
		printf("thread2_fun is running a=%d money=%d\n", a, money);
		if(a>0)
		{
			a--;
			money += 1;
		}
		else
		{
			a=0;
			printf("fun2 ticket is sold out\n");
			break;
		}
		sleep(3);
	}
	return NULL;
}

void *thread3_fun(void *arg)
{
	while(1)
	{
		printf("thread3_fun is running a=%d money=%d\n", a, money);
		if(a>0)
		{
			a--;
			money += 1;
		}
		else
		{
			a=0;
			printf("fun3 ticket is sold out\n");
			break;
		}
		sleep(4);
	}
	return NULL;
}

void *thread4_fun(void *arg)
{
	while(1)
	{
		printf("thread4_fun is running a=%d money=%d\n", a, money);
		if(a>0)
		{
			a--;
			money += 1;
		}
		else
		{
			a=0;
			printf("fun4 ticket is sold out\n");
			break;
		}
		sleep(5);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid1, tid2, tid3, tid4;

	pthread_create(&tid1, NULL, thread1_fun, NULL);
	pthread_create(&tid2, NULL, thread2_fun, NULL);
	pthread_create(&tid3, NULL, thread3_fun, NULL);
	pthread_create(&tid4, NULL, thread4_fun, NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
	pthread_join(tid3,NULL);
	pthread_join(tid4,NULL);
	printf("All threads have finished\n");
	printf("a=%d, Total money collected: %d\n", a, money);
	return 0;
}
