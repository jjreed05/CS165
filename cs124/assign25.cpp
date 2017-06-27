/***********************************************************************
* Program:
*    Assignment 25, Loop Design         (e.g. Assignment 01, Hello World)  
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

int getNumDays()
{
   int numDays;
   cout << "Number of days: ";
   cin >> numDays;

   return numDays;
}

int getOffset()
{
   int offset;
   cout << "Offset: ";
   cin >> offset;
   
   return offset;
}

void displayTable(int numDays, int offset)
{
   int days;
  
   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   if (offset == 0)
      cout << setw(4)  << " ";
   if (offset == 1)
      cout << setw(8)  << " ";
   if (offset == 2)
      cout << setw(12) << " ";
   if (offset == 3)
      cout << setw(16) << " ";
   if (offset == 4)
      cout << setw(20) << " ";
   if (offset == 5)
      cout << setw(24) << " ";
   else (offset == 6);

   for (days = 1; days <= numDays; days++)
   {
      cout << "  " << setw(2) << days;
      if ((days+1+offset) % 7 == 0)
         cout << endl;
   }
   cout << endl;
     
   return;
}   
/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   int numDays = getNumDays();
   int offset = getOffset();

   displayTable(numDays, offset);

   return 0;
}
