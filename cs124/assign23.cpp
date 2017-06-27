/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax          (e.g. Assignment 01, Hello World)  
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

int getMultiple()
{
   int multiple;
   cout << "What multiples are we adding? ";
   cin >> multiple;

   return multiple;
}


int addMultiples(int multiple)
{
   int outcome = 0;

   for (int count = multiple; count < 100; count += multiple)
   {
      outcome += count;
   }

   return outcome;
}

void display(int multiple, int outcome)
{
   cout << "The sum of multiples of " << multiple
        << " less than 100 are: " << outcome << endl;

   return;
}

/**********************************************************************
 * Add text here to describe what the function "main" does. Also don't forget
 * to fill this out with meaningful text or YOU WILL LOSE POINTS.
 ***********************************************************************/
int main()
{

   int multiple = getMultiple();
   int outcome = addMultiples(multiple);
   display (multiple, outcome);

   return 0;
   

}
