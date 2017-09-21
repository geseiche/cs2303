README - Grace Seiche - PA1

My Program

This program is designed to print out a 12 month calendar for the year specified 
by the user. When prompted, enter an integer.


To Compile, Execute the Following Command

	gcc -Wall -o PA1 PA1.c


To Run, Execute the Following Command

	./a.out


Problems

I have no problems with this code. Designing my own algorithm for determining the 
day of the week was a challenge, but I believe it is currently correct. To the best 
of my knowledge, it is accurate.


Algorithms

All algorithms are my own. I did not consult with any outside sources.


Loop Invariants

In the function printDays, in the first for-loop, the loop invariant is on the 
printf command line. The loop invariant is that the counter i is less than the 
day of the week. 
//loop invariant: i<dayOfWeek

In the function printDays, in the second for-loop, there is a loop invariant on 
the first line of the body. The loop invariant is that the date is less than or
equal to the number of days in the month. 
//loop invariant: date<=number of days in given month

In the function printDays, in the second for-loop, there is a loop invariant on
the last line of the body. The loop invariant is that the 0 is less than or equal
to the day of the week, which is less than or equal to 6.
//loop invariant: 0<=dayOfWeek<=6

In the function main, in the for-loop, there is a loop invariant on the first line
of the body that says that the month must be less than 12.
//loop invariant: month<12 

In the function main, in the for-loop, there is a loop invariant on the last line 
of the body that says that 0 is less than or equal to the day of the week, which 
is less than or equal to 6.
//0<=dayOfWeek<=6

