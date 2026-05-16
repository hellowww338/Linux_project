
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(1);
	}
	FILE *fp = fopen(argv[1], "w");
	if(fp == NULL)
	{
		perror("fopen");
		exit(1);
	}
	fputs("Hello, World!\n", fp);
	printf("Write to file %s successfully\n", argv[1]);
	fclose(fp);
	return 0;
}
