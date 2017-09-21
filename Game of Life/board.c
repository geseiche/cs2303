// Grace Seiche
// board.c - utility functions for printing boards, comparison, etc.

#include<stdio.h>
#include<stdlib.h>

#include "board.h"

//takes two arrays of the same size and their height and width
//compares the arrays to see if they are the same
//returns 1 if they are the same and 0 if they are different
int compareBoard (char **A, char **B, int height, int width){
	for(int row=0; row<height; row++){//loop invariant: row<height
		for(int col=0; col<width; col++){//loop invariant: col<width
			if(A[row][col]!=B[row][col])
				return 0;
		}
	}
	return 1;
}//int compareBoard(char **A, char **B, int height, int width)


//takes a board its heght and its width
//prints the board of 1s and 0s as xs and os
//returns void
void printBoard (char **newBoard, int height, int width){
	for(int row=0; row<height; row++){//loop invariant: row<height
		for(int col=0; col<width; col++){//loop invariant: col<width
			if(newBoard[row][col])
				printf("x");
			else
				printf("o");
		}
		printf("\n");
	}
	printf("\n");
}//void printBoard (char newBoard**, int height, int width)


//takes an old array and new array of same size and their height and width
//copies the contents of the new array into the old array
//returns void
void copyBoard (char **old, char **newBoard, int height, int width){
	for(int row=0; row<height; row++){//loop invariant: row<height
		for(int col=0; col<width; col++){// loop invariant: col<width
			old[row][col] = newBoard[row][col];
		}
	}
}//void copyBoard (char **old, char **newBoard, int height, int width)
