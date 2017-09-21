// Grace Seiche
// game.c - playing game, test termination

#include "game.h"
#include "board.h"

#include<stdio.h>
#include<stdlib.h>

//takes an array, a position in the array, and the height and width of the array
//determines the number of living neighbors the position has
//determines whether the given cell lives or dies in the next round
//returns 1 if it lives and 0 if it dies
char countNeighbors (char **old, int x, int y, int width, int height){
	int ln =0;//living neighbors
	if((x!=0) && (y!=0) && old[x-1][y-1]){//top left
		ln++;
	}
	if( (x!=0) && (old[x-1][y])){//top
		ln++;
	}
	if( (x!=0) && y<(width-1) && old[x-1][y+1]){//top right
		ln++;
	}
	if(y<(width-1) && old[x][y+1]){//right
		ln++;
	}
	if(x<(height-1) && y<(width-1) && old[x+1][y+1]){//bottom right
		ln++;
	}
	if(x<(height-1) && old[x+1][y]){//bottom
		ln++;
	}
	if(x<(height-1) && (y!=0) && old[x+1][y-1]){//bottom left
		ln++;
	}
	if( (y!=0) && old[x][y-1]){//left
		ln++;
	}
	switch (ln){
	case 0 : case 1 : case 4 : case 5 : case 6 : case 7 : case 8 ://dies of over- or under-crowding
		return 0;
		break;
	case 3 ://lives
		return 1;
		break;
	case 2 ://lives if alive, dies if dead
		if(old[x][y])
			return 1;
		else
			return 0;
		break;
	}
	return 0;
}//char countNeighbors (char **old, int x, int y, int width, int height)


//takes an old and new array of same size, and the int width and int height of the arrays
//creates the next generation in the newBoard
//returns void
void playOne(char **old, char **newBoard, int width, int height){
	for (int row=0; row<height; row++){//loop invariant: row<height
		for (int col=0; col<width; col++){//loop invariant: col<width
			newBoard[row][col] = countNeighbors(old, row, col, width, height);
		}
	}
}//void playOne(char **old, char **newBoard, int width, int height)


//takes the oldest board, the old board, and the new board, and the width and height of the board
//tests for three of the four termination conditions
//returns a positive number if it should be terminated and 0 if it should continue for another generation
int terminate (char **oldest, char **old, char **newBoard, int width, int height){
	//steady state
	if(compareBoard(newBoard, old, height, width))
		return 1;
	//oscillating state
	if(compareBoard(newBoard, oldest, height, width))
		return 2;
	//empty board
	for(int row=0; row<height; row++){//loop invariant: row<height
		for(int col=0; col<width; col++){//loop invariant: col<width
			if(newBoard[row][col]==1)
				return 0;// if not empty
		}
	}
	return 3;
}//int terminate (char **oldest, char **old, char **newBoard, int width, int height)




