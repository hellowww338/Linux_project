#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#define  N   1024

int main(void)
{
	int fd_src, fd_des;
	// char src[N] = "girl.jpg";
	// char des[N] = "student.jpg";
	char src[N] = "cp2sys.c";
	char des[N] = "cp2sys.bak";
	
	int nbytes, ret;
	char buf[N];
	int size;
	int count = 0; //统计已拷贝的字节数
	int percent;
	fd_src = open(src, O_RDONLY);
	if (fd_src < 0) {
		perror("open");
		exit(1);
	}
	//获取文件大小
	struct stat st;
	fstat(fd_src, &st);
	size = st.st_size;
	printf("file size %d\n", size);

	
	fd_des = open(des, O_WRONLY|O_CREAT|O_TRUNC, 0664);
	if (fd_des < 0) {
		perror("open");
		exit(1);
	}


	
	while (1) {
		// bzero(buf, N);
		memset(buf, 0, N);
		nbytes = read(fd_src, buf, N); //一次nbytes读到字节数
		if (nbytes < 0) {
			perror("read");
			exit(1);
		} else if (nbytes == 0) {
			printf("read file over\n");
			break;
		} else {
			ret = write(fd_des, buf, nbytes);
			if (ret < 0) {
				perror("write");
				exit(1);
			}
			//拷贝进度百分比
			count += nbytes;
			percent = count*100/size;
			printf("拷贝进度: %s  %d%%\r", des, percent);
			fflush(stdout);
			usleep(500000); //微秒休眠 1ms
		}
	}
	printf("cp file over\n");	
	
	return 0;
	
}

