README - Grace Seiche - PA4 - Event Driven Programming

My Program

This program is designed to simulate a bank with a single queue of customers and
multiple queues of customers. The program then prints out statistics about the 
simulation in the console. This program is composed of five classes and a main 
file. Customer and Teller are two classes that inherit from event. They simulate 
the actions of the customers and tellers in a real bank. The Queue class is a
linked list that sorts first in first out, while its derived class EventQueue
sorts by actionTime of the events in the payload of the items in the queue. The
main file combines the actions of all the classes to simulate the bank and also
prints the statistics for the simulation.


To Compile, Execute the make command


To Run, Execute the following command
		./qSim #customers #tellers simulationTime averageServiceTime <seed>
where #customers is an integer number of customers to visit the bank, #tellers
is the integer number of tellers to work in the bank, simulationTime is the 
total amount of time that the simulation runs, averageServiceTime is the average
amount of time that a teller spends with a customer, and seed is an optional 
seed for the random number generator.


Problems

To the best of my knowledge, my program is accurate and fully functional. I 
struggled a lot with how to set up the project and how to cause events to happen
when they were pulled off the event queue. I also had difficulties with how
to simulate both types of queuing.


Algorithms

All algorithms in this project are my own. I did not consult any outside sources.


Conclusions
First, if information is being gathered about a bank with only one teller, there 
is no possibility of having multiple queues. Second, if there are fewer customers
than tellers, the statistics are exactly the same between a single queue style 
and a multi queue style because regardless of the style, a customer never has to 
wait in line for a teller. For most cases, the single queue had a lower average
time in bank, though there were also some cases where the multi queue had a lower
average time in bank. However, the maximum wait in line time and the standard 
deviation were always lower for the single queue than they were for the multi
queue. In my opinion, this fact is more important and a single queue is more 
efficient than a multi queue. For sample data to support my conclusions, see the
sample outputs in the next section.


Sample Output/Tests

./qSim 3 4 10 2 15

Total Customers Served: 3
Total Service Time: 6.93306
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 2.89879
Standard Deviation: 0.343105
Maximum Wait Time Before Seeing Teller: 1.3473
Total Teller Service Time: 6.93306
Total Teller Idle Time: 41.2896

Total Customers Served: 3
Total Service Time: 6.93306
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 2.89879
Standard Deviation: 0.343105
Maximum Wait Time Before Seeing Teller: 1.3473
Total Teller Service Time: 6.93306
Total Teller Idle Time: 41.2896


./qSim 3 4 10 7 15

Total Customers Served: 3
Total Service Time: 24.2657
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 9.16833
Standard Deviation: 2.59255
Maximum Wait Time Before Seeing Teller: 1.89094
Total Teller Service Time: 24.2657
Total Teller Idle Time: 34.2131

Total Customers Served: 3
Total Service Time: 24.2657
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 9.16833
Standard Deviation: 2.59255
Maximum Wait Time Before Seeing Teller: 1.89094
Total Teller Service Time: 24.2657
Total Teller Idle Time: 34.2131


./qSim 10 4 10 2 15

Total Customers Served: 10
Total Service Time: 20.3667
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 5.93859
Standard Deviation: 1.11301
Maximum Wait Time Before Seeing Teller: 5.80487
Total Teller Service Time: 20.3667
Total Teller Idle Time: 34.5707

Total Customers Served: 10
Total Service Time: 20.3667
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 6.12839
Standard Deviation: 2.83037
Maximum Wait Time Before Seeing Teller: 9.45295
Total Teller Service Time: 20.3667
Total Teller Idle Time: 34.5707


./qSim 5 4 10 2 15

Total Customers Served: 5
Total Service Time: 9.44395
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 2.31424
Standard Deviation: 0.898393
Maximum Wait Time Before Seeing Teller: 0.601172
Total Teller Service Time: 9.44395
Total Teller Idle Time: 49.1519

Total Customers Served: 5
Total Service Time: 9.44395
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 2.31424
Standard Deviation: 0.898393
Maximum Wait Time Before Seeing Teller: 0.601172
Total Teller Service Time: 9.44395
Total Teller Idle Time: 49.1519


./qSim 5 4 10 7 15

Total Customers Served: 5
Total Service Time: 33.0538
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 7.51578
Standard Deviation: 2.93505
Maximum Wait Time Before Seeing Teller: 2.15534
Total Teller Service Time: 33.0538
Total Teller Idle Time: 32.7994

Total Customers Served: 5
Total Service Time: 33.0538
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 7.58133
Standard Deviation: 3.15975
Maximum Wait Time Before Seeing Teller: 2.15534
Total Teller Service Time: 33.0538
Total Teller Idle Time: 35.6345


./qSim 50 4 10 2 15

Total Customers Served: 50
Total Service Time: 109.688
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 12.3222
Standard Deviation: 4.91527
Maximum Wait Time Before Seeing Teller: 19.853
Total Teller Service Time: 109.688
Total Teller Idle Time: 15.5163

Total Customers Served: 50
Total Service Time: 109.688
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 12.449
Standard Deviation: 5.05262
Maximum Wait Time Before Seeing Teller: 19.485
Total Teller Service Time: 109.688
Total Teller Idle Time: 15.5163


./qSim 50 4 20 2 15

Total Customers Served: 50
Total Service Time: 109.688
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 7.51841
Standard Deviation: 2.09222
Maximum Wait Time Before Seeing Teller: 9.85669
Total Teller Service Time: 109.688
Total Teller Idle Time: 15.5163

Total Customers Served: 50
Total Service Time: 109.688
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 7.39979
Standard Deviation: 2.7597
Maximum Wait Time Before Seeing Teller: 12.1195
Total Teller Service Time: 109.688
Total Teller Idle Time: 15.5163


./qSim 50 4 20 2 14

Total Customers Served: 50
Total Service Time: 98.4734
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 6.87727
Standard Deviation: 1.67685
Maximum Wait Time Before Seeing Teller: 7.8427
Total Teller Service Time: 98.4734
Total Teller Idle Time: 19.0466

Total Customers Served: 50
Total Service Time: 98.4734
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 6.64733
Standard Deviation: 2.6351
Maximum Wait Time Before Seeing Teller: 10.3068
Total Teller Service Time: 98.4734
Total Teller Idle Time: 19.0466


./qSim 100 4 10 2 15

Total Customers Served: 100
Total Service Time: 211.189
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 27.5142
Standard Deviation: 11.9105
Maximum Wait Time Before Seeing Teller: 46.8095
Total Teller Service Time: 211.189
Total Teller Idle Time: 21.8672

Total Customers Served: 100
Total Service Time: 211.189
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 27.6044
Standard Deviation: 12.0733
Maximum Wait Time Before Seeing Teller: 46.4534
Total Teller Service Time: 211.189
Total Teller Idle Time: 21.8672


./qSim 500 4 100 2 15

Total Customers Served: 500
Total Service Time: 1028.14
Number of Tellers: 4
Queue Type: Single Queue
Average Customer Time in Bank: 83.9
Standard Deviation: 46.223
Maximum Wait Time Before Seeing Teller: 160.311
Total Teller Service Time: 1028.14
Total Teller Idle Time: 17.2109

Total Customers Served: 500
Total Service Time: 1028.14
Number of Tellers: 4
Queue Type: Multiple Queues
Average Customer Time in Bank: 83.4722
Standard Deviation: 46.4974
Maximum Wait Time Before Seeing Teller: 162.004
Total Teller Service Time: 1028.14
Total Teller Idle Time: 17.2109


