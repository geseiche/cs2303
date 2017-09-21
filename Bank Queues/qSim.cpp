// Grace Seiche - PA4
// qSim.cpp

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "queue.h"
#include "eventQueue.h"
#include "customer.h"
#include "teller.h"

float simulationClock;
bool isSingleQueue;

int numCustomers;
int numTellers;
float simulationTime;
float averageServiceTime;
float seed;

EventQueue *eventQueue;

Queue *tellerQueues;

float totalServiceTime;
float totalIdleTime;
float *timeInBank;
float averageTimeInBank;
float standardDeviationTimeInBank;
float maxWaitInLineTime;
int customerCount;

//take the command line arguments
//initialize the command line arguments
//return void
void initializeCommands (int argc, char *argv[]){
	numCustomers = atoi(argv[1]);
	numTellers = atoi(argv[2]);
	simulationTime = atof(argv[3]);
	averageServiceTime = atof(argv[4]);
	if(argc==6){
		seed = atof(argv[5]);
	}
	else{
		seed = rand();
	}
}//void initializeCommands (int argc, char *argv[])

//take no parameters
//initialize the statistics to zero and make an array for timeInBank
//return void
void initializeStats (){
	totalServiceTime=0;
	totalIdleTime=0;
	timeInBank = new float [numCustomers];
	averageTimeInBank =0;
	standardDeviationTimeInBank=0;
	maxWaitInLineTime=0;
	customerCount = 0;
}//void initialStats()

//take no parameters
//initialize the event queue with customers and tellers
//initialize tellerQueues to one queue or an array of queues
//initialize simulationClock to 0
//return void
void initializeSimulation (){
	eventQueue = new EventQueue;
	for(int i=0; i<numCustomers; i++){
		eventQueue->addItem(new Customer(simulationTime, averageServiceTime));
	}
	if(isSingleQueue){

		//std::cout << eventQueue.queueSize()<<std::endl;
		//std::cout << "Check" << std::endl;
		//eventQueueTemp=eventQueue;
		tellerQueues = new Queue;
		for(int i=0; i<numTellers; i++){
			eventQueue->addItem(new Teller(tellerQueues));
		}
		//std::cout << eventQueue.queueSize()<<std::endl;
	}else{
		//eventQueue=eventQueueTemp;
		tellerQueues = new Queue [numTellers];
		for(int i=0; i<numTellers; i++){
			//tellerQueues[i] = new Queue;
			eventQueue->addItem(new Teller(&tellerQueues[i]));
			//std::cout<< &tellerQueues[i] << std::endl;
		}
	}
	simulationClock = 0;
}//void initializeSimulation()

//take no parameters
//delete all new'ed memory from the simulation
//return void
void cleanUp (){
	delete [] timeInBank;
	if(isSingleQueue){
		delete tellerQueues;
	}else{
		delete [] tellerQueues;
	}
	//EventQueue *eq = &eventQueue;
	delete eventQueue;
}//void cleanUp()

//take no parameters
//print to the console all gathered statistics
//calculate the average time in bank and the standard deviation
//return void
void printStats(){
	std::cout << "Total Customers Served: " << customerCount << std::endl;
	std::cout << "Total Service Time: " << totalServiceTime << std::endl;
	std::cout << "Number of Tellers: " << numTellers << std::endl;
	std::cout << "Queue Type: "<< (isSingleQueue ? "Single Queue" : "Multiple Queues") << std::endl;
	//calculate average
	for(int i=0; i<customerCount; i++){
		averageTimeInBank += timeInBank[i];
	}
	averageTimeInBank = averageTimeInBank/customerCount;
	std::cout << "Average Customer Time in Bank: " << averageTimeInBank << std::endl;
	//calculate standard deviation
	for(int i=0; i<customerCount; i++){
		standardDeviationTimeInBank += pow(averageTimeInBank-timeInBank[i],2);
	}
	standardDeviationTimeInBank = sqrt(standardDeviationTimeInBank/customerCount);
	std::cout << "Standard Deviation: " << standardDeviationTimeInBank << std::endl;
	std::cout << "Maximum Wait Time Before Seeing Teller: " << maxWaitInLineTime << std::endl;
	std::cout << "Total Teller Service Time: " << totalServiceTime << std::endl;
	std::cout << "Total Teller Idle Time: " << totalIdleTime << std::endl << std::endl;
}//void printStats()


//take the command line arguments
//run initializations
//take events off the event queue and perform their actions
//print the statistics
//return void
void runSimulation (int argc, char *argv[]){
	//std::cout << isSingleQueue << std::endl;
	//initializeCommands (argc, argv);
	initializeStats();
	initializeSimulation ();
	//eventQueue->printQueue();
	while(eventQueue->isEmptyQueue()==false){
		//std::cout << "Check" <<std::endl;
		//std::cout << eventQueue.queueSize() << std::endl;
		//std::cout << simulationClock << std::endl;
		//std::cout << eventQueue.getHead()<< std::endl;
		//eventQueue->printQueue();
		(eventQueue->removeHead())->action();
		//eventQueue.printQueue();
		//std::cout << eventQueue.getHead()->getActionTime() << std::endl;
	}
	//eventQueue.printQueue();
	printStats();
}//void runSimulation (int argc, char *argv[])

//take the command line arguments
//run the simulation for a single queue
//run the simulation for multiple queues
//return 1
int main (int argc, char *argv[]){
	initializeCommands(argc, argv);
	isSingleQueue = true;
	srand(seed);
	runSimulation(argc, argv);
	cleanUp();
	isSingleQueue = false;
	srand(seed);
	runSimulation(argc, argv);
	cleanUp();
	//std::cout << "finished" << std::endl;
	return 1;
}//int main (int argc, char *argv[])
