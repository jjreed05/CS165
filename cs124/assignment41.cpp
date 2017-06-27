/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory            
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

using namespace std;

int getNumber()
{
   int number;

   cout << "Number of characters: ";
   cin >> number;
   
   return number;
}

void getCharacters(char characters[])
{
   cin.ignore();

   cout << "Enter Text: ";
   cin.getline(characters, 256);
}

void displayText(int number, char characters[])
{

   cout << "Text: ";
   
   for (int i = 0; i < number; i++)
   {
      cout << characters[i];
   }
   cout << endl;
}
   

int main()
{
   int number = getNumber();
   if (number < 0)
      cout << "Allocation failure!" << endl;
   else
   {
      char characters[256];
      getCharacters(characters);
      displayText(number, characters);
   }
      
   return 0;
}
