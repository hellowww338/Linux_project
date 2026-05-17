
go: add.o sub.o main.o
	gcc add.o sub.o main.o -o go

add.o: add.c
sub.o: sub.c
main.o: main.c
clean:
	rm -f *.o go

.PHONY: clean  #定义clean伪目标 强制更新

