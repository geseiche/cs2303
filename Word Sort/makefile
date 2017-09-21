# Grace Seiche - PA3 - makefile

CFLAGS = -Wall -g

PA3: binaryTree.o handleFile.o PA3.o
	gcc $(CFLAGS) -o PA3 PA3.o binaryTree.o handleFile.o

binaryTree.o: binaryTree.c binaryTree.h
	gcc $(CFLAGS) -c binaryTree.c
	
handleFile.o: handleFile.c handleFile.h
	gcc $(CFLAGS) -c handleFile.c

PA3.o: PA3.c binaryTree.h handleFile.h
	gcc $(CFLAGS) -c PA3.c

clean:
	rm -f *.o life

all: PA3
