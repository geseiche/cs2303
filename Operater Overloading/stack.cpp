// Grace Seiche - PA4
// queue.cpp

#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "rational.h"


//take no arguments
//constructs the head to null
Stack::Stack(){
	originalHead = NULL;
	head = NULL;
}//Stack::Stack()

//take no arguments
//destructs the elements of the stack
Stack::~Stack(){
	listItem *now = originalHead;
	//std::cout << now << std::endl;
	while(now){
		listItem *next = now->next;
		//delete now->payload;
		delete now;
		now = next;
	}
	return;
}//Stack::~Stack()

//takes no parameters
//move the head forward one rational
//return the rational reference in the old head payload
void Stack::addItem(Rational item){
	//make a list item
	listItem *toAdd = new listItem(item);
	//if head is null, make the new listItem the head
	if(head==NULL){
		head = toAdd;
		originalHead=head;
		return;
	}
	//add the listItem to the front of the stack
	else{
		toAdd->next = head;
		head = toAdd;
		originalHead = toAdd;
		return;
	}
}//void Stack::addItem(Rational item)

//takes no parameters
//return the private payload of the head
const Rational& Stack::getHead (){
	return head->payload;
}//const Rational& Stack::getHead ()

//takes no parameters
//move the head forward one rational
//return the rational reference in the old head payload
const Rational& Stack::removeHead(){
	listItem *temp = head;
	head = head->next;
	return temp->payload;
}//const Rational& Stack::removeHead()

//takes no parameters
//checks if the head is null
//returns true if there are no listItems in the stack
bool Stack::isEmptyStack (){
	//std::cout << ((head!=NULL)?"head is not null":"head is null")<< std::endl;
	if(head==NULL)
		return true;
	else
		return false;
}//bool Stack::isEmptyStack ()

//takes no parameters
//prints the rational payloads
//returns void
void Stack::printStack(){
	listItem *cursor = head;
	std::cout << cursor->payload << std::endl;
	while(cursor->next!=NULL){
		cursor=cursor->next;
		std::cout << cursor->payload << std::endl;
	}
	std::cout << std::endl;
}//void Stack::printStack()

//take no parameters
//measure the number of elements in the stack
//return the number of elements in the stack
int Stack::stackSize(){
	if(head==NULL){
		return 0;
	}
	int count = 1;
	listItem *cursor = head;
	while (cursor->next){
		count++;
		cursor=cursor->next;
	}
	return count;
}//int Stack::stackSize()
