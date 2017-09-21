// Grace Seiche - PA4
// event.cpp

#include <iostream>
#include "event.h"
#include "teller.h"
#include "customer.h"

//takes an int status
//constructs the status and the actionTime to 0
Event::Event(int statu){
	status = statu;
	actionTime = 0;
}//Event::Event(int statu)

//takes no parameters
//destructs the event
Event::~Event(){
}//Event::~Event()

//takes no parameters
//returns the private instance variable status
int Event::getStatus(){
	return status;
}//int Event::getStatus()

//takes an int status
//sets the internal status equal to the parameter status
//returns void
void Event::setStatus(int statu){
	status = statu;
}//void Event::setStatus(int statu)

//takes no parameters
//returns the private instance variable actionTime
float Event::getActionTime(){
	return actionTime;
}//float Event::getActionTime()

//takes a float time
//sets the intenal status equal to time
//returns void
void Event::setActionTime(float time){
	actionTime = time;
}//void Event::setActionTime(float time)

