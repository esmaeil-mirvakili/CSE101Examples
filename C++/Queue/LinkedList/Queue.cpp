//-----------------------------------------------------------------------------
// Queue.cpp
// Implementation file for Queue ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"Queue.h"


// Private Constructor --------------------------------------------------------

// Node constructor
Queue::Node::Node(QueueElement x){
   data = x;
   next = nullptr;
}


// Class Constructors & Destructors -------------------------------------------

// Creates a new Queue in the empty state.
Queue::Queue(){
   front = nullptr;
   back = nullptr;
   length = 0;
}

// Copy Constructor.
Queue::Queue(const Queue& Q){
   // make this an empty Queue
   front = nullptr;
   back = nullptr;
   length = 0;

   // load elements of Q into this Queue
   Node* N = Q.front;
   while( N!=nullptr ){
      this->Enqueue(N->data);
      N = N->next;
   }
   // std::cout << "***called copy constructor: " << this->to_string() << std::endl;
}

// Destructor
Queue::~Queue(){
   while( length>0 ){
      Dequeue();
   }
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
   return(front->data);
}

// getLength()
// Returns the length of Queue.
int Queue::getLength() const{
   return(length);
}


// Manipulation procedures ----------------------------------------------------

// Enqueue()
// Inserts new data at back of Queue.
void Queue::Enqueue(QueueElement x)
{
   Node* N = new Node(x);

   if( isEmpty() ) { 
      front = back = N; 
   }else{ 
      back->next = N; 
      back = N; 
   }
   length++;
}

// Dequeue()
// Deletes data at back of Queue
// Pre: !isEmpty()
void Queue::Dequeue(){
   if( length==0 ){
      throw std::length_error("Queue: Dequeue(): empty Queue");
   }
   
   Node* N = front;
   if( length>1 ) { 
      front = front->next; 
   }else{ 
      front = back = nullptr; 
   }
   length--;
   delete N;
}

// join()
// Returns a new Queue consisting of the elements of this Queue, followed
// the elements of Q.
Queue Queue::join(const Queue& Q) const{
   Queue J;
   Node* N = this->front;
   Node* M = Q.front;
   while( N!=nullptr ){
      J.Enqueue(N->data);
      N = N->next;
   }
   while( M!=nullptr ){
      J.Enqueue(M->data);
      M = M->next;
   }
   return J;
}


// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of Queue consisting of a space separated 
// list of data values.
std::string Queue::to_string() const{
   Node* N = nullptr;
   std::string s = "";

   for(N=front; N!=nullptr; N=N->next){
      s += std::to_string(N->data)+" ";
   }
   
   return s;
}

// equals()
// Returns true if and only if this is the same sequence as Q.
bool Queue::equals(const Queue& Q) const{
   bool eq = false;
   Node* N = nullptr;
   Node* M = nullptr;

   eq = ( this->length == Q.length );
   N = this->front;
   M = Q.front;
   while( eq && N!=nullptr){
      eq = (N->data==M->data);
      N = N->next;
      M = M->next;
   }
   return eq;
}


// Overloaded Operators --------------------------------------------------------

// operator<<()
// Inserts string representation of Q, as defined by member function 
// to_string(), into stream.
std::ostream& operator<<( std::ostream& stream,  const Queue& Q ) {
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
      std::swap(front, temp.front);
      std::swap(back, temp.back);
      std::swap(length, temp.length);
   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return
}
