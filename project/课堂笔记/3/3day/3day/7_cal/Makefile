CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))
go: $(OBJ)
	$(CC) $(CFLAGS)  -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	$(RM)  $(OBJ)  go

.PHONY: clean  #定义clean伪目标 强制更新

