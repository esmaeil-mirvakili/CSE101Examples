//-----------------------------------------------------------------------------
// Queue.cpp
// Implementation file for Queue ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"Queue.h"

// Initial size  --------------------------------------------------------------
static const int InitialSize = 10;

// Helper Function ------------------------------------------------------------

// doubleItemArray
// Doubles the physical size of this Queue's underlying item array.
void Queue::doubleItemArray(){
   int i;
   int newSize = 2*physicalSize;
   QueueElement* oldArray = item;
   QueueElement* newArray = new QueueElement[newSize];
   
   for(i=0; i<length; i++){
      newArray[i] = oldArray[(front+i)%physicalSize];
   }
   delete [] oldArray;

   item = newArray;
   physicalSize = newSize;
   front = 0;
   back = length-1;
}


// Class Constructors & Destructors -------------------------------------------

// Creates a new Queue in the empty state.
Queue::Queue(){
   item = new QueueElement[InitialSize];
   physicalSize = InitialSize;
   front = 0;
   back = -1;
   length = 0;
}

// Copy Constructor.
Queue::Queue(const Queue& Q){
   // create an array with room to grow
   physicalSize = 2*Q.length;
   item = new QueueElement[physicalSize];
   length = Q.length;
   front = 0;
   back = length-1;

   // load elements of Q into this Queue
   for(int i=0; i<Q.length; i++){
      item[i] = Q.item[(Q.front+i)%Q.physicalSize];
   }
}

// Destructor
Queue::~Queue(){
   delete [] item;
}


// Access functions -----------------------------------------------------------

// isEmpty()
// Returns true if Queue is empty, otherwise returns false.
bool Queue::isEmpty() const{
   return(length==0);
}

// getFront()
// Returns the value at the front of Queue.
// Pre: !isEmpty()
QueueElement Queue::getFront() const{
   if( length==0 ){
      throw std::length_error("Queue: getFront(): empty Queue");
   }
   return(item[front]);
}

// getLength()
// Returns the length of Queue.
int Queue::getLength() const{
   return(length);
}


// Manipulation procedures ----------------------------------------------------

// Enqueue()
// Inserts new data at back of Queue.
void Queue::Enqueue(QueueElement x){
   if( length==physicalSize ){
      doubleItemArray();
   }
   back = (back+1)%physicalSize;
   item[back] = x;
   length++;
}

// Dequeue()
// Deletes data at back of Queue
// Pre: !isEmpty()
void Queue::Dequeue(){
   if( length==0 ){
      throw std::length_error("Queue: Dequeue(): empty Queue");
   }
   
   front = (front+1)%physicalSize;
   length--;
}

// join()
// Returns a new Queue consisting of the elements of this Queue, followed
// the elements of Q.
Queue Queue::join(const Queue& Q) const{
   Queue R = *this; // create a copy of this Queue

   // place contents of Q at the end of R
   for(int i=0; i<Q.length; i++){
      R.Enqueue( Q.item[ (Q.front+i)%(Q.physicalSize) ] );
   }
   return R;
}


// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of this Queue consisting of a space separated 
// list of data values.
std::string Queue::to_string() const{
   std::string s = "";
   for(int i=0; i<length; i++){
      s += std::to_string(item[(front+i)%physicalSize])+" ";
   }
   return s;
}

// equals()
// equals()
// Returns true if and only if this is the same sequence as Q.
bool Queue::equals(const Queue& Q) const{
   bool eq = ( length == Q.length );
   int i = 0;

   while( eq && i<length){
      eq = ( item[(front+i)%physicalSize] == Q.item[(Q.front+i)%Q.physicalSize] );
      i++;
   }

   return eq;
}


// Overloaded Operators --------------------------------------------------------

// operator<<()
// Inserts string representation of Q, as defined by member function 
// to_string(), into stream.
std::ostream& operator<< ( std::ostream& stream,  const Queue& Q ) {
   return stream << Q.to_string();
}

// operator==()
// Returns true if and only if Queue A equals Queue B, as defined by member
// member function equals().
bool operator==(const Queue& A, const Queue& B){
   return A.equals(B);
}

// operator=()
// Overwrites the state of this Queue with state of Q, then returns a reference
// to this Queue.
Queue& Queue::operator=( const Queue& Q ) {
   if( this != &Q ){ // not self assignment
      // make a copy of Q
      Queue temp = Q;

      // then swap the copy's fields with fields of this
      std::swap(item, temp.item);
      std::swap(physicalSize, temp.physicalSize);
      std::swap(length, temp.length);
      std::swap(front, temp.front);
      std::swap(back, temp.back);
   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return
}
