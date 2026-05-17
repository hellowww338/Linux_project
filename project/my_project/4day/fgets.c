
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
	char temp[20];
	if(argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}
	FILE *fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen");
		exit(1);
	}
	fgets(temp,10,fp);
	printf("Read from file %s successfully.\n", argv[1]);
	printf("The content is: %s\n", temp);
	fclose(fp);
	return 0;
}
