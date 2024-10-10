//-----------------------------------------------------------------------------
// StackTest.cpp
// A test client for Stack ADT
//-----------------------------------------------------------------------------
#include<string>
#include<iostream>
#include"Stack.h"

using namespace std;

int main(){

   int i;
   Stack S;
   Stack T;

   cout << endl;

   for(i=1; i<=10; i++){
      S.push(i);
   }
   cout << "S = " << S << endl;

   for(i=11; i<=18; i++){
      S.push(i);
   }
   cout << "S = " << S << endl << endl;

   for(i=1; i<=9; i++){
      S.pop();
      T.push(i);
   }
   cout << "S = " << S << endl;
   cout << "T = " << T << endl;
   cout << "S == T is " << (S==T?"true":"false") << endl << endl;

   S.push(10);
   T.push(100);
   cout << "S = " << S << endl;
   cout << "T = " << T << endl;
   cout << "S == T is " << (S==T?"true":"false") << endl << endl;

   // test exceptions
   while( S.getHeight()>0 ){
      S.pop();
   }
   // S is now empty
   try{
      S.getTop();
   }catch( std::length_error& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      S.pop();
   }catch( std::length_error& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   cout << endl;

   return(0);
}
/* Output:

S = 10 9 8 7 6 5 4 3 2 1
S = 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

S = 9 8 7 6 5 4 3 2 1
T = 9 8 7 6 5 4 3 2 1
S == T is true

S = 10 9 8 7 6 5 4 3 2 1
T = 100 9 8 7 6 5 4 3 2 1
S == T is false

Stack: getTop(): empty Stack
   continuing without interruption
Stack: pop(): empty Stack
   continuing without interruption

*/
