CC = gcc
CFLAGS = -Wall
SRC = $(shell ls *.c)
APP = $(patsubst %.c, %, $(SRC))

all: $(APP)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<
clean:
	$(RM) $(APP)

.PHONY: clean



