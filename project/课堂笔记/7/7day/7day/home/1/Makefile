CC = gcc
CFLAGS = -Wall -g -O0 -lpthread
SRC = $(shell ls *.c)
APP = $(patsubst %.c, %, $(SRC))

all: $(APP)

%: %.c
	$(CC)  -o $@ $< $(CFLAGS)
clean:
	$(RM) $(APP)

.PHONY: clean



