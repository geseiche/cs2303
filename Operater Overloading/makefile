# Grace Seiche - PA5 - makefile

CFLAGS = -Wall -g

PA5: rational.o stack.o PA52.o
	g++ $(CFLAGS) -o PA5 PA52.o rational.o stack.o

rational.o: rational.cpp rational.h
	g++ $(CFLAGS) -c rational.cpp
	
stack.o: stack.cpp stack.h
	g++ $(CFLAGS) -c stack.cpp

PA52.o: PA52.cpp rational.h stack.h
	g++ $(CFLAGS) -c PA52.cpp

clean:
	rm -f *.o PA5

all: PA5
