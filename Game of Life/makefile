# Grace Seiche

CFLAGS = -Wall -g

life: board.o game.o life.o 
	gcc $(CFLAGS) -o life life.o board.o game.o

board.o: board.c board.h
	gcc $(CFLAGS) -c board.c

game.o: game.c game.h
	gcc $(CFLAGS) -c game.c
	
life.o: life.c board.h game.h
	gcc $(CFLAGS) -c life.c

clean:
	rm -f *.o life

all: life
