objects = main.o debug.o

run:$(objects)
	cc -o run $(objects)
	rm $(objects)

.PHONY:clean
clean:
	rm run

.PHONY:clean.obj
clean.obj:
	rm $(objects)

.PHONY:clean.all
clean.all:
	rm run $(objects)


