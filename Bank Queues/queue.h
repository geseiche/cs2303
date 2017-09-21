// Grace Seiche - PA4
// queue.h

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "event.h"

class Queue {

public:

	//takes a pointer to an event
	//builds a listItem and adds it to the end of the queue
	//return void
	void addItem (Event *item);

	//takes no parameters
	//return the private payload of the head
	Event *getHead ();

	//takes no parameters
	//move the head forward one event
	//return the event pointer in the old head payload
	Event *removeHead();

	//takes no parameters
	//checks if the head is null
	//returns true if there are no listItems in the queue
	bool isEmptyQueue ();

	//takes no parameters
	//prints the address of the queue and the action times and statuses of all events in the queue
	//returns void
	void printQueue();

	//take no parameters
	//measure the number of elements in the queue
	//return the number of elements in the queue
	int queueSize ();

	//take no arguments
	//constructs the head to null
	Queue ();

	//take no arguments
	//destructs the elements of the queue
	~Queue ();

protected:

	//contains a value and a pointer to the next listItem
	class listItem;

	//pointer to the next item in the queue
	listItem *head;

	listItem *originalHead;

	//protected inner class
	//contains an event pointer payload and a pointer to the next value
	class listItem {
	public:
		Event *payload;
		listItem *next;

		//constructs the payload to the given event and the next pointer to NULL
		listItem(Event *event) : payload(event), next(NULL){	};
	};
};

#endif
