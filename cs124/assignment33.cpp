/***********************************************************************
* Program:
*    Assignment 33, Pointers            
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*   
*   
*
*
*    Estimated:  0.30 hrs   
*    Actual:     0.45 hrs
*   
*   
************************************************************************/

#include <iostream>

using namespace std;

float getSamsBalance()
{
   float samsBalance;

   cout << "What is Sam's balance? ";
   cin >> samsBalance;

   return samsBalance;
}

float getSuesBalance()
{
   float suesBalance;

   cout << "What is Sue's balance? ";
   cin >> suesBalance;

   return suesBalance;
}
void displayCost()
{
   cout << "Cost of the date:" << endl;
}

float getDinnerCost()
{
   float dinner;

   cout << "\tDinner:    ";
   cin >> dinner;

   return dinner;
}

float getMovieCost()
{
   float movie;

   cout << "\tMovie:     ";
   cin >> movie;

   return movie;
}

float getIceCreamCost()
{
   float iceCream;

   cout << "\tIce cream: ";
   cin >> iceCream;

   return iceCream;
}

int main()
{

   float samsBalance = getSamsBalance();
   float suesBalance = getSuesBalance();
   displayCost();
   float dinner = getDinnerCost();
   float movie = getMovieCost();
   float iceCream = getIceCreamCost();
   float * pBalance;

   if (samsBalance > suesBalance)
      pBalance = &samsBalance;
   else
      pBalance = &suesBalance;

   float dinnerCost = (dinner + movie + iceCream);

   *pBalance -= dinnerCost;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   
   cout << "Sam's balance: $" << samsBalance << endl;
   cout << "Sue's balance: $" << suesBalance << endl;

   
   return 0;
}
