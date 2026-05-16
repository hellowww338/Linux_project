
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
	char a;
	int b;
	float c;
	char d[20];
	struct student e;
	
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
	fread(&a, sizeof(char), 1, fp);
	fread(&b, sizeof(int), 1, fp);
	fread(&c, sizeof(float), 1, fp);		
	fread(d, sizeof(char), sizeof(d), fp);
	fread(&e, sizeof(struct student), 1, fp);
	printf("a = %c\n", a);
	printf("b = %d\n", b);
	printf("c = %.2f\n", c);		
	printf("d = %s\n", d);
	printf("e.name = %s\n", e.name);
	printf("e.num = %d\n", e.num);
	printf("e.score = %.2f\n", e.score);	

	printf("Read from file %s successfully.\n", argv[1]);
	fclose(fp);
	return 0;
}
