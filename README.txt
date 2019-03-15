Name: Bob Ghosh; CS id: j0k0b; Student#: 42039157
Partner: Chen Gang (Michael) Zhang; CS id: o7h0b; Student#: 27044156  

List of files submitted:
*LQueue.C -> Source Code for LQueue containing the implementaion of all the methods in the LQueue Header File.
*LQueue.h -> A header file for Queue containing the declaration of the methods.
*LQueue_driver.C -> The main/driver C file for LQueue to simulate Queues and their functions.
*LQueue_driver Output.txt -> A text file containing the output of the LQueue_driver file.
*README.txt -> A text contaning these information and our(Programmers') names.
*runway.C -> A C file simulating a situation in 2 Runways. 
*Runway.h -> A header file containing all the necessary methods and definition for the runway file.
*runway Output.txt -> A text file containing the output of the runway file. 

In making this program, we assume that:
 1) For the simulation, there was a technical issue at some point (defined) in the second runway and thus all the queue of
    flights that are landing and taking off are merged with the runway 1. There's also a need for emergency landing of flight
	1002, and was given the priority after the recent takeoff.
 2) We didn't use makefile for compiling runway, instead we used g++ -Wall -g runway.C Runway.h LQueue.h LQueue.o -o runway 