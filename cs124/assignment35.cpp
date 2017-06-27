/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals            
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

int getGrade()
{
   int grade;

   cout << "Enter number grade: ";
   cin >> grade;

   return grade;
}

char computeLetterGrade(int grade)
{
   char letterGrade;
   
   switch (grade / 10)
   {
      case 10:
      case 9:
         letterGrade = 'A';
         break;
      case 8:
         letterGrade = 'B';
         break;
      case 7:
         letterGrade = 'C';
         break;
      case 6:
         letterGrade = 'D';
         break;
      default:
         letterGrade = 'F';
   }
   return letterGrade;
}

char computeGradeSign(int grade)
{
   char gradeSign;

   if (grade > 95 || grade < 60)
      gradeSign = '*';
   else
      switch (grade % 10)
      {  case 9:
         case 8:
         case 7:
            gradeSign = '+';
            break;
         case 6:
         case 5:
         case 4:
         case 3:   
            gradeSign = '*';
            break;
         default:
            gradeSign = '-';
      }

   return gradeSign;
}

int main()
{
   int grade = getGrade();

   char letterGrade = computeLetterGrade(grade);

   char gradeSign = computeGradeSign(grade);
   
   if (gradeSign == '*')
      cout << grade << "% is " << letterGrade << endl;
   else
      cout << grade << "% is " << letterGrade << gradeSign << endl;
   return 0;
}
