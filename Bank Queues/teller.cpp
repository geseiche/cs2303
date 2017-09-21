// Grace Seiche - PA4
// teller.h

#include <iostream>
#include <cstdlib>
#include "event.h"
#include "teller.h"
#include "queue.h"
#include "eventQueue.h"
extern Queue *tellerQueues;
extern int numTellers;
extern float simulationClock;
extern EventQueue *eventQueue;
extern float simulationTime;
extern bool isSingleQueue;
extern float totalIdleTime;

//takes a pointer to a queue
//passes IDLE to the event constructor
//constructs idleTime to a random value and tellerQueue to the give queue
Teller::Teller(Queue *myQueue) : Event(IDLE){
	idleTime = 10*(rand()/float(RAND_MAX));
	tellerQueue = myQueue;
}//Teller::Teller(Queue *myQueue)

//takes no parameters
//destructs Teller
Teller::~Teller(){
}//Teller::~Teller()

//takes no parameters
//returns the instance idleTime
float Teller::getIdleTime(){
	return idleTime;
}//float Teller::getIdleTime()

//takes no parameters
//given the status, decides which actions to take
//returns void
void Teller::action(){
	//std::cout << "check" <<std::endl;
	switch(status){
	case IDLE : case WITH_CUSTOMER :
		//std::cout << status << std::endl;
		Customer *nextCustomer = (Customer*)getNextCustomer();
		if(nextCustomer){
			setActionTime(simulationClock+nextCustomer->getServiceTime());
			nextCustomer->action();
			setStatus(WITH_CUSTOMER);
			eventQueue->addItem(this);
		}
		else{
			if(simulationClock>=simulationTime){
				delete this;
			}
			else{
				setActionTime(simulationClock+idleTime);
				totalIdleTime += idleTime;
				eventQueue->addItem(this);
			}
		}
		break;
	}
}//void Teller::action()

//takes no parameters
//returns teller point of the instance tellerQueue
Queue *Teller::getQueue(){
	return tellerQueue;
}//Queue *Teller::getQueue()

//takes no parameters
//for a single queue, takes the first customer off the queue or null
//for a multi queue, take the first customer for personal queue or a random other queue
//returns a pointer to the customer
Event *Teller::getNextCustomer(){
	if(isSingleQueue){
		if(getQueue()->isEmptyQueue()){
			return NULL;
		}
		else{
			//getQueue()->printQueue();
			return getQueue()->removeHead();
		}
	}else{
		if(getQueue()->isEmptyQueue()){
			int start = numTellers*rand()/float(RAND_MAX);
			int i = start;
			do{
				if(tellerQueues[i].isEmptyQueue()){
					i++;
					i=i%numTellers;
				}
				else{
					//tellerQueues[i].printQueue();
					return tellerQueues[i].removeHead();
				}
			} while (i!=start);
			return NULL;
		}
		else{
			//getQueue()->printQueue();
			return getQueue()->removeHead();
		}
	}
}//Event *Teller::getNextCustomer()
