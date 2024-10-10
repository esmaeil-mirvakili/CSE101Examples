//-----------------------------------------------------------------------------
// StackTest.c
// A test client for Stack ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"

int main(int argc, char* argv[]){
   int i;
   Stack S = newStack();
   Stack T = newStack();

   printf("\n");

   for(i=1; i<=10; i++){
      push(S, i);
   }
   printStack(S);

   for(i=11; i<=18; i++){
      push(S, i);
   }
   printStack(S);
   printf("\n");

   for(i=1; i<=9; i++){
      pop(S);
      push(T, i);
   }
   printStack(S);
   printStack(T);
   printf("S==T is %s\n\n", equals(S, T)?"true":"false");

   push(S, 10);
   push(T, 100);
   printStack(S);
   printStack(T);
   printf("S==T is %s\n\n", equals(S, T)?"true":"false");

   freeStack(&S);
   freeStack(&T);

   return(0);
}
/* Output:

10 9 8 7 6 5 4 3 2 1
18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

9 8 7 6 5 4 3 2 1
9 8 7 6 5 4 3 2 1
S==T is true

10 9 8 7 6 5 4 3 2 1
100 9 8 7 6 5 4 3 2 1
S==T is false

*/
