/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother {Neff, Jones, Helfrich, Grimmett, Smith, Sloan, Comeau}, CS124
* Author:
*    your name
* Summary: 
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall 
*        pay one-tenth of all their interest annually; and this 
*        shall be a standard law unto them forever, for my holy 
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <iostream>
#include <iomanip>
#include
using namespace std;

/*****************************************************
 *
 *****************************************************/
int getDays()
{
   int day;
   cout << "How many days in the month? ";
   cin >> day;
   
   return day;
}

void display(int day)
{
   for (int i = 1; i <= day; i++)
   {   
      cout << setw(4) << i;
      if (i % 7 == 0)
         
   cout << endl;

   return 0;
}   

/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   int day = getDays();
   display(days);
  
  
   return 0;
}
