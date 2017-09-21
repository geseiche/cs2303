README - Grace Seiche - PA2 - Conway's Game of Life

My Program

This program is designed to play Conway's Game of Life on a finite board. I organized my program into
three c files: board.c, game.c, and life.c. board.c contains the utility functions for dealing with 
boards such as copying boards, comparing boards, and printing boards. game.c contains the functions
for determining the number of living neighbors a cell has, playing one generation, and testing for
termination. life.c is the executable file, containing the main method. It puts all of the functions
together and plays the whole game. life.c also deals with all necessary memory allocations.


To Compile, Execute the make command


To Run, Execute the following command
		./life X Y gens input print pause
where X and Y are positive integers indicating the size of the board in their respective directions, 
gens is the integer number of generations to complete, input is the name of a file with an initial 
configuration, print is an optional argument either 'y' or 'n' as to whether each generation is
printed, and pause is an optional argument either 'y' or 'n' as to whether the user must enter a key
between generations. Print and pause default to 'n'


Problems

To the best of my knowledge, my program is accurate and fully functional. My greatest struggle in this
assignment was finding and fixing the segmentation faults that kept arising due to mis-allocating my
arrays. However, this helped me practice troubleshooting and made me more familiar with segmentation
faults and their causes.

Algorithms

All algorithms in this project are my own. I did not consult any outside sources.

Tests

To test this program, I used the test files acorn.txt, beehive.txt, blinker.txt, block.txt, diehard.txt, 
glider.txt, r_pentomino.txt, and tetromino.txt. I varied the arguments of the array to test for input
files that were too big for the boards, unknown characters in the input file, and invalid command line
arguments. All tests that I conducted were successful.

Loop invariants

life.c
line 42 i<aHeight
line 54 row<inputh
line 55 col<inputw
line 72 i<height
line 78 i<height
line 79 j<width
line 102 i<height
line 106 j<width
line 130 j<width
line 142 i<height
line 143 j<width
line 152 i<inputh
line 154 j<inputw
line 220 count<gens

board.c
line 13 row<height
line 14 col<width
line 27 row<height
line 28 col<width
line 44 row<height
line 45 col<width

game.c
line 62 row<height
line 63 col<width
line 81 row<height
line 82 col<width
