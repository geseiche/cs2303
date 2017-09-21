// Grace Seiche
// life.c - main program, read input & initialize

#include<stdio.h>
#include<stdlib.h>

#include "game.h"
#include "board.h"

//height and width of game board
//from command line
unsigned int height;
unsigned int width;

//rectangular height and width of board in input file
unsigned int inputh=0;
unsigned int inputw=0;

//boards for three generations
char **newBoard;
char **old;
char **oldest;

//board from input file with ones and zeros to fill it to the size of a game board
//top-left aligned
char **input;

//condensed (smaller) input board without extra zeros to be centered in a game board
char **initial;
FILE *inputFile;

//more command line input
int gens; //maximum generations
char print = 'n';
char pause = 'n';


//takes an array and its height (i.e. number of rows)
//frees the memory allocated to given array
//returns void
void freeArray(char **A, int aHeight){
	for(int i=0; i<aHeight; i++){//loop invariant: i<aHeight
		free(A[i]);
	}
	free(A);
}// void freeArray(char **A, int aHeight)


//takes no parameters, uses only global variables
//centers the initial configuration array on the array newBoard
//frees the initial array, as it is no longer in use
//returns void
void centerInitial (){
	for(int row =0; row<inputh; row++){//loop invariant: row<inputh
		for(int col=0; col<inputw; col++){//loop invariant: col<inputw
			newBoard[height/2-inputh/2+row][width/2-inputw/2+col]=initial[row][col];
		}
	}
	freeArray(initial, inputh);
}//void centerInitial ()


//takes no parameters
//allocates memory for the arrays newBoard, old, and oldest
//fills all arrays with zeros
//calls center input
void initializeBoard (){
	//allocate memory to arrays
	newBoard = malloc(sizeof(char*)*height);
	old = malloc(sizeof(char*)*height);
	oldest = malloc(sizeof(char*)*height);
	for(int i=0; i<height; i++){//loop invariant: i<height
		newBoard[i] = malloc(sizeof(char)*width);
		old[i] = malloc(sizeof(char)*width);
		oldest[i] = malloc(sizeof(char)*width);
	}
	//fill arrays with zeros
	for(int i=0; i<height; i++){//loop invariant: i<height
		for(int j=0; j<width; j++){//loop invariant: j<width
			newBoard[i][j] = 0;
			old[i][j] = 0;
			oldest[i][j] = 0;
		}
	}
	old[0][0]=1;//if all cells die on generation 1, terminate will return all cells died instead of oscillating state
	centerInitial();
}// void initializeBoard()


//takes no parameters
//read the file and use it to fill an array of size height and width
//print error messages if error is encountered
//create and fill a smaller array that contains only the input
//return 1 if the function worked
//return a negative integer if encountered an error
int initializeInput(){
	input = malloc(sizeof(char*)*height);
	char letter;//current character taken from file
	int countw;//counts the current width of the line
	int newLineCounter=0;//counts the number of characters between the newline characters
	//fill the input array
	for(int i=0; i<height; i++){//loop invariant i<height
		input[i] = malloc(sizeof(char)*width);
		inputh++;//increase the height of the input array with every iteration
		countw=0;
		for(int j=0; j<width; j++){//loop invariant: j<width
			if(newLineCounter>width){
				printf("Error: Input is larger than board\n");
				return -1;
			}
			letter = getc(inputFile);//take the next character in the input file
			// if a valid input, enter it in array and increase width
			if(letter!='\n'&&letter!=EOF){
				newLineCounter++;
				if(letter=='x'){
					input[i][j]=1;
				}
				else if(letter=='o'){
					input[i][j]=0;
				}
				else{
					printf("Error: Unknown character %c in input file\n", letter);
					return -2;
				}
				countw++;
			}
			else{
				//if a new line character, fill the rest of the line with 0s
				if(letter=='\n'){
					for(;j<width;j++){//loop invariant: j<width
						input[i][j] = 0;
						newLineCounter=0;
					}
				}
				//if this line is longer than the longest line, this is the longest line
				if(countw>inputw)
					inputw=countw;
				//if end of file, don't count that row and fill the rest of the board with 0s
				if(letter==EOF){
					if(j==0)
						inputh--;
					for(;i<height;i++){//loop invariant: i<height
						for(;j<width;j++){//loop invariant: j<width
							input[i][j]=0;
						}
					}
				}
			}
		}
		//allocate memory to the condensed initial array and fill it with the initial array gathered from the input
		initial =malloc(sizeof(char*)*inputh);
		for(int i=0; i<inputh; i++){//loop invariant: i<inputh
			initial[i]=malloc(sizeof(char)*inputw);
			for(int j=0; j<inputw; j++){//loop invariant: j<inputw
				initial[i][j]=input[i][j];
			}
		}
	}
	fclose(inputFile);//close the file b/c you are done reading from it
	freeArray(input, height);//free the input array because all necessary data is now in the initial array
	return 1;
}//int initializeInput()


//takes in the command line arguments
//assigns the command line arguments to their appropriate variables
//returns void
void initializeCommands(int argc, char *argv[]){
	//assign command line arguments
	width=atoi(argv[1]);
	height=atoi(argv[2]);
	gens = atoi(argv[3]);
	inputFile = fopen(argv[4], "r");//inputFile is a file to be read
	//optional arguments
	if(argv[5]){
		print = *argv[5];
		if(argv[6]){
			pause = *argv[6];
		}
	}
}//void initializeCommands(int argc, char *argv)


//takes in arguments from the command line
//plays Conway's game of life
//returns 1 if successful and 0 if unsuccessful
int main (int argc, char *argv[]){
	initializeCommands(argc, argv);
	if(height<=0||width<=0){
		printf("Error: Board dimensions must be greater than 0\n");
		return 0;
	}
	if(gens<=0){
		printf("Error: Generations must be greater than 0\n");
		return 0;
	}
	if(print!='y'&&print!='n'){
		printf("Error: print must be y or n\n");
		return 0;
	}
	if(pause!='y'&&pause!='n'){
		printf("Error: pause must be y or n\n");
		return 0;
	}
	//if error in initializeInput, return error here too
	if(initializeInput()<0){
		return 0;
	}
	//printf("Command line arguments (for tests only):\n%d %d %d %s %c %c\n\n", width, height, gens, argv[4], print, pause);
	initializeBoard();
	if(pause=='y'){
		printf("Press any key to continue\n");
		getchar();
	}
	if(print=='y'){
		printBoard(newBoard, height, width);
	}

	//play a round
	for (int count=0; count<gens; count++){//loop invariant: count<gens

		if(pause=='y'){
			getchar();
		}
		//transfer boards
		copyBoard(oldest, old, height, width);
		copyBoard(old, newBoard, height, width);
		playOne(old, newBoard, width, height);

		//detect any of 4 termination causes
		if(terminate(oldest, old, newBoard, width, height)){
			printBoard(newBoard, height, width);
			switch (terminate(oldest, old, newBoard, width, height)){
			case 1 :
				printf("Game terminated after %d generations: steady state\n", count+1);
				break;
			case 2 :
				printf("Game terminated after %d generations: oscillating state\n", count+1);
				break;
			case 3 :
				printf("Game terminated after %d generations: all cells died\n", count+1);
				break;
			}
			break;
		}
		if(count+1==gens){
			printBoard(newBoard, height, width);
			printf("Game terminated after %d generations: completed generations\n", count+1);
			break;
		}


		if(print=='y'){
			printBoard(newBoard, height, width);
		}

	}
	//free the boards when finished
	freeArray(newBoard, height);
	freeArray(old, height);
	freeArray(oldest, height);
	return 1;
}//int main (int argc, char *argv[])
