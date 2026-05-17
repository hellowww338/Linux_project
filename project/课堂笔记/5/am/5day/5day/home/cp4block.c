//文本,二进程文件复制fread fwrite
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

/* 读写文件*/
#define BLOCK_SIZE  100  //都可以


int main(int argc, char *argv[])
{
	FILE *fp_r = NULL, *fp_w =NULL ;

	if(argc != 3 ) {
		printf("Usage:\n\t%s src_file dst_file\n\n", argv[0]);
	  	exit(1);  
	}

	fp_r = fopen(argv[1], "r"); //二进制文件读写  文件必须存在
	fp_w = fopen(argv[2], "w"); //二进制文件读写 文件不存在创建
	if(!fp_r || !fp_w) {
		perror("fopen");
		exit(1);	  	    
	}  

	char buf[BLOCK_SIZE];  //char类型  字符类型 1个字节整型
	int ret = -1;
	int i=0;

	/* 获取文件大小 */
	long file_size;
	fseek(fp_r, 0, SEEK_END);
	file_size = ftell(fp_r);
	
	fseek(fp_r, 0, SEEK_SET); //rewind(fp_r); 文件指针指向文件开始位置

	while(file_size >= BLOCK_SIZE) { //文件剩余大小大于等于缓冲区大小
		bzero(buf, BLOCK_SIZE);//缓冲区清零
		ret = fread(buf, BLOCK_SIZE, 1, fp_r); //读一个块大小为BLOCK_SIZE
		i++;
		printf("%d ret = %d\n", i,ret);//返回块数

		//if(!ret) break;
		file_size -= BLOCK_SIZE;
		fwrite(buf, BLOCK_SIZE, 1, fp_w);
		//fflush(fp_w);
	}
	printf("file_size=%ld\n", file_size);
	if(file_size > 0) { /* 还有最后不够一块的一部分数据*/
		bzero(buf,BLOCK_SIZE);
		ret = fread(buf, file_size, 1, fp_r);
		fwrite(buf, file_size, 1, fp_w);
		//fflush(fp_w);
		printf("last data: ret =%d\n", ret);
	}	    

	/* 关闭文件*/
	fclose(fp_r);
	fclose(fp_w);

	return 0;
}

