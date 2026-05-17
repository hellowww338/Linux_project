
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define COPY_SIZE 5
int main(int argc, char *argv[])
{
	char temp[50];
	char ret;
	int file_size=0;
	int data_num=0,remain=0;
	int scale=0;//刻度
	char progress_cnt=1;//进度计数
	char value[100];  
	struct stat st;
	memset(value, '\0', sizeof(value));   
	if(argc != 3)
	{
		printf("Usage: %s source_file destination_file\n", argv[0]);
		exit(1);
	}
	int fd_r = open(argv[1], O_RDONLY);
	int fd_w = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC);
	if(fd_r == -1 || fd_w == -1)
	{
		perror("open");
		exit(1);
	}
	lseek(fd_r, 0, SEEK_END);
	fstat(fd_r, &st);
	file_size=st.st_size;
	lseek(fd_r, 0, SEEK_SET);
	data_num=file_size/COPY_SIZE;
	remain=file_size%COPY_SIZE;	
	scale=file_size/100; 

	while(data_num--)
	{
		ret=read(fd_r, temp, COPY_SIZE);
		if(ret != COPY_SIZE)
		{	
			printf("Read file %s error.\n", argv[1]);		
			break;			
		}
		if(write(fd_w, &temp, COPY_SIZE) != COPY_SIZE)
		{
			perror("write");
			exit(1);
		}
		if(lseek(fd_r, 0, SEEK_CUR) > scale*progress_cnt )
		{
//			printf("progress... %d%%\r", progress_cnt++);
//			 fflush(stdout); //立刻刷新输出缓冲区，显示进度
			printf("[%-100s] [%d%%]\r", value, progress_cnt);                                                                                                                                  
			fflush(stdout);//刷新屏幕打印  
			value[progress_cnt-1] = '#';
			progress_cnt++;
		}
		usleep(10000); //模拟复制文件的时间
	}
	if(read(fd_r, temp, remain) == remain)
	{
		write(fd_w, temp, remain);
//		printf("progress... %d%%\r", progress_cnt++);
		value[99] = '#';
		printf("[%-100s] [%d%%]\n", value, 100);        
	}
	printf("Copy file from %s to %s successfully.\n", argv[1], argv[2]);

	close(fd_r);
	close(fd_w);
	return 0;
}

/* 
//第一种写法
char temp[50];
	char ret;
	int p_cnt=0;

while(1)
	{
		ret=fread(temp, 20, 1, fp_r);
		if(ret != 1)
		{
			int i=(ftell(fp_r)-p_cnt);
			fseek(fp_r, -i, SEEK_CUR);
				if(fread(temp, i, 1, fp_r))
				{
					fwrite(temp, i, 1, fp_w);
				}
				break;			
		}
		p_cnt=ftell(fp_r) ;
		if(fwrite(&temp, 20, 1, fp_w) != 1)
		{
			perror("fwrite");
			exit(1);
		}
	}

*/