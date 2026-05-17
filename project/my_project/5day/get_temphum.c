
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct THL_data
{
	char node;
	char temp[2];
	char hum[2];
	char lux[2];
}THL_data;

int main(int argc, char *argv[])
{
	char ret;
	char temp=0;
	char status=0;
	struct THL_data thl_data;
	if(argc != 2)
	{
		printf("Usage: %s source_file destination_file\n", argv[0]);
		exit(1);
	}
	int fd = open(argv[1], O_RDONLY);
	if(fd == -1 || fd == -1)
	{
		perror("open");
		exit(1);
	}
	lseek(fd, 5, SEEK_SET);

	while(1)
	{
		ret=read(fd, &temp, 1);		
		if(ret ==0)
		{
			lseek(fd, 3, SEEK_SET);
		}
		else if(ret != 1)
		{	
			printf("Read file %s error.\n", argv[1]);		
			break;			
		} 
		switch(status)
		{
			case 0:
				if(temp =='#')
					status=1;
				break;
			case 1:
				if(temp == '#')
					status=2;
				else
					status=0;
				break;
			case 2:
				if(temp == 'I')
				{
					status=3;
				}
				else
					status=0;
				break;
			case 3:
				if(temp == 'D')
				{
					status=4;
				}
				else
					status=0;
				break;
			case 4:
				if(temp == 'T')
				{
					status=5;
				}
				else
					status=0;
				break;
			case 5:
				if(temp == 'H')
				{
					status=6;
				}
				else
					status=0;
				break;
			case 6:
				thl_data.node=temp;
				status=7;
				break;
			case 7:
				thl_data.temp[0]=temp;
				status=8;
				break;
			case 8:
				thl_data.temp[1]=temp;
				status=9;
				break;				
			case 9:
				thl_data.hum[0]=temp;
				status=10;	
				break;
			case 10:
				thl_data.hum[1]=temp;
				status=11;
				break;
			case 11:
				thl_data.lux[0]=temp;
				status=12;
				break;	
			case 12:	
				thl_data.lux[1]=temp;
				status=0;
				printf("N,T,H,L=%d#%2d#%2d#%2d\n", thl_data.node, thl_data.temp[1], thl_data.hum[1], thl_data.lux[0]);
				break;
		}
			

	}


	close(fd);
	return 0;
}
