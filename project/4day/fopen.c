
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
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
	printf("Open file %s successfully.\n", argv[1]);
	fclose(fp);
	return 0;
}
