//-----------------------------------------------------------------------------
// Stack.h
// Header file for Queue ADT
//-----------------------------------------------------------------------------
#include<string>
#include<iostream>

#ifndef STACK_H_INCLUDE_
#define STACK_H_INCLUDE_


// Exported type --------------------------------------------------------------
typedef int StackElement;

class Stack{

private:

   // private Node struct
   struct Node{
      // Node fields
      StackElement data;
      Node* next;
      // Node constructor
      Node(StackElement x);
   };

   // Stack fields
   Node* top;
   int height;

public:

   // Class Constructors & Destructors ----------------------------------------

   // Creates new Stack in the empty state.
   Stack();

   // Copy constructor.
   Stack(const Stack& L);

   // Destructor
   ~Stack();


   // Access functions --------------------------------------------------------

   // isEmpty()
   // Returns true if Stack is empty, otherwise returns false.
   bool isEmpty() const;

   // getTop()
   // Returns the value at top of Stack.
   // Pre: !isEmpty()
   StackElement getTop() const;

   // getHeight()
   // Returns the height of Stack.
   int getHeight() const;


   // Manipulation procedures -------------------------------------------------

   // push()
   // Places new data element on top of Stack.
   void push(StackElement x);

   // pop()
   // Deletes data element on top of Stack.
   // Pre: !isEmpty()
   void pop();


   // Other Functions ---------------------------------------------------------

   // to_string()
   // Returns a string representation of Stack consisting of a space separated 
   // list of data values.
   std::string to_string() const;

   // equals()
   // Returns true if and only if this Stack is the same sequence as S.
   bool equals(const Stack& S) const;


   // Overriden Operators -----------------------------------------------------

   // operator<<()
   // Inserts string representation of S, as defined by member function 
   // to_string(), into stream.
   friend std::ostream& operator<<( std::ostream& stream, const Stack& S );

   // operator==()
   // Returns true if and only if A equals B, as defined by member function
   // equals().
   friend bool operator==( const Stack& A, const Stack& B );

   // operator=()
   // Overwrites the state of this Stack with state of S, then returns a
   // reference to this Stack.
   Stack& operator=( const Stack& S );

};


#endif
