

#include "coord.h"
#include "iot_server.h"
extern char data_arr[13]; //模拟串口发送的13个字节的监控数据
extern char send_mob_buf[SIZE]; //发送监控数据字符串给移动端的缓冲区

/*
	功能: 接收串口协调器发来的数据

*/
void recv_coord_fun(void)
{
	int i;
	int check = 0; //未同步
	char vbuf[SIZE];
	node_data buf;
	int ret = 0;
	int cnt = 0 , line=0;
	char byte; //用来保存串口一个字节的变量
	char syncok = 0; //是否同步成功的标志
	int fd = open("ttyS.dat", O_RDONLY); //打开串口设备文件
	lseek(fd, 5, SEEK_SET);  //文件位置指针随机定位到5

	while (1) {
		bzero(vbuf, SIZE);		
		
		//循环读取一个数据包
		while (1) {
			byte = 0;

			ret = read(fd, &byte, 1); //什么开始读串口是随机
			if (ret == 0) goto repeat; //到文件末尾
			usleep(80000); //80ms
			//cnt++;
			if (byte == '#') {				
				byte = 0;
				ret = read(fd, &byte, 1);
				usleep(80000);
				if (ret == 0) goto repeat;
				if (byte == '#') {
					byte = 0;
					ret = read(fd, &byte, 1);
					usleep(80000);
					if (ret == 0) goto repeat;
				if (byte == 'I') {
					byte = 0;
					ret = read(fd, &byte, 1);
					usleep(80000);
					if (ret == 0) goto repeat;
					if (byte == 'D') {
						byte = 0;
						ret = read(fd, &byte, 1);
						usleep(80000);
						if (ret == 0) goto repeat;
						if (byte == 'T') {
							byte = 0;
							ret = read(fd, &byte, 1);
							usleep(80000);
							if (ret == 0) goto repeat;
							if (byte == 'H') {
								//##IDTH全部找到,说明正确的同步头开始
								//读取后面7个字节 一共13个字节为一个数据包
								for (i = 0; i < LEN_MONI; i++) {
									ret = read(fd, &byte, 1);
									if (ret == 0) goto repeat;
									buf.data[i] = byte;
									usleep(80000);
								}
								if (i == LEN_MONI) {
									syncok=1;
									line ++;
									

									printf("==%d== %02x %02x %02x %02x %02x %02x %02x\n", line, \
										buf.data[0], buf.data[1], buf.data[2], buf.data[3],\
										buf.data[4], buf.data[5], buf.data[6]);
									convert_moni_info(&buf, send_mob_buf);
									//将采集到7个字节的buf数据包转换为字符串
									break;
								}
							}
						}
					}
				}
			}
		
		}
			
			if (syncok == 1) {
				convert_moni_info(&buf, send_mob_buf);
				syncok = 0;
			}
		}
		if (ret > 0) continue;  //还没找到同步头
repeat:
		lseek(fd, 0, SEEK_SET);	//文件位置设置到开头
		line = 0;
	
	}
	
}

