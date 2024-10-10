//-----------------------------------------------------------------------------
// Stack.c
// Implementation file for Stack ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "Stack.h"

// structs --------------------------------------------------------------------

// private NodeObj type
typedef struct NodeObj{
   StackElement data;
   struct NodeObj* next;
} NodeObj;

// private Node type
typedef NodeObj* Node;

// private StackObj type
typedef struct StackObj{
   Node top;
   int height;
} StackObj;


// Constructors-Destructors ---------------------------------------------------

// newNode()
// Returns reference to new Node object. Initializes next and data fields.
Node newNode(StackElement data){
   Node N = malloc(sizeof(NodeObj));
   assert( N!=NULL );
   N->data = data;
   N->next = NULL;
   return(N);
}

// freeNode()
// Frees heap memory pointed to by *pN, sets *pN to NULL.
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// newStack()
// Returns reference to new empty Stack object.
Stack newStack(void){
   Stack S;
   S = malloc(sizeof(StackObj));
   assert( S!=NULL );
   S->top = NULL;
   S->height = 0;
   return(S);
}

// freeStack()
// Frees all heap memory associated with Stack *pS, and sets *pS to NULL.
void freeStack(Stack* pS){
   if(pS!=NULL && *pS!=NULL){
      while( !isEmpty(*pS) ) { pop(*pS); }
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
   return(S->top->data);
}

// getHeight()
// Returns the height of S.
int getHeight(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling getHeight() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   return(S->height);
}

// isEmpty()
// Returns true if S is empty, otherwise returns false.
bool isEmpty(Stack S){
   if( S==NULL ){
      printf("Stack Error: calling isEmpty() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   return(S->height==0);
}


// Manipulation procedures ----------------------------------------------------

// push()
// Places new data element on top of S.
// Post: !isEmpty(S)
void push(Stack S, StackElement data){
   Node N = newNode(data);

   if( S==NULL ){
      printf("Stack Error: calling push() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }

   if( isEmpty(S) ){ 
      S->top = N; 
   }else{ 
      N->next = S->top; 
      S->top = N; 
   }
   S->height++;
}

// pop()
// Deletes data element on top of S.
// Pre: !isEmpty(S)
void pop(Stack S){
   Node N = NULL;

   if( S==NULL ){
      printf("Stack Error: calling pop() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   if( isEmpty(S) ){
      printf("Stack Error: calling pop() on an empty Stack\n");
      exit(EXIT_FAILURE);
   }

   N = S->top;
   if( getHeight(S)>1 ) { 
      S->top = S->top->next; 
   }else{ 
      S->top = NULL; 
   }
   S->height--;
   freeNode(&N);
}


// Other Functions ------------------------------------------------------------

// printStack()
// Prints a string representation of S consisting of a space separated list 
// of ints to stdout.
void printStack(Stack S){
   Node N = NULL;

   if( S==NULL ){
      printf("Stack Error: calling printStack() on NULL Stack reference\n");
      exit(EXIT_FAILURE);
   }
   for(N = S->top; N != NULL; N = N->next){
      printf(FORMAT" ", N->data);
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

   bool eq; 
   Node N, M;

   eq = ( A->height == B->height );
   N = A->top;
   M = B->top;
   while( eq && N!=NULL)
   {
      eq = ( N->data==M->data );
      N = N->next;
      M = M->next;
   }
   return eq;
}
