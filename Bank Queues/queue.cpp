// Grace Seiche - PA4
// queue.cpp

#include <iostream>
#include <cstdlib>
#include "event.h"
#include "queue.h"
//extern float simulationClock;

//take no arguments
//constructs the head to null
Queue::Queue(){
	originalHead = NULL;
	head = NULL;
}//Queue::Queue()

//take no arguments
//destructs the elements of the queue
Queue::~Queue(){
	listItem *now = originalHead;
	//std::cout << now << std::endl;
	while(now){
		listItem *next = now->next;
		//delete now->payload;
		delete now;
		now = next;
	}
	return;
}//Queue::~Queue()

//takes a pointer to an event
//builds a listItem and adds it to the end of the queue
//return void
void Queue::addItem(Event *item){
	//make a list item
	listItem *toAdd = new listItem(item);
	//if head is null, make the new listItem the head
	if(head==NULL){
		head = toAdd;
		originalHead=head;
		return;
	}
	//add the listItem to the end of the queue
	else{
		listItem *cursor = head;
		while((cursor->next)!=NULL)
			cursor = cursor->next;
		cursor->next = toAdd;
	}
}////void Queue::addItem(Event *item)

//takes no parameters
//return the private payload of the head
Event *Queue::getHead (){
	return head->payload;
}//Event *Queue::getHead()

//takes no parameters
//move the head forward one event
//return the event pointer in the old head payload
Event *Queue::removeHead(){
	listItem *temp = head;
	head = head->next;
	//std::cout << simulationClock << std::endl;
	//simulationClock = temp->payload->getActionTime();
	//std::cout << temp->payload->getActionTime() << std::endl;
	//std::cout << "Check" <<std::endl;
	return temp->payload;
}//Event *Queue::removeHead()

//takes no parameters
//checks if the head is null
//returns true if there are no listItems in the queue
bool Queue::isEmptyQueue (){
	//std::cout << ((head!=NULL)?"head is not null":"head is null")<< std::endl;
	if(head==NULL)
		return true;
	else
		return false;
}//bool Queue::isEmptyQueue()

//takes no parameters
//prints the address of the queue and the action times and statuses of all events in the queue
//returns void
void Queue::printQueue(){
	std::cout << this << std::endl;
	listItem *cursor = head;
	std::cout << cursor->payload->getActionTime() << " " << cursor->payload->getStatus() << std::endl;
	while(cursor->next!=NULL){
		cursor=cursor->next;
		std::cout << cursor->payload->getActionTime() << " " << cursor->payload->getStatus() << std::endl;
	}
	std::cout << std::endl;
}//void Queue::printQueue()

//take no parameters
//measure the number of elements in the queue
//return the number of elements in the queue
int Queue::queueSize(){
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
}//int Queue::queueSize()
