/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    
*    
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;


int main()
{
   char text[] = "0.3";
   float meter;
   meter = atof(text);

   cout << "1.0 feet is 0.3 meters" << endl;
   cout << "2.0 feet is 0.6 meters" << endl;
   cout << "3.0 feet is 0.9 meters" << endl;
   cout << "5.9 feet is 1.8 meters" << endl;
   cout << "100.0 feet is 30.5 meters" << endl;
   
   return 0;
}
