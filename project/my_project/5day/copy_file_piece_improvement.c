
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
	int remain=0;
	char progress_cnt=1;//���ȼ���
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
	remain=file_size%COPY_SIZE;	

	while(file_size)
	{
		file_size=file_size-COPY_SIZE;
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
		if(file_size < COPY_SIZE )
		{
			break;
		}
			value[((progress_cnt*COPY_SIZE)*100/file_size)-1] = '#';
			printf("[%-100s] [%d%%]\r", value, ((progress_cnt*COPY_SIZE)*100/file_size));                                                                                                                                  
			fflush(stdout);//ˢ����Ļ��ӡ  
			
			progress_cnt++;
		usleep(10000); //ģ�⸴���ļ���ʱ��
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
//��һ��д��
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