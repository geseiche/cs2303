README - Grace Seiche - PA3 - Binary Trees

My Program

This program is designed to scan through a file, organize the words into a binary tree, 
and return an alphabetical list of all words in the file and their frequencies. The 
return is stored in an output file specified by the user. My program is organized into
three c files: binaryTree.c, handleFile.c, and PA3.c. binaryTree.c contains methods for
adding an item to a tree, printing the tree, and freeing the memory allocated to the 
tree. handleFile.c contains the methods to strip a string of extraneous characters, 
building a tree from a file, and sending the tree and sumative information to the 
output file. PA3.c contains the main method for to run the program. 
Note: In this project, a number with a comma is treated as one word. 


To Compile, Execute the make command


To Run, Execute the following command
		./PA3 outputFile inputFile1 inputFile2 . . . 
where outputFile is the file written with the program output and the inputFiles are the
files of text to be read, organized, and alphabetized


Problems

To the best of my knowledge, my program is accurate and fully functional. I struggled a
lot with reading from the file figuring out how to allocate memory for the strings of
unknown length.


Algorithms

All algorithms in this project are my own, with the exception of the function addItem
located in binaryTree.c. This function was taken directly from the project instruction
powerpoint shown in class. It is a recursive function that takes a pointer to a tree 
and a pointer to a character array. If the tree pointer is null, it creates a node in
that spot with the word pointed to. If the given word is equal to the word in the given
node, it simply increases the count on the word. Otherwise, it adds a node with the 
word to either the left or right  node depending on whether the word is less than or 
greater than the word in the given node, respectively.


Sample Output

In addition to the test cases provided, I tested my program against Martin Luther King's
I Have a Dream speech and Roosevelt's first Fireside Chat. The sample texts and outputs
are included in my program files as King.txt, KingOutput.txt, Roosevelt.txt, and
RooseveltOutput.txt