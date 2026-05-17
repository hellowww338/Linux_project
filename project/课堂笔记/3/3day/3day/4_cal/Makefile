CC = gcc
CFLAGS = -Wall

go: add.o sub.o main.o
	$(CC) $(CFLAGS)  -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<


clean:
	$(RM)  *.o go

.PHONY: clean  #定义clean伪目标 强制更新

