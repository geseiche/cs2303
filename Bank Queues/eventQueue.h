// Grace Seiche - PA4
// eventQueue.h

#include<iostream>
#include "queue.h"

class EventQueue : public Queue {

public:

	//takes a pointer to an event
	//inserts event into the queue based on the actionTime
	//returns void
	void addItem (Event *item);

	//takes no parameters
	//prints the actionTime and the status of each item in the queue
	//returns void
	void printQueue ();

	//takes no parameters
	//takes the head of the queue off
	//updates the simulationClock
	//return the event pointer of the removed head
	Event *removeHead ();

	//takes no parameters
	//constructs eventQueue and uses the queue constructor
	EventQueue();

	//takes no parameters
	//destructs the event queue
	~EventQueue();
};
