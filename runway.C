#include<iostream>
#include"Runway.h"
#include<cstdlib>
#include<ctime>

using namespace std;
int main(void){
	int Time, time_counter = 1, takeofftime, landtime, lrate, trate, swap = 0;
	Runway r1,r2;
	double x,y;
	bool landed = false, tookoff = false, flag = false;
	
	cout<<"Enter :";	//UI
    cout<<"\nTime for a plane to land (in minutes): ";
    cin>>landtime;
    cout<<"Time for a plane to takeOff (in minutes) : ";
    cin>>takeofftime;
    cout<<"Landing rate (planes per hour) : ";
    cin>>lrate;
    cout<<"TakeOff rate (planes per hour) : ";
    cin>>trate;
    cout<<"How long to run the simulation (in minutes) : ";
    cin>>Time;
	
	srand(time(NULL));
	
	while(time_counter<=Time){
		x = (double)((rand()%60 + 1))/100.0;	         //random value for x
        y = (double)((rand()%60 + 1))/100.0;
		cout<<"\nTime: "<<++time_counter-1<<endl;		//random value for y
		
		if(time_counter % 2 == 0)
			r1.ready(x,y,lrate,trate);
		else
			r2.ready(x,y,lrate,trate);
		
		if(time_counter==(Time-5)){
			cout<<"\n\n***Due to some technical issues, the Runway 2 has been shut down temporarily***"<<endl;
			r1.merge(r2);
			cout<<"***All flights leaving from or coming to Runway 2 have been moved to Runway 1***"<<endl;         
			cout<<"Total Number of Flights Now Leaving Runway 1 is: "<<r1.getLengthLanding()<<endl;               //A simulation of a non-functional runway to test
			cout<<"Total Number of Flights Now Arriving Runway 1 is: "<<r1.getLengthTakeoff()<<endl;              //the merge() method. 
			cout<<"Is Runway 2 Free: "<<boolalpha<<r2.getRunway()<<endl;
		}
		
		if(time_counter==(6)){
			cout<<"\n***The flight "<<1002<<" needs to land immediately due to an emergency!***\n";       //A simulation of emergency landing
			r1.move_to_front(1002,0);
		}
			
			if(flag)		//check  if the flight has landed/taken off
        {
           if(swap-1 > 0)
              swap--;
           else
              {
			 if(tookoff)
                {
                   cout<<"TakeOff complete; ";
                   cout<<r1.getLengthTakeoff();                 //when takesoff
                   cout<<" in queue\n";
                   tookoff = false;
                }
                if(landed)
                {
                   cout<<"Landing complete; ";
                   cout<<r1.getLengthLanding();                 //when lands
                   cout<<" in queue\n";
                   landed = false;
                }
               
                swap = 0;
                flag = false;
                r1.setRunway(true);	//Runway is freed 
              }
        }
        else if(r1.getRunway())
        {
           if(r1.getLengthLanding() != 0)
                {			                                  //Lands next flight 
                    landed = true;
                    r1.doLanding();
                    r1.setRunway(false);
                    flag = true;	
                    swap = landtime;
                }
           else if(r1.getLengthTakeoff() != 0)
                {			                                  //Departs next flight
                    tookoff = true;
                    r1.doTakeoff();
                    r1.setRunway(false);
                    flag = true;
                    swap = takeofftime;
                }			
				
				}
    } 

	cout<<"\nNo new landings or takeoffs will be generated!\n";	
	
	   int alpha = r1.getLengthLanding(), beta = r1.getLengthTakeoff(); 
	   
	   while(alpha >= 0)
    {
        cout<<"\nTime: "<<++time_counter-1<<endl;
        if(r1.getRunway())
        {
           r1.doLanding();
           r1.setRunway(false);
           swap = landtime;		//Set runway to false
           }
        else        
        {
           if(swap-1 > 0)
              swap--;
           else
              {
                cout<<"Landing complete; ";
                cout<<alpha;
                cout<<" in queue\n";		//Flights have landed 
                alpha--;
                swap = 0;
                r1.setRunway(true);
              }
         }
         
     }

     
		flag = false;
		r1.setRunway(true);
		swap = 0;
     

		
		while(beta > 0)
    {				
        cout<<"\nTime: "<<++time_counter-1<<endl;
        if(r1.getRunway())
        {
           r1.doTakeoff();
           r1.setRunway(false);      //Set runway to false
           swap = takeofftime;
           }
        else        
        {
           if(swap-1 > 0)
              swap--;
           else
              {
                cout<<"TakeOff complete; ";
                cout<<beta-1;
                cout<<" in queue\n";                    //Flights have taken off
                beta--;
                swap = 0;
                r1.setRunway(true);
              }
         }
         
     }
	
	cout<<"\nSTATISTICS\n";
	cout<<"\nMaximum number of planes in landing queue was: "<<r1.getMaxL();
	cout<<"\nAverage minutes spent waiting to land: "<<r1.getAvgTimeLand(time_counter);
	cout<<"\nMaximum number of planes in takeoff queue was: "<<r1.getMaxT();                                //Summary of the flights in the Queues
	cout<<"\nAverage minutes spent waiting to takeoff: "<<r1.getAvgTimeTakeoff(time_counter)<<endl;
	cout<<"End of program."<<endl;
	return 0;
}