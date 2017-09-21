# Grace Seiche - PA4
# makefile

CFLAGS = -Wall -g

qSim: customer.o event.o eventQueue.o qSim.o queue.o teller.o
	g++ $(CFLAGS) -o qSim customer.o event.o eventQueue.o qSim.o queue.o teller.o
		
customer.o: customer.cpp customer.h event.h queue.h eventQueue.h
	g++ $(CFLAGS) -c customer.cpp

event.o: event.cpp event.h teller.h customer.h
	g++ $(CFLAGS) -c event.cpp
	
eventQueue.o: eventQueue.cpp eventQueue.h queue.h
	g++ $(CFLAGS) -c eventQueue.cpp

qSim.o: qSim.cpp customer.h event.h eventQueue.h queue.h teller.h
	g++ $(CFLAGS) -c qSim.cpp
	
queue.o: queue.cpp queue.h
	g++ $(CFLAGS) -c queue.cpp
	
teller.o: teller.cpp teller.h event.h queue.h customer.h eventQueue.h
	g++ $(CFLAGS) -c teller.cpp

clean:
	rm -f *.o qSim
	
all: qSim

