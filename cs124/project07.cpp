/***********************************************************************
* Program:
*    Project 07, Calendar Project          
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    This program displays a calendar that the user wants to see.
*    This program can display any calendar after 1753. The program takes
*    in account the leap year, and it also knows how to calculate the
*    offset from the start of the month from "Monday".
*
*    Estimated:  2.0 hrs   
*    Actual:     1.0 hrs
*      The most difficult part of this project was getting the calendar
*      layout to end at the right line.
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
 * This display function shows the month and year of the calendar
 ***********************************************************************/
void displayHeader(int month, int year)
{
   cout << endl;
   
   if (month == 1)
      cout << "January, " << year << endl;
   if (month == 2)
      cout << "February, " << year << endl;
   if (month == 3)
      cout << "March, " << year << endl;
   if (month == 4)
      cout << "April, " << year << endl;
   if (month == 5)
      cout << "May, " << year << endl;
   if (month == 6)
      cout << "June, " << year << endl;
   if (month == 7)
      cout << "July, " << year << endl;
   if (month == 8)
      cout << "August, " << year << endl;
   if (month == 9)
      cout << "September, " << year << endl;
   if (month == 10)
      cout << "October, " << year << endl;
   if (month == 11)
      cout << "November, " << year << endl;
   if (month == 12)
      cout << "December, " << year << endl;

   return;
}

/**********************************************************************
 * This function displays the calendar table.
 ***********************************************************************/
void display(int offset, int month, int year)
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

   
   for (days = 1; days <= numDaysInMonth(month, year); days++)
   {
      cout << "  " << setw(2) << days;
      if ((days + 1 + offset) % 7 == 0)
         cout << endl;
   }
   if (offset + numDaysInMonth(month, year) == 34)
      ;
   else
      cout << endl;
   
   
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
   displayHeader(month, year);
   display(offset, month, year);
   
   return 0;
}
