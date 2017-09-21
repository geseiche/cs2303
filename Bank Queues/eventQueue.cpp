// Grace Seiche - PA4
// eventQueue.cpp

#include<iostream>
#include "queue.h"
#include "eventQueue.h"

extern float simulationClock;

//takes no parameters
//constructs eventQueue and uses the queue constructor
EventQueue::EventQueue() : Queue(){
}//EventQueue::EventQueue() : Queue()

//takes no parameters
//destructs the event queue
EventQueue::~EventQueue(){
}//EventQueue::~EventQueue()

//takes a pointer to an event
//inserts event into the queue based on the actionTime
//returns void
void EventQueue::addItem(Event *item){
	listItem *toAdd = new listItem(item);
	if(head==NULL){
		head = toAdd;
		return;
	}
	else{
		listItem *cursor = head;
		if(cursor->payload->getActionTime() > toAdd->payload->getActionTime()){
			toAdd->next = cursor;
			head = toAdd;
		}
		else{
			while(cursor->next && cursor->next->payload->getActionTime() < toAdd->payload->getActionTime()){
				cursor =cursor->next;
			}
			toAdd->next = cursor->next;
			cursor->next = toAdd;
		}
	}
}//void EventQueue::addItem(Event *item)

//takes no parameters
//prints the actionTime and the status of each item in the queue
//returns void
void EventQueue::printQueue(){
	listItem *cursor = head;
	std::cout << cursor->payload->getActionTime() << " " << cursor->payload->getStatus() << std::endl;
	while(cursor->next!=NULL){
		cursor=cursor->next;
		std::cout << cursor->payload->getActionTime() << " " << cursor->payload->getStatus() << std::endl;
	}
	std::cout << std::endl;
}//void EventQueue::printQueue()

//takes no parameters
//takes the head of the queue off
//updates the simulationClock
//return the event pointer of the removed head
Event *EventQueue::removeHead(){
	//std::cout << "Check" <<std::endl;
	listItem *temp = head;
	head = head->next;
	//std::cout << simulationClock << std::endl;
	simulationClock = temp->payload->getActionTime();
	//std::cout << temp->payload->getActionTime() << std::endl;
	return temp->payload;
}//Event *EventQueue::removeHead()
