CC = gcc
CFLAGS = -Wall
SRC = $(wildcard *.c)
APP = go


$(APP): linklist.o test.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	$(RM) $(APP) *.o

.PHONY: clean


