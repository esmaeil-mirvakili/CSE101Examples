//-----------------------------------------------------------------------------
// QueueTest.cpp
// A test client for Queue ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"Queue.h"

using namespace std;

int main(){

   int i;
   Queue Q;
   Queue R;

   cout << endl;

   for(i=1; i<=10; i++){
      Q.Enqueue(i);
   }
   cout << "Q = " << Q << endl;

   for(i=1; i<=5; i++){
      Q.Dequeue();
   }
   cout << "Q = " << Q << endl;

   for(i=11; i<=15; i++){
      Q.Enqueue(i);
   }
   cout << "Q = " << Q << endl;

   for(i=16; i<=19; i++){
      Q.Enqueue(i);
   }
   cout << "Q = " << Q << endl << endl;

   for(i=13; i<=19; i++){
      Q.Dequeue();
      R.Enqueue(i);
   }
   cout << "Q = " << Q << endl;
   cout << "R = " << R << endl;
   cout << "Q == R is " << (Q==R?"true":"false") << endl << endl;

   Q.Enqueue(20);
   R.Enqueue(200);
   cout << "Q = " << Q << endl;
   cout << "R = " << R << endl;
   cout << "Q == R is " << (Q==R?"true":"false") << endl << endl;

   Queue S = Q; // copy constructor called
   Queue T = S.join(R);

   cout << "Q = " << Q << endl;
   cout << "R = " << R << endl;
   cout << "S = " << S << endl;
   cout << "T = " << T << endl << endl;
   
   // test exceptions
   while( Q.getLength()>0 ){
      Q.Dequeue();
   }
   // Q is now empty
   try{
      Q.getFront();
   }catch( std::length_error& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   try{
      Q.Dequeue();
   }catch( std::length_error& e ){
      cout << e.what() << endl;
      cout << "   continuing without interruption" << endl;
   }
   cout << endl;


   return(0);
}
/* Output:

Q = 1 2 3 4 5 6 7 8 9 10
Q = 6 7 8 9 10
Q = 6 7 8 9 10 11 12 13 14 15
Q = 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Q = 13 14 15 16 17 18 19
R = 13 14 15 16 17 18 19
Q == R is true

Q = 13 14 15 16 17 18 19 20
R = 13 14 15 16 17 18 19 200
Q == R is false

Q = 13 14 15 16 17 18 19 20
R = 13 14 15 16 17 18 19 200
S = 13 14 15 16 17 18 19 20
T = 13 14 15 16 17 18 19 20 13 14 15 16 17 18 19 200

Queue: getFront(): empty Queue
   continuing without interruption
Queue: Dequeue(): empty Queue
   continuing without interruption

*/
