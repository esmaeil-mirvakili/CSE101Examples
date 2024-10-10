//-----------------------------------------------------------------------------
// Stack.cpp
// Implementation file for Stack ADT
//-----------------------------------------------------------------------------
#include<string>
#include<cstring>
#include<iostream>
#include<stdexcept>
#include"Stack.h"

// Initial size  --------------------------------------------------------------
static const int InitialSize = 10;

// Helper Function ------------------------------------------------------------

// doubleItemArray
// Doubles the physical size of this Stack's underlying item array.
void Stack::doubleItemArray(){
   int newSize = 2*physicalSize;
   StackElement* oldArray = item;
   StackElement* newArray = new StackElement[newSize];
   
   // efficiently copy oldArray to newArray
   memcpy(newArray, oldArray, physicalSize*sizeof(StackElement));

   delete [] oldArray;
   item = newArray;
   physicalSize = newSize;
}


// Class Constructors & Destructors -------------------------------------------

// Creates new Stack in the empty state.
Stack::Stack(){
   item = new StackElement[InitialSize];
   physicalSize = InitialSize;
   top = -1;
   height = 0;
}

// Copy constructor.
Stack::Stack(const Stack& S){
   // create an array with room to grow
   physicalSize = 2*S.height;
   item = new StackElement[physicalSize];
   height = S.height;
   top = S.top;

   // efficiently copy elements from S to this Stack
   memcpy(item, S.item, height*sizeof(StackElement));
}

// Destructor
Stack::~Stack(){
   delete [] item;
}


// Access functions -----------------------------------------------------------

// isEmpty()
// Returns true if Stack is empty, otherwise returns false.
bool Stack::isEmpty() const{
   return(height==0);
}

// getTop()
// Returns the value at top of Stack.
// Pre: !isEmpty()
StackElement Stack::getTop() const{
   if( height==0 ){
      throw std::length_error("Stack: getTop(): empty Stack");
   }
   return(item[top]);
}

// getHeight()
// Returns the height of Stack.
int Stack::getHeight() const{
   return(height);
}


// Manipulation procedures ----------------------------------------------------

// push()
// Places new data element on top of Stack.
void Stack::push(StackElement x)
{
   if( height==physicalSize ){
      doubleItemArray();
   }
   top++;
   item[top] = x;
   height++;
}

// pop()
// Deletes data element on top of Stack.
// Pre: !isEmpty()
void Stack::pop(){
   if( height==0 ){
      throw std::length_error("Stack: pop(): empty Stack");
   }

   top--;
   height--;
}


// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of Stack consisting of a space separated 
// list of data values.
std::string Stack::to_string() const{
   std::string s = "";
   for(int i=top; i>=0; i--){
      s += std::to_string(item[i])+" ";
   }
   return s;
}

// equals()
// Returns true if and only if this Stack is the same sequence as S.
bool Stack::equals(const Stack& S) const{
   bool eq = ( height == S.height );
   for(int i=0; eq && i<height; i++){
      eq = ( item[i]==S.item[i] );
   }
   return eq;
}


// Overloaded Operators -------------------------------------------------------

// operator<<()
// Inserts string representation of S, as defined by member function to_string(),
// into stream.
std::ostream& operator<< ( std::ostream& stream, const Stack& S ) {
   return stream << S.to_string();
}

// operator==()
// Returns true if and only if A equals B, as defined by member function equals().
bool operator== (const Stack& A, const Stack& B){
   return A.equals(B);
}

// operator=()
// Overwrites the state of this Stack with state of S, then returns a reference
// to this Stack.
Stack& Stack::operator=( const Stack& S ){
   if( this != &S ){ // not self assignment
      // make a copy of S
      Stack temp = S;

      // then swap the copy's fields with fields of this
      std::swap(item, temp.item);
      std::swap(physicalSize, temp.physicalSize);
      std::swap(height, temp.height);
      std::swap(top, temp.top);
   }

   // return this with the new data installed
   return *this;

   // the copy, if there is one, is deleted upon return   
}
