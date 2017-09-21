Grace Seiche - PA6
README

My Program

This program is designed to simulate ants and doodlebugs as they move, eat (or are eaten), breed, and
die. I organized this project into 5 classes. Organism is an abstract class with the basic members
and member functions for all organisms. Doodlebug and Ant are concrete, derived classes of Organism 
that implement the pure virtual functions breed(), breedEligible(), and move() of the Organism class.
Board is a separate class dedicated to the board where the Organism pointers are stored. It contains
two members: the grid (where the Organism pointers are stored) and the size (the length of the grid).
Board also has member functions for constructing and destructing boards, printing boards, and counting
the number of ants or doodlebugs in the grid. Finally, PA6 is the main class where the game is 
actually played. The output from the game is stored in a file called output.txt


To Compile, Execute the make command


To Run, Execute the following command
		./PA6 gridSize #doodlebugs #ants #time_steps seed pause
where gridSize is a positive, non-zero integer for the square board dimensions (non-integers will be
cast to integers, zero or negative values are errors); #doodlebugs is a positive, non-zero integer for 
the number of doodlebugs on the board (non-integers will be cast to integers, zero or negative values
are errors); #ants is a positive, non-zero integer for the number of ants on the board (non-integers
will be cast to integers, zero or negative values are errors); #time_steps is a positive, non-zero
integer for the number of steps to be completed before termination (non-integers will be cast to
integers, negative or zero values are errors); seed is the seed for the random number generator (if
provided) (note: the project instructions state that if seed==0, then the seed should be the time, 
however, in class Professor Lauer told us that it was not necessary and as such, my project does not
implement that); pause is a positive or zero integer representing the number of steps between 
printing the board (if pause==0, only the initial and final boards are printed) (non-integers are 
cast to integers, negative values are errors).
Note: the default values for the command line arguments should the not be included are as follows
gridSize = 20
#doodlebugs = 5
#ants = 100
#time_steps = 1000
seed = 1
pause = 0


Problems

To the best of my knowledge, my program is accurate and fully functional. My greatest struggle in this
assignment was deciding which members and member functions each class needed in addition to the required
member functions.

Algorithms

All algorithms in this project are my own. I did not consult any outside sources.

Tests

To test this program, I used a variety of command line arguments testing small values, large values, and
invalid. I manually traced each organism to ensure that it moved and bred correctly. Since I tested
many different sets of arguments, I am only including sample out for three sets of arguments, since 
page 3 of the assignment says output from at least two tests. My sample outputs are in the following 
three files included in this project: outputSample1.txt, outputSample2.txt, and outputSample3.txt
