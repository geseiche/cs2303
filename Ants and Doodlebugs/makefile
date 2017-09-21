# Grace Seiche - PA6
# makefile

CFLAGS = -Wall -g

PA6: organism.o ant.o doodlebug.o board.o PA6.o
	g++ $(CFLAGS) -o PA6 PA6.o organism.o ant.o doodlebug.o board.o
	
board.o: board.cpp board.h organism.h ant.h doodlebug.h
	g++ $(CFLAGS) -c board.cpp

organism.o: organism.cpp organism.h
	g++ $(CFLAGS) -c organism.cpp
	
ant.o: ant.cpp ant.h organism.h
	g++ $(CFLAGS) -c ant.cpp

doodlebug.o: doodlebug.cpp doodlebug.h organism.h
	g++ $(CFLAGS) -c doodlebug.cpp

PA6.o: PA6.cpp organism.h ant.h doodlebug.h
	g++ $(CFLAGS) -c PA6.cpp

clean:
	rm -f *.o PA6

all: PA6
