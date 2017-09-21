Grace Seiche - PA5 - Rational Class

My Program

This program is designed to overload operators for use on rational objects both
of which are located in the rational class. The program also comes with a 
rudimentary  test program that reads rational expressions from a file and 
evaluates them to either a rational, a boolean, or an error message. This 
information is then printed out to the console. The files are text files taken 
in as command line arguments. The expressions are all written in post fix. In 
addition to the test program and the rational class, there is a stack class used 
to implement the stack where the scanned rationals are being stored.


To Compile, Execute the make command


To Run, Execute the following command
		./PA5 inputFile1 inputFile2 . . .
where all arguments after the call are names of files containing input lines to 
be evaluated by the test program. There can be a variable number of files, but 
there must be at least one.


Problems

To the best of my knowledge, my program is accurate and fully functional. I 
struggled a lot with writing the test program, especially reading in the lines
from the files. I also had difficulties with overloading >> and deciding how to
handle the various different ways that someone can input something.


Algorithms

All algorithms in this project are my own. I did not consult any outside sources.


Testing

To test the accuracy of the overloaded operators, I used the test program and file.
To the best of my knowledge, all of the overloaded operators are working. My 
testing first begins with various examples of improper syntax, whether it be from
too many rational arguments, too many operator arguments, dividing by zero, adding
extraneous symbols, operating on a boolean, etc. From there, I test each of my
comparison operators four or five times. Then I test each of my arithmetic 
operations four or five times. I tried to include varied denominators as well as 
edge cases in my testing. I also used many non-normalized rationals to show the 
program's ability to normalize rationals. Finally, I added three lines where multiple
operators are used to show that the test program can handle more complex expressions.


Output for Test File

geseiche_tests.txt
2/4 1/3 2/6 == *	: invalid expression
4/1 0/6 /	: invalid expression
1/3 1/3 1/2 * + -	: invalid expression
1/4 1/5 1/3 *	: invalid expression
1/ 2/3 +	: invalid expression
1$ 4/3 /	: invalid expression
1/3 *	: invalid expression
3/4 6/7 !	: invalid expression
5/4 8/7 =	: invalid expression
1 2 >*	: invalid expression
4 5 <*	: invalid expression
8 9 *<	: invalid expression
3 6*	: 18/1 (double 18)
1/2 1/2 ==	: true
1/2 -1/2 ==	: false
3/6 1/2 ==	: true
111/110 112/110 ==	: false
1/17 1/2 !=	: true
5/10 6/12 !=	: false
1/17 1/17 !=	: false
222/221 223/221 !=	: true
1 3/4 <	: false
10/-19 11/20 <	: true
7/9 22/27 <	: true
1/38 -1/38 <	: false
6/10 3/5 <	: false
14/21 8/-10 <=	: false
3/15 1/5 <=	: true
17/29 20/21 <=	: true
11/7 24/-12 <=	: false
23/17 7/19 >	: true
11/9 10/30 >	: true
17/8 34/16 >	: false
6/15 22/2 >	: false
3/5 18/30 >=	: true
-16/9 -10/4 >=	: true
29/-5 25/28 >=	: false
-6/8 -6/28 >=	: false
0/-10 -18/-20 +	: 9/10 (double 0.9)
2/-4 9/2 +	: 4/1 (double 4)
-20/-12 6/15 +	: 31/15 (double 2.06667)
25/26 17/-15 +	: -67/390 (double -0.171795)
1/-19 5/28 -	: -123/532 (double -0.231203)
3/-15 -14/9 -	: 61/45 (double 1.35556)
27/12 -5/-14 -	: 53/28 (double 1.89286)
4/-2 29/-16 -	: -3/16 (double -0.1875)
16/3 11/27 *	: 176/81 (double 2.17284)
29/29 18/-19 *	: -18/19 (double -0.947368)
19/3 8/-6 *	: -76/9 (double -8.44444)
19/-4 -14/22 *	: 133/44 (double 3.02273)
15/6 -17/9 /	: -45/34 (double -1.32353)
11/24 -15/-3 /	: 11/120 (double 0.0916667)
-8/-19 10/-16 /	: -64/95 (double -0.673684)
0/-3 -3/-7 /	: 0/1 (double 0)
1/3 1/6 1/12 - /	: 4/1 (double 4)
1/2 1/4 3/4 * >	: true
5/4 1/4 - 5/8 3/8 + *	: 1/1 (double 1)