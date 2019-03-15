#include<iostream>
#include"LQueue.h"

class Runway{
	
	int f_no,lQueue,tQueue,maxl,maxt;
	bool isfree;                          //attributes
	Queue l,t;
	
	public:
	Runway(){
		isfree = true;
		f_no = 1000;
		lQueue = 0;                     //constructor
		tQueue = 0;
		maxl = 0;
		maxt = 0;
	}
	
	private:
	void land(int no){
		maxl++;
		l.enqueue(no);
		cout<<"\nPlane "<<no<<" wants to land; added to landing queue: ";              //wants to land, go to the method
		lQueue++;
		cout<<lQueue<<" in queue"<<endl;
	}
	
	void takeoff(int no){
		maxt++;
		t.enqueue(no);  
		cout<<"\nPlane "<<no<<" wants to takeoff; added to takeoff queue: ";          //wants to take off, go to the method
		tQueue++;
		cout<<tQueue<<" in queue"<<endl;
	}
	
	public:
	void ready(double x, double y, int landingRate, int takeoffRate){
		double a = landingRate/60.0;
		double b = takeoffRate/60.0;                                                 //checks for takeoff and landing requests
		f_no++;
		if(a<x)
			land(f_no);
		if(b<y)
			takeoff(f_no);
	}
	int getf_no(){
		return f_no;
	}
	
	bool getRunway(){
		return isfree;
	}
	
	void setRunway(bool x){
		isfree = x;
	}
	
	int getLengthLanding(){
		return lQueue;
	}
	
	int getLengthTakeoff(){
		return tQueue;
	}
	
	void doLanding(){
		cout<<"Landing Flight: ";
        cout<<l.front()<<"\n";                                          //method for landing
		lQueue--;
		l.dequeue();
	}
	
	void doTakeoff(){
		cout<<"Taking off Flight: ";
        cout<<t.front()<<"\n";                                          //method for taking off
		tQueue--;
		t.dequeue();
	}
	
	Queue getLQueue(){
		return l;
	}
	
	Queue getTQueue(){
		return t;
	}
	
	int getMaxL(){
		return maxl;
	}
	
	int getMaxT(){
		return maxt;
	}
	
	double getAvgTimeLand(int time){
		return (double)time/maxl;
	}
	
	double getAvgTimeTakeoff(int time){
		return (double)time/maxt;
	}
	
	void merge(Runway r){
		Queue temp = r.getLQueue();
		l.merge_two_queues(temp);
		lQueue += r.getLengthLanding();                             //merge two runways using the LQueue merge_two_queues
		maxl += r.getMaxL();
		temp = r.getTQueue();
		t.merge_two_queues(temp);
		tQueue += r.getLengthTakeoff();
		maxt += r.getMaxT();
		r.setRunway(true);
	}
	
	void move_to_front(int no, int val){
		if(val == 0)
			l.move_to_front(no);                                  //move_to_front for emergency landing and takeoff
		if(val == 1)                                              // 0 for landing and 1 for takeoff
			t.move_to_front(no);
	}
};