/***********************************************************************
* Program:
*    Project 06, Calendar           
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    This project computes the days offset from any given month or year
*    after 1753. The offset determines how far away the first day of the
*    month is away from Monday. This program takes in account the leap
*    days.
*
*    Estimated:  4.0 hrs   
*    Actual:     5.0 hrs
*      The most difficult part of this project was getting the offset
*      to incorporate the isLeapYear() function properly.
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

/**********************************************************************
 * The getMonth() function asks the user to input the month number.
 ***********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin >> month;

   while (month < 1 || month > 12)
   {
      cout << "Month must be between 1 and 12.\n"
           << "Enter a month number: ";
      cin >> month;
   }
   
   return month;
}

/**********************************************************************
 * The getYear() function asks the user to input a year after 1753.
 ***********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin >> year;

   while (year < 1753)
   {
      cout << "Year must be 1753 or later.\n"
           << "Enter year: ";
      cin >> year;
   }
   
   
   return year;
}

/**********************************************************************
 * This boolean statement calculates if the year is a leap year.
 ***********************************************************************/
bool isLeapYear(int year)
{
   if ( year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
      return true;
   else
      return false;
}

/**********************************************************************
 * This function calculates the number of days in a certain month.
 ***********************************************************************/
int numDaysInMonth(int month, int year)
{
   if (month == 1 || month == 3 || month == 5 || month == 7 || month ==
       8 || month == 10 || month == 12)
      return 31;

   if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
   
   if (month == 2)
   {
      if (isLeapYear(year) == true)
         return 29;
      else 
         return 28;
   }
}

/**********************************************************************
 * This function figures out if the year has 365 days or 366 days.
 ***********************************************************************/
int numDaysInYear(int year)
{
   if (isLeapYear(year) == true)
      return 366;
   else 
      return 365;
}

/**********************************************************************
 * This function calculates the offset between the first day of the month
 * from the last Monday.
 ***********************************************************************/
int computeOffset(int month, int year)
{

   int count = 0;

   for (int i = 1; i < month; i++)
      count = count + numDaysInMonth(i, year);
   for (int i = 1753; i < year; i++)
      count = count + numDaysInYear(i);
   
   int offset = (count % 7);
   return offset; 
}

/**********************************************************************
 * This function displays the offset results.
 ***********************************************************************/
void displayOffset(int offset)
{
   cout << "Offset: " << offset << endl;

   return;
}

/**********************************************************************
 * The function, main(), initializes the program.
 ***********************************************************************/
int main()
{

   int month = getMonth();
   int year = getYear();
   int offset = computeOffset(month, year);
   displayOffset(offset);
   
   return 0;
}
