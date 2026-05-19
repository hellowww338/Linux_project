CC=gcc
CFLAGS=-Wall -g -O0
SRC = $(shell ls *.c)
OBJ=$(patsubst %.c, %.o , $(SRC))
BIN=go 
all: $(BIN)

$(BIN):$(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ -I. 
%.o: %.c
	$(CC) -c -o $@ $< -I. 
	
clean:
	$(RM) .*.sw? $(OBJ) $(BIN)
