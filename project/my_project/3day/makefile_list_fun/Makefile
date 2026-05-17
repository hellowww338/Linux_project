CC = gcc
CFLAGS = -Wall

LIST = $(shell ls *.c)
OBJ = $(patsubst %.c, %.o, $(LIST))

go: $(OBJ)
		$(CC) $(CFLAGS)  -o $@ $^	
%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $<
			
clean : 
		$(RM) *.o go 
		
.PHONY : clean
