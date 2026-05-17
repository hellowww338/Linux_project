
CC =gcc
CFLAGS = -Wall


go : test.o linklist.o
		$(CC) $(CFLAGS) -o $@ $^
		
%.o : %.c
		$(CC) $(CFLAGS) -c -o $@ $<
		
clean : 
		$(RM) *.o go 
		
.PHONY : clean
