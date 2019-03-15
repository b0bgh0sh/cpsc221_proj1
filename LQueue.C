/*--- LQueue.cpp ----------------------------------------------------------
  This file implements LQueue member functions.
  From:  "ADTs, Data Structures, and Problem Solving with C++", 2nd edition
         by Larry Nyhoff
-------------------------------------------------------------------------*/

#include <iostream>
using namespace std;

#include "LQueue.h"

//--- Definition of Queue constructor
Queue::Queue()
: myFront(0), myBack(0)
{}

//--- Definition of Queue copy constructor
Queue::Queue(const Queue & original)
{
   myFront = myBack = 0;
   if (!original.empty())
   {
      // Copy first node
      myFront = myBack = new Queue::Node(original.front());

      // Set pointer to run through original's linked list
      Queue::NodePointer origPtr = original.myFront->next;
      while (origPtr != 0)
      {
         myBack->next = new Queue::Node(origPtr->data);
         myBack = myBack->next;
         origPtr = origPtr->next;
      }
   }
}

//--- Definition of Queue destructor
Queue::~Queue()
{
  // Set pointer to run through the queue
  Queue::NodePointer prev = myFront,
                     ptr;
  while (prev != 0)
    {
      ptr = prev->next;
      delete prev;
      prev = ptr;
    }
}

//--- Definition of assignment operator
const Queue & Queue::operator=(const Queue & rightHandSide)
{
   if (this != &rightHandSide)         // check that not q = q
   {
      this->~Queue();                  // destroy current linked list
      if (rightHandSide.empty())       // empty queue
         myFront = myBack = 0;
      else
      {                                // copy rightHandSide's list
         // Copy first node
         myFront = myBack = new Queue::Node(rightHandSide.front());

         // Set pointer to run through rightHandSide's linked list
         Queue::NodePointer rhsPtr = rightHandSide.myFront->next;
         while (rhsPtr != 0)
         {
           myBack->next = new Queue::Node(rhsPtr->data);
           myBack = myBack->next;
           rhsPtr = rhsPtr->next;
         }
      }
   }
   return *this;
}

//--- Definition of empty()
bool Queue::empty() const
{
   return (myFront == 0);
}

//--- Definition of enqueue()
void Queue::enqueue(const QueueElement & value)
{
   Queue::NodePointer newptr = new Queue::Node(value);
   if (empty())
      myFront = myBack = newptr;
   else
   {
      myBack->next = newptr;
      myBack = newptr;
   }
}

//--- Definition of display()
void Queue::display(ostream & out) const
{
   Queue::NodePointer ptr;
   for (ptr = myFront; ptr != 0; ptr = ptr->next)
     out << ptr->data << "  ";
   out << endl;
}

//--- Definition of front()
QueueElement Queue::front() const
{
   if (!empty())
      return (myFront->data);
   else
   {
	return 0;
   }
}

//--- Definition of dequeue()
void Queue::dequeue()
{
   if (!empty())
   {
      Queue::NodePointer ptr = myFront;
      myFront = myFront->next;
      delete ptr;
      if (myFront == 0)     // queue is now empty
         myBack = 0;
   }
   else
      cerr << "*** Queue is empty -- can't remove a value ***\n";
}

//--- Definition of move_to_front()
void Queue::move_to_front(QueueElement x){
	Queue::NodePointer prev = myFront;		 //set the pointer to run through the queue
    Queue::NodePointer curr = myFront->next; //points to the second node in the queue
	Queue::NodePointer temp_swap;
	
	
	while(curr != NULL){                   	  //loop untill the node reaches the end     
		if(curr->data == x)             	 //compare the current node's data
		{
			temp_swap = curr;              
			prev->next = curr->next;
			temp_swap->next = myFront;       //swap, if found, i.e. move to front if matched 
			myFront = temp_swap;
			return;
		}
		curr = curr->next;
		prev = prev->next;				//changing the current and the previous node to the next one
		}
		}

//---Definition of merge_two_queues()
void Queue::merge_two_queues(Queue & q){
	
	if(q.empty())  								//if the given Queue is empty, exit the method
	return;
	
	Queue temp;
	Node* curr = myFront;	
	Node* curr2 = q.myFront; 
	
	int i = 0;
	while(curr!= NULL){                          //get the length of this Queue
		i++;
		curr = curr->next;
	}
	
	int j = 0;
	while(curr2!=NULL){                         //get the length of the given Queue
		j++;
		curr2 = curr2->next;
	}
	
	curr = myFront;	
	curr2 = q.myFront;
	
	while((curr!=NULL)&&(curr2!=NULL)){
		if((curr->data < curr2->data)){
		temp.enqueue(curr->data);          //merge the given queue into a third temporary queue 
		curr = curr->next;}
		
		else{
			temp.enqueue(curr2->data);
			curr2 = curr2->next;
		}
	}
	
	if(j==i){
		if(curr==NULL){
			while(curr2!=NULL){
			temp.enqueue(curr2->data);      //condtion; when the length of the two Queues are equal!
			curr2 = curr2->next;}}
		else
		{	while(curr!=NULL){
			temp.enqueue(curr->data);
			curr=curr->next;}
		}
	}
	
	if(j>i){
		while(curr2!=NULL){
			temp.enqueue(curr2->data);       //condition; when the length of the given Queue is greater
			curr2=curr2->next;
	}}
	
	if(i>j){
		while(curr!=NULL){
			temp.enqueue(curr->data);           //condition; when the length of this Queue is greater
			curr=curr->next;
		}
	}
	
	while(q.myFront != NULL)          //empty the given queue after a successful merge
		q.dequeue();		
	
	while(myFront != NULL)
		dequeue();
	
	Node* curr3 = temp.myFront;
	while (curr3 != NULL){
		enqueue(curr3->data);            //make this Queue = the temporary/swap Queue
		curr3 = curr3->next;
	}
	
	while(temp.myFront!=NULL)            //empty the temporary Queue
		temp.dequeue();
	
	
	return;
	
}
	
