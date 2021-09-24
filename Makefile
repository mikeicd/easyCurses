#arquivo Makefile
all: main.o easyCurses.o
	gcc main.o easyCurses.o -o main -lncurses

main.o: main.c easyCurses.h
	gcc -c main.c

easyCurses.o: easyCurses.c easyCurses.h
	gcc -c easyCurses.c

clean:
	rm *.o

install:
	mv main ../