// Grace Seiche - PA3
// PA3

#include<stdio.h>
#include<stdlib.h>
#include "binaryTree.h"
#include "handleFile.h"

FILE *outputFile;
FILE *inputFile;
treeItem *root;

int main(int argc, char *argv[]){
	outputFile = fopen(argv[1], "w");
	char *str = malloc(sizeof(char)*200);
	char *ptr = str;
	for(int i=2; i<argc; i++){
		inputFile = fopen(argv[i], "r");
		root = buildFromFile(inputFile, root, str);
		fclose(inputFile);
	}
	sendToFile(outputFile, root);
	fclose(outputFile);
	free(ptr);
	freeTree(root);
	return 1;
}
