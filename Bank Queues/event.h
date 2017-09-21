// Grace Seiche - PA4
// event.h

#ifndef EVENT_H
#define EVENT_H

#include <iostream>

enum STATES {PRE_ARRIVAL, IN_LINE, WITH_TELLER, IDLE, WITH_CUSTOMER, DONE};

class Event {

public:

	//takes an int status
	//sets the internal status equal to the parameter status
	//returns void
	void setStatus (int statu);

	//takes no parameters
	//returns the private instance variable status
	int getStatus ();

	//takes a float time
	//sets the intenal status equal to time
	//returns void
	void setActionTime(float time);

	//takes no parameters
	//returns the private instance variable actionTime
	float getActionTime();

	//takes no parameters
	//use the status to perform the next actions
	//return no parameters
	virtual void action () = 0;

	//takes an int status
	//constructs the status and the actionTime to 0
	Event(int statu);

	//takes no parameters
	//destructs the event
	virtual ~Event();

protected:

	//protected instance variables
	int status;
	float actionTime;
};

#endif
