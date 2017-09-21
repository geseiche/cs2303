// Grace Seiche - PA4
// customer.h

#include <iostream>
#include <cstdlib>
#include "event.h"
#include "customer.h"
#include "queue.h"
#include "eventQueue.h"
extern int numTellers;
extern Queue *tellerQueues;
extern float simulationClock;
extern EventQueue *eventQueue;
extern bool isSingleQueue;
extern float totalServiceTime;
extern int customerCount;
extern float *timeInBank;
extern float maxWaitInLineTime;


//takes the simulationTime and the averageServiceTime floats
//passes PRE_ARRIVAL to the event constructor
//initializes the arrivalTime, actionTime, and serviceTime
Customer::Customer(float simulationTime, float averageServiceTime) : Event(PRE_ARRIVAL){
	arrivalTime = simulationTime*(rand()/float(RAND_MAX));
	actionTime = arrivalTime;
	serviceTime = 2*averageServiceTime*(rand()/float(RAND_MAX));
}//Customer::Customer(float simulationTime, float averageServiceTime) : Event(PRE_ARRIVAL)

//takes no arguments
//destructs the customer
Customer::~Customer(){
}//Customer::~Customer()

//takes no arguments
//returns the instance serviceTime
float Customer::getServiceTime(){
	return serviceTime;
}//float Customer::getServiceTime()

//takes no arguments
//puts the time in bank into a storage array
//increases the customerCount
void Customer::printStats(){
	//std::cout << simulationClock << "\t" << (customerCount +1) << std::endl;
	timeInBank[customerCount] = simulationClock - arrivalTime;
	customerCount++;
}//void Customer::printStats()

//takes no arguments
//for a single queue, add the customer to the queue
//for a multi queue, choose a queue with the shortest line
//return void
void Customer::addToTellerQueue(){
	if(isSingleQueue){
		tellerQueues->addItem(this);
		//tellerQueues->printQueue();
	} else{
		int shortest = -1;
		int length = RAND_MAX;
		for(int i=0; i<numTellers; i++){
			if(tellerQueues[i].queueSize()==length && (rand()/float(RAND_MAX))>=.75){
				length = tellerQueues[i].queueSize();
				shortest = i;
			}
			if(tellerQueues[i].queueSize()<length){
				length = tellerQueues[i].queueSize();
				shortest = i;
			}
		}
		//std::cout << shortest << std::endl;
		tellerQueues[shortest].addItem(this);
		//tellerQueues[shortest].printQueue();
	}
}//void Customer::addToTellerQueue()

//takes no parameters
//given the status, decides which actions to take
//returns void
void Customer::action(){
	//std::cout << "check" <<std::endl;
	switch(status){
	case PRE_ARRIVAL :
		//std::cout << "before" << std::endl;
		addToTellerQueue();
		//std::cout << "after" << std::endl;
		setStatus(IN_LINE);
		break;
	case IN_LINE :
		setActionTime(simulationClock+serviceTime);
		totalServiceTime += serviceTime;
		//std::cout << simulationClock << "\t" << arrivalTime << std::endl;
		if(maxWaitInLineTime<(simulationClock - arrivalTime)){
			maxWaitInLineTime = simulationClock - arrivalTime;
		}
		setStatus(WITH_TELLER);
		eventQueue->addItem(this);
		break;
	case WITH_TELLER :
		printStats();
		delete this;
		break;
	}
}//void Customer::action()
