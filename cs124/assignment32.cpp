/***********************************************************************
* Program:
*    Assignment 32, Strings            
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

char getLetter()
{
   char letter;
   cout << "Enter a letter: ";
   cin >> letter;

   return letter;
}   

void getPhrase(char text[])
{
   cout << "Enter text: ";
   cin.ignore();
   cin.getline(text, 256);

   return;
}   

   
int countLetters(char letter, char text[])
{
   int numLetters = 0;
   for (int i = 0; text[i]; i++)
   {
      if (text[i]==letter)
         numLetters += 1;
   }

   return numLetters;
}

int main()
{
   char text[256];
   char letter = getLetter();
   getPhrase(text);
  


   int numLetters = countLetters(letter, text);

   cout << "Number of '" << letter << "'s: " << numLetters << endl;

 
  
   

   return 0;
}
