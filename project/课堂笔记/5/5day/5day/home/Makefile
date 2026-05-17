CC = gcc
CFLAGS = -Wall
SRC = $(wildcard *.c)
APP = $(patsubst %.c, %, $(SRC))

all: $(APP)

%: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	$(RM) $(APP)

.PHONY: clean



