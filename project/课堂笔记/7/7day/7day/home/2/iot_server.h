

#ifndef __IOT_SERVER_H__
#define __IOT_SERVER__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define SIZE 1024
#define LEN_MONI 7 //监控数据的字节数为7

void recv_coord_fun(void);

#endif
