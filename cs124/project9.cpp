/***********************************************************************
* Program:
*    Project 09, Mad Lib Program            
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    This program is a Mad Lib program. This program asks the user to
*    input certain answers to questions based on the text file that  
*    the user provides.
*
*    Estimated:  3.0 hrs   
*    Actual:     1.5 hrs
*      The most difficult part of this project was getting the program
*      to ask the questions.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

/**********************************************************************
 * This asks the user to input a file.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Please enter the filename of the Mad Lib: ";
   cin.getline(fileName, 256);
}

/**********************************************************************
 * This function reads the file that the user inputs.
 ***********************************************************************/
int readFile(char fileName[], char madLibStory[][32])
{
   ifstream fin(fileName);
   int numWords = 0;

   if (fin.fail())
   {
      cout << "Error reading file. " << endl;
      return -1;
   }

   while (numWords <= 256 && !fin.eof())
      fin >> madLibStory[numWords++ ];

   fin.close();

   return numWords;
}

/**********************************************************************
 * This function gets the words that the user should input on the story
 * based on the text given in the file.
 ***********************************************************************/
char getWords(char madLibStory[][32], int numWords)
{
   for (int i = 0; i < numWords; i++)
   {
      if (madLibStory[i][0] == '<')
      {
         if (isalpha(madLibStory[i][1]))
         {
            cout << "\t";
            for (int j = 1; madLibStory[i][j] != '>'; j++)
            {
               if (j == 1)
                  cout << (char)toupper(madLibStory[i][1]);
               else if (madLibStory[i][j] == '_')
                  cout << ' ';
               else
                  cout << madLibStory[i][j];
            }

            cout << ": ";
            cin.getline(madLibStory[i], 256);
           
         }
      }
   }
}


/**********************************************************************
 * This function, main(), initializes the program.
 ***********************************************************************/ 
int main()
{
   char madLibStory[256][32];
   char fileName[256];
   
   getFileName(fileName);
   int numWords = readFile(fileName, madLibStory);

   getWords(madLibStory, numWords);
   cout << "Thank you for playing." << endl;


   return 0;
}
