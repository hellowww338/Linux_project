CC = gcc
CFLAGS = -Wall

SUBDIRS= main \
                list \
                obj

BIN_DIR=bin
OBJ_DIR=obj
export CC OBJ_DIR BIN_DIR


all: check_dir $(SUBDIRS)       #完成这两个依赖
check_dir:
	mkdir -p $(BIN_DIR)

$(SUBDIRS):echo
	make -C $@

echo:
	@echo $(SUBDIRS)
	@echo begin compile
	
clean :
	$(RM) $(OBJ_DIR)*.o 
	rm -rf $(BIN_DIR)

.PHONY : clean

