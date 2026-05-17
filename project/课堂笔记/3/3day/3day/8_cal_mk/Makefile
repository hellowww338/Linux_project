CC = gcc
SUBDIRS = fun_a \
	 fun_s \
	 main \
	 obj

OBJS = add.o sub.o main.o
BIN = myapp
OBJ_DIR = obj
BIN_DIR = bin
export CC OBJS BIN OBJ_DIR BIN_DIR

all: check_dir $(SUBDIRS)
check_dir:
	mkdir -p $(BIN_DIR)

$(SUBDIRS):echo
	make -C $@
echo:
	@echo $(SUBDIRS)
	@echo begin compile

clean:
	$(RM) $(OBJ_DIR)/*.o
	rm -rf $(BIN_DIR)	



