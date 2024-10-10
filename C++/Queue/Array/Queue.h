//-----------------------------------------------------------------------------
// Queue.h
// Header file for Queue ADT
//-----------------------------------------------------------------------------
#include<string>
#include<iostream>

#ifndef QUEUE_H_INCLUDE_
#define QUEUE_H_INCLUDE_


// Exported types -------------------------------------------------------------
typedef int QueueElement;

class Queue{

private:

   // Queue fields
   QueueElement* item;
   int physicalSize;
   int length;
   int front;
   int back;

   // Helper function
   void doubleItemArray();

public:
   
   // Class Constructors & Destructors ----------------------------------------

   // Creates a new Queue in the empty state.
   Queue();

   // Copy Constructor.
   Queue(const Queue& Q);

   // Destructor
   ~Queue();


   // Access functions --------------------------------------------------------

   // isEmpty()
   // Returns true if Queue is empty, otherwise returns false.
   bool isEmpty() const;

   // getFront()
   // Returns the value at the front of Queue.
   // Pre: !isEmpty()
   QueueElement getFront() const;

   // getLength()
   // Returns the length of Queue.
   int getLength() const;


   // Manipulation procedures -------------------------------------------------

   // Enqueue()
   // Inserts new data at back of Queue.
   void Enqueue(QueueElement x);

   // Dequeue()
   // Deletes element at front of Queue.
   // Pre: !isEmpty()
   void Dequeue();

   // join()
   // Returns a new Queue consisting of the elements of this Queue, followed
   // the elements of Q.
   Queue join(const Queue& Q) const;

   // Other Functions ---------------------------------------------------------

   // toString()
   // Returns a string representation of Queue consisting of a space separated 
   // list of data values.
   std::string to_string() const;

   // equals()
   // Returns true if and only if this is the same sequence as Q.
   bool equals(const Queue& Q) const;


   // Overriden Operators -----------------------------------------------------
   
   // operator<<()
   // Inserts string representation of Q, as defined by member function 
   // to_string(), into stream.
   friend std::ostream& operator<<( std::ostream& stream, const Queue& Q );

   // operator==()
   // Returns true if and only if Queue A equals Queue B, as defined by member
   // member function equals().
   friend bool operator==( const Queue& A, const Queue& B );

   // operator=()
   // Overwrites the state of this Queue with state of Q, then returns a reference
   // to this Queue.
   Queue& operator=( const Queue& Q );

};


#endif
