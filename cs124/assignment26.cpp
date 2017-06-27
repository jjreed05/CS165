/***********************************************************************
* Program:
*    Assignment 26, Read Files            
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
#include <fstream>
#include <iomanip>
using namespace std;

void getFileName(char fileName[])
{
   cout << "Please enter the filename: ";
   cin >> fileName;
   
}

float readFile(char fileName[])
{
   
   ifstream fin(fileName);
   int data;
   int sum = 0;
   
   if (fin.fail())
   {
      cout << "Error reading file " << "\"" << fileName << "\""  << endl;
      return 0;
   }

   while(fin >> data)
      sum += data;

      
   float average = (sum / 10);
   
    if (average < 10)
       cout << "Error reading file " << "\"" << fileName << "\""  << endl;
    
    if (average > 100)
       cout << "Error reading file " << "\"" << fileName << "\""  << endl;
    

    return average;
   
}


void display(float average)
{     
   if (average < 100 && average > 0)
      cout << "Average Grade: " << 1 + average << "%" << endl;
   return;
}   

/**********************************************************************
 * The main function is the main point of entry for the C++ program.
 * 
 ***********************************************************************/
int main()
{  
   char fileName[256];
   getFileName(fileName);

   float average = readFile(fileName);

   display(average);
   
   return 0;
}
