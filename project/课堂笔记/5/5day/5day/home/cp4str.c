#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define SIZE 2048
int main(int argc, char **argv)
{
	FILE *fp = NULL;
	FILE *fp_w = NULL;
	
	char buf[SIZE];
	bzero(buf, SIZE);
	int cnt = 0;
	
	if (argc != 3) {
		printf("usage: %s srcfile desfile\n", argv[0]);
		exit(1);
	}
	
	if ((fp = fopen(argv[1], "r")) == NULL) {
		perror("fopen fail");
		exit(1); //终止进程
	}
	if ((fp_w = fopen(argv[2], "w")) == NULL) {
		perror("fopen fail");
		exit(1); //终止进程
	}

	//SIZE-1   \0
	while (fgets(buf, SIZE, fp) != NULL) {
		printf("%s", buf);
		fputs(buf, fp_w);
		cnt++;
		//bzero(buf, SIZE);
	}

	printf("over %d\n", cnt);
	return 0;
}





