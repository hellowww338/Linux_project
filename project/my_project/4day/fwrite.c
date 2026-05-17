
#include "stdio.h"
#include "stdlib.h"
struct student
{
	char name[20];
	int num;
	float score;
};

int main(int argc, char *argv[])
{
	char a='a';
	int b=123;
	float c=3.14;
	char d[20]="Hello, World!";
	struct student e={"jison", 2021001, 95.5};
	
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
	fwrite(&a, sizeof(char), 1, fp);
	fwrite(&b, sizeof(int), 1, fp);
	fwrite(&c, sizeof(float), 1, fp);
	fwrite(d, sizeof(char), sizeof(d), fp);
	fwrite(&e, sizeof(struct student), 1, fp);
	printf("Write to file %s successfully\n", argv[1]);
	fclose(fp);
	return 0;
}
