/*---------------------------------------------------------------------
                  Driver program to test the Queue class.
  ----------------------------------------------------------------------*/

#include <iostream>
#include "LQueue.h"
using namespace std;
	

void print(Queue q)
{ q.display(cout); }

int main(void)
{
   Queue q1;
   cout << "Queue created.  Empty? " << boolalpha << q1.empty() << endl;

   cout << "How many elements to add to the queue? ";
   int numItems;
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q1.enqueue(100*i);

   cout << "Contents of queue q1 (via  print):\n";
   print(q1); 
   cout << endl;

   Queue q2;
   q2 = q1;
   cout << "Contents of queue q2 after q2 = q1 (via  print):\n";
   print(q2); 
   cout << endl;

   cout << "Queue q2 empty? " << q2.empty() << endl;

   cout << "Front value in q2: " << q2.front() << endl;

   while (!q2.empty())
   {
     cout << "Remove front -- Queue contents: ";
     q2.dequeue();
     q2.display(cout);
   }
   cout << "Queue q2 empty? " << q2.empty() << endl;
   cout << "Front value in q2?" << endl << q2.front() << endl;
   cout << "Trying to remove front of q2: " << endl;
   q2.dequeue();

   cout << "q1:\t";
   print(q1); 
  
   cout << "\nHow many elements to add to the queue q2? ";
   cin >> numItems;
   for (int i = 1; i <= numItems; i++) 
      q2.enqueue(50*i);

   cout << "q2:\t";
   print(q2);
   cout<<endl;   

   Queue r1 = q1;
   Queue r2 = q2;
   
   
   cout<<"What number do you want to move in front of the queue q1? q1: ";
   print(q1);
   int x;
   cin>>x;
   q1.move_to_front(x);
   cout<<"\nContents of q1 before move_to_front (the number is "<< x <<") :\n";
   print(r1);
   cout<<endl;
   cout<<"Contents of q1 after move_to_front (the number is "<< x <<") :\n";
   print(q1);
   cout<<endl;
   
   cout<<"What number do you want to move in front of the queue q2? q2: ";
   print(q2);
   int y;
   cin>>y;
   q2.move_to_front(y);
   cout<<"\nContents of q2 before move_to_front (the number is "<< y <<") :\n";
   print(r2);
   cout<<endl;
   cout<<"Contents of q2 after move_to_front (the number is "<< y <<") :\n";
   print(q2);
   cout<<endl;
   
   cout<<"Sorting q1 back to original:\n";
   q1 = r1;
   print (q1);
   cout<<endl;
   
   cout<<"Sorting q2 back to original:\n";
   q2 = r2;
   print (q2);
   cout<<endl;
   
   q1.merge_two_queues(q2);
   cout<<"Contents of q1 after merge_two_queues:\n";
   print(q1);
   cout<<endl;
   cout << "Queue q2 empty after merge_two_queues? " << q2.empty() << endl;
   return 0;
}
