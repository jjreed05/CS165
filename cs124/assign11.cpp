/***********************************************************************
* Program:
*    Assignment 11, Output  
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
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision (2);
   
   cout << "\tItem           Projected\n";
   cout << "\t=============  ==========\n";
   cout << "\tIncome         $ " << setw(8) <<  1000.0 <<  endl;
   cout << "\tTaxes          $ " << setw(8) << 100.0 <<  endl;
   cout << "\tTithing        $ " << setw(8) << 100.0 << endl;
   cout << "\tLiving         $ " << setw(8) << 650.0 << endl;
   cout << "\tOther          $ " << setw(8) << 90.0 << endl;
   cout << "\t=============  ==========\n";
   cout << "\tDelta          $ " << setw(8) <<  60.0 <<  endl;   
   

   return 0;
}
