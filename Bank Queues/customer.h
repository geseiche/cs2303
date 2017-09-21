// Grace Seiche - PA4
// customer.h

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include "event.h"

class Customer : public Event{

public:

	//takes no arguments
	//returns the instance serviceTime
	float getServiceTime();

	//takes no arguments
	//puts the time in bank into a storage array
	//increases the customerCount
	void printStats();

	//takes no arguments
	//for a single queue, add the customer to the queue
	//for a multi queue, choose a queue with the shortest line
	//return void
	void addToTellerQueue();

	//takes no parameters
	//given the status, decides which actions to take
	//returns void
	void action ();

	//takes the simulationTime and the averageServiceTime floats
	//passes PRE_ARRIVAL to the event constructor
	//initializes the arrivalTime, actionTime, and serviceTime
	Customer(float simulationTime, float averageServiceTime);

	//takes no arguments
	//destructs the customer
	~Customer();

private:
	//private instance variables
	float arrivalTime;
	float serviceTime;

};

#endif
