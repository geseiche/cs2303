// Grace Seiche - PA5 - stack.h

#include <iostream>
#include "rational.h"

class Stack {

public:

	//takes a reference to a rational
	//builds a listItem and adds it to the top of the stack
	//return void
	void addItem (Rational item);

	//takes no parameters
	//return the private payload of the head
	const Rational& getHead ();

	//takes no parameters
	//move the head forward one rational
	//return the rational reference in the old head payload
	const Rational& removeHead();

	//takes no parameters
	//checks if the head is null
	//returns true if there are no listItems in the stack
	bool isEmptyStack ();

	//takes no parameters
	//prints the rational payloads
	//returns void
	void printStack();

	//take no parameters
	//measure the number of elements in the stack
	//return the number of elements in the stack
	int stackSize ();

	//take no arguments
	//constructs the head to null
	Stack ();

	//take no arguments
	//destructs the elements of the stack
	~Stack ();

protected:

	//contains a value and a pointer to the next listItem
	class listItem;

	//pointer to the next item in the queue
	listItem *head;

	listItem *originalHead;

	//protected inner class
	//contains a rational reference payload and a pointer to the next value
	class listItem {
	public:
		Rational payload;
		listItem *next;

		//constructs the payload to the given rational and the next pointer to NULL
		listItem(Rational r) : payload(r), next(NULL){	};
	};
};

