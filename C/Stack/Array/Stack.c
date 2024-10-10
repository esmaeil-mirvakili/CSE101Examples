//-----------------------------------------------------------------------------
// Stack.c
// Implementation file for Stack ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Stack.h"


// private structs, functions and constants -----------------------------------

// InitialSize
static const int InitialSize = 10;

// private StackObj type
typedef struct StackObj{
   StackElement* item;
   int physicalSize;
   int height;
   int top;
} StackObj;

// doubleItemArray
// Doubles the physical size of the underlying array Q->item.
void doubleItemArray(Stack S){
   int newSize = 2*(S->physicalSize);
   StackElement* oldArray = S->item;
   // realloc() allocates and copies to the new array, then frees the old array
   StackElement* newArray = realloc(oldArray, newSize*sizeof(StackElement));
   assert( newArray!=NULL );
   S->physicalSize = newSize;
   S->item = newArray;
}


// Constructors-Destructors ---------------------------------------------------

// newStack()
// Returns reference to new empty Stack object.
Stack newStack(void){
   Stack S;
   S = malloc(sizeof(StackObj));
   assert( S!=NULL );
   S->item = calloc(InitialSize, sizeof(StackElement));
   assert( S->item!=NULL );
   S->physicalSize = InitialSize;
   S->height = 0;
   S->top = -1;
   return(S);
}

// freeStack()
// Frees all heap memory associated with Stack *pS, and sets *pS to NULL.
void freeStack(Stack* pS){
   if(pS!=NULL && *pS!=NULL){
      free((*pS)->item);
      free(*pS);
      *pS = NULL;
   }
}


// Access functions -----------------------------------------------------------

// getTop()
// Returns the value at the top of S.
// Pre: !isEmpty(S)
StackElement getTop(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling getTop() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(S) ){
      printf("Stack Error: calling getTop() on an empty Stack\n");
      exit(EXIT_FAILURE);
   }
   return S->item[S->top];
}

// getHeight()
// Returns the height of S.
int getHeight(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling getHeight() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   return S->height;
}

// isEmpty()
// Returns true if S is empty, otherwise returns false.
bool isEmpty(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling isEmpty() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   return (S->height==0);
}


// Manipulation procedures ----------------------------------------------------

// push()
// Places new data element on top of S.
// Post: !isEmpty(S)
void push(Stack S, StackElement data){
   if( S==NULL ){
      printf("Stack Error: calling push() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }

   if( (S->height)==(S->physicalSize) ){
      doubleItemArray(S);
   }
   S->top++;
   S->item[S->top] = data;
   S->height++;
}

// pop()
// Deletes data element on top of S.
// Pre: !isEmpty(S)
void pop(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling pop() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(S) ){
      printf("Stack Error: calling pop() on an empty Stack\n");
      exit(EXIT_FAILURE);
   }

   S->top--;
   S->height--;
}


// Other Functions ------------------------------------------------------------

// printStack()
// Prints a string representation of S consisting of a space separated list 
// of ints to stdout.
void printStack(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling printStack() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }

   int i;
   for(i = S->top; i>=0; i--){
      printf(FORMAT" ", S->item[i]);
   }
   printf("\n");
}

// equals()
// Returns true if A is same int sequence as B, false otherwise.
bool equals(Stack A, Stack B){
   if( A==NULL || B==NULL )
   {
      printf("Stack Error: calling equals() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }

   int i;
   bool eq = ( A->height == B->height ); 

   for(i = 0; eq && i<A->height; i++){
      eq = ( A->item[i]==B->item[i] );
   }
   return eq;
}
