
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>

pid_t tar_pid;//目标pid

void Send_fun(int signum)
{
	

	if(signum == SIGINT)
	{
		printf("接收到SIGINT信号了\n");
		kill( tar_pid, SIGUSR1);
		printf("给目标pid发送了SIGUSR1信号了\n");
	}

}
int main(int argc, char *argv[])
{
	int fd_fifo;
	int ret;
	if(argc != 2)
	{
		printf("Usage: %s FIFO file\n", argv[0]);
		exit(1);
	}
	signal(SIGINT, Send_fun); 

	fd_fifo = open(argv[1], O_RDONLY);
	if(fd_fifo == -1)
	{	
		perror("open");
		exit(1);
	}	
	ret = read(fd_fifo, &tar_pid, sizeof(tar_pid));
	if(ret == -1)
	{
		perror("read");
		exit(1);
	}
	printf("得到目标pid:%d\n", tar_pid);
	while(1)
	{
		    sleep(1);
	}

	return 0;
}
