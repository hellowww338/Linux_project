CC = gcc
CFLAGS = -Wall

SUBDIRS= main \
		list \
		obj
		
BIN_DIR=bin
OBJ_DIR=obj
export CC OBJ_DIR BIN_DIR


all: check_dir $(SUBDIRS)	#完成这两个依赖
check_dir：
		mkdir -p $(BIN_DIR) bin文件夹放输出文件

$(SUBDIRS):
		make -C $@		#指定文件夹编译
clean : 
		$(RM) $(OBJ_DIR)*.o $(BIN_DIR) 
		
.PHONY : clean