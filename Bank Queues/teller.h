// Grace Seiche - PA4
// teller.h

#include <iostream>
#include "event.h"
#include "queue.h"
#include "customer.h"

class Teller : public Event{

public:

	//takes no parameters
	//returns the instance idleTime
	float getIdleTime();

	//takes no parameters
	//given the status, decides which actions to take
	//returns void
	void action();

	//takes no parameters
	//returns teller point of the instance tellerQueue
	Queue *getQueue();

	//takes no parameters
	//for a single queue, takes the first customer off the queue or null
	//for a multi queue, take the first customer for personal queue or a random other queue
	//returns a pointer to the customer
	Event *getNextCustomer();

	//takes a pointer to a queue
	//passes IDLE to the event constructor
	//constructs idleTime to a random value and tellerQueue to the give queue
	Teller(Queue *myQueue);

	//takes no parameters
	//destructs Teller
	~Teller();

private:
	//private instance variables
	float idleTime;
	Queue *tellerQueue;
};
