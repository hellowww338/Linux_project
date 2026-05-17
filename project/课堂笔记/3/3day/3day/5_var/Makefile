#VAR1 = $(VAR2)
#VAR2 = $(VAR3)
#VAR3 = hello world
#VAR1 := $(VAR2)
#VAR2 := $(VAR3)
#VAR3 := hello world
VAR1 += one
VAR1 += two
VAR1 += three
LIST1 = $(wildcard *.c)
LIST2 = $(shell ls  *.c)
LIST3 = $(shell pwd)
LIST4 = $(patsubst %.c, %.o, a.c b.c c.c d.c)
LIST5 = $(patsubst %.c, %.o, $(LIST1))
LIST6 = $(patsubst %.c, %.o, $(LIST2))

all:
	@echo $(VAR1)
	@echo $(VAR2)
	@echo $(VAR3)
	@echo $(LIST1)
	@echo $(LIST2)
	@echo $(LIST3)
	@echo $(LIST5)
	@echo $(LIST6)
	@echo $(LIST4)





