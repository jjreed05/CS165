/***********************************************************************
* Program:
*    Assignment 30, Array Syntax            
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

int averageGrades(int grade[], int size);
int getGrades()
{
   int grade[9],res;
   for(int i = 0; i < 10; i++)
   {
      cout << "Grade " << i+1 << ": ";
      cin >> grade[i];
   }
   res=averageGrades (grade, 10);
   return res;
}

int averageGrades(int grade[], int i)
{
   int sum =0;
   for(int j=0;j < i; j++)
      sum +=grade[j];

   return sum / 10;;
}


int main()
{
   int quotion;
   quotion = getGrades();
   cout << "Average Grade: " << quotion << "%" << endl;
   return 0;
}
