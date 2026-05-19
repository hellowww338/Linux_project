
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
struct tm *pt;

void Read_fun(int signum)
{
	if(signum == SIGUSR1)
	{
		printf("接收到目标pid的信号了\n");
		int fd_log=open("log.txt", O_WRONLY | O_CREAT |O_APPEND, 0664);//log.txt文件不存在就创建，存在就追加
		if(fd_log == -1)
		{
			perror("open");
			exit(1);
		}
		char value[256];
		sprintf(value, "当前时间：%d-%d-%d %d:%d:%d\n", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec);
		write(fd_log, value, strlen(value));

	}

}
int main(int argc, char *argv[])
{
	int fd_fifo;
	int ret;
	
    time_t tm1;
	pid_t tar_pid = getpid();
	printf("tar_pid:%d\n", tar_pid);
	if(argc != 2)
	{
		printf("Usage: %s FIFO_file\n", argv[0]);
		exit(1);
	}
	signal(SIGUSR1, Read_fun); 

	if(mkfifo(argv[1], 0664)	== -1)
	{
		printf("FIFO已经存在\n");
	}	
	else
	{
		printf("FIFO创建成功\n");

	}
	
	fd_fifo = open(argv[1], O_RDWR); //r+打开
	if(fd_fifo == -1)
	{	
		perror("open");
		exit(1);
	}	
	
	ret = write(fd_fifo, &tar_pid, sizeof(pid_t));
	if(ret == -1)
	{
		perror("write");
		exit(1);
	}
	printf("发送目标pid:%d\n", tar_pid);
	 
	
	

	while(1)
	{
		time(&tm1);
		pt = localtime(&tm1);
		printf("当前时间：%d-%d-%d %d:%d:%d\n", pt->tm_year + 1900, pt->tm_mon + 1, pt->tm_mday, pt->tm_hour, pt->tm_min, pt->tm_sec);
		sleep(1);
	}

	return 0;
}
