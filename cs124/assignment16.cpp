/***********************************************************************
* Program:
*    Assignment 16, If Statemnts          (e.g. Assignment 01, Hello World)  
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    Enter a brief description of your program here!  Please note that if
*    you do not take the time to fill out this block, YOU WILL LOSE POINTS.
*    Before you begin working, estimate the time you think it will
*    take you to do the assignment and include it in this header block.
*    Before you submit the assignment include the actual time it took.
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part.
************************************************************************/

#include <iostream>
using namespace std;

int computeTax()
{
   float income;
   int bracket;
  
   cout << "Income: ";
   cin >> income;
   
      if (income >= 336550)
        bracket = 35;

      else if (income >= 188450 && income < 336550)
        bracket = 33;

      else if (income >= 123700 && income < 188450)
        bracket = 28;

      else if (income >= 61300 && income < 123700)
        bracket = 25;

      else if (income >= 15100 && income < 61300)
        bracket = 15;

      else if (income < 15100)
        bracket = 10;

    return bracket;      
}   
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   int bracket = computeTax();
   

   cout << "Your tax bracket is " << bracket << "\%" << endl;
      
   
   return 0;
}
