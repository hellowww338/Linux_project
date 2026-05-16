
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[])
{
	int size=50;
	char buf[size];
	int cnt=0;
	if(argc != 3)
	{
		printf("Usage: %s source_file destination_file\n", argv[0]);
		exit(1);
	}
	FILE *fp_r = fopen(argv[1], "r");
	FILE *fp_w = fopen(argv[2], "w");
	if(fp_w == NULL || fp_r == NULL)
	{
		perror("fopen");
		exit(1);
	}

	while(fgets(buf,size,fp_r) != NULL)
	{
		fputs(buf,fp_w);
		printf("Copied line %d\n", ++cnt);
	}

	printf(" file copy successfully.\n");
	fclose(fp_r);
	fclose(fp_w);
	return 0;
}
