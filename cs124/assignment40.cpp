/***********************************************************************
* Program:
*    Assignment 40, Multi-Dimensional Arrays            
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
void getFileName(char fileName[])
{
   cout << "Enter source filename: ";
   cin.getline(fileName, 256);
}

int readFile(char fileName[], char ticTacToe[][9])
{
   ifstream fin(fileName);

   if (fin.fail())
   {
      return -1;
   }


   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         fin >> ticTacToe[j][i];
         if (ticTacToe[j][i] == '.')
            ticTacToe[j][i] = ' ';
         
      }
      
   }

   
   fin.close();

  
}


void display(int size, char ticTacToe[][9])
{
      cout << " " << ticTacToe[0][0] << " | " << ticTacToe[1][0] << " | " << ticTacToe[2][0] << " " << endl
         
           << "---+---+---" << endl
         
           << " " << ticTacToe[0][1] << " | " << ticTacToe[1][1] << " | " << ticTacToe[2][1] << " " << endl
         
           << "---+---+---" << endl
         
           << " " << ticTacToe[0][2] << " | " << ticTacToe[1][2] << " | " << ticTacToe[2][2] << " " << endl;
         
   
}

void getWriteFileName(char fileName[])
{
   cout << "Enter destination filename: ";
   cin >> fileName;

   return;
}

void writeFile(char fileName[], char ticTacToe[][9])
{
   ofstream output;
   output.open(fileName);

   for (int i = 0; i < 3; i++)
   {
      for (int j = 0; j < 3; j++)
      {
         if (ticTacToe[j][i] == ' ')
            ticTacToe[j][i] = '.';
         output << ticTacToe[j][i] << " ";
      }

      output << endl;
   }

   output.close();

   cout << "File written" << endl;
}
   
      
int main()
{
   char ticTacToe[9][9];
   char fileName[256];

   
   getFileName(fileName);
   
   int size = readFile(fileName, ticTacToe);

   display(size, ticTacToe);

   getWriteFileName(fileName);

   writeFile(fileName, ticTacToe);

   return 0;
}
