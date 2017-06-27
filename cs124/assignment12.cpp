/***********************************************************************
* Program:
*    Assignment 12, Input and Variables            
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
#include <iomanip>
using namespace std;

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{
   float income;

   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision (2);

   cout << "\tYour monthly income: ";
   cin >> income;
   cout << "Your income is: $ " << setw(8) << income << endl;
   
   

   
   return 0;
}
