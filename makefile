# Makefile for whole project
exe = run
objects = main.o 
objects += debug.o
#sources = main.c

exe:$(objects)
	cc -o $(exe) $^
	-$(RM) $^

.PHONY:clean
clean:
	-$(RM) $(exe)

.PHONY:clean.obj
clean.obj:
	-$(RM) $(objects)

.PHONY:clean.all
clean.all:
	-$(RM) $(exe) $(objects)


