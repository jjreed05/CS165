/***********************************************************************
* Program:
*    Project 13, Sudoku
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    This program is a sudoku game. It prompts the user to input a 
*    file that has the puzzle numbers. This program then displays  
*    the sudoku puzzle, and allows the user to edit the puzzle
*    and write the puzzle to a new file.
*
*    Estimated:  4.0 hrs   
*    Actual:     6.5 hrs
*      The most difficult part of this project was getting the program
*      to allow the user to edit a blank square.
************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

/**********************************************************************
 * This function asks the users to supply a file to the program.
 ***********************************************************************/
void getFileName(char fileName[])
{
   cout << "Where is your board located? ";
   cin >> fileName;

   return;
}

/**********************************************************************
 * This function opens the text file and creates an array based on the
 * text file. It also converts 0's to blank spaces.
 ***********************************************************************/
int readFile(char fileName[], char board[][9])
{
   ifstream input;
   input.open(fileName);

   if (input.fail())
   {
      return -1;
   }

   for (int i = 0; i < 9; i++)
      for (int j = 0; j < 9; j++)
      {
         input >> board[j][i];
         if (board[j][i] == '0')
            board[j][i] = ' ';
      }
             

   input.close();
   return 0;
}

/**********************************************************************
 * The displayOption() function displays options the users can do to
 * the puzzle.
 ***********************************************************************/
void displayOption()
{
   cout << "Options:" << endl;
   cout << "   ?  Show these instructions" << endl;
   cout << "   D  Display the board" << endl;
   cout << "   E  Edit one square" << endl;
   cout << "   S  Show the possible values for a square" << endl;
   cout << "   Q  Save and Quit" << endl;
   cout << endl;
}

/**********************************************************************
 * The displayBoard() function displays the array into a sudoku layout.
 ***********************************************************************/
void displayBoard(char board[][9])
{
   cout << "   A B C D E F G H I" << endl;
  
   cout << "1  " << board[0][0] << " " << board[1][0] << " " << board[2][0]
        << "|" << board[3][0] << " " << board[4][0] << " " << board[5][0]
        << "|" << board[6][0] << " " << board[7][0] << " " << board[8][0]
        << endl;
   
   cout << "2  " << board[0][1] << " " << board[1][1] << " " << board[2][1]
        << "|" << board[3][1] << " " << board[4][1] << " " << board[5][1]
        << "|" << board[6][1] << " " << board[7][1] << " " << board[8][1]
        << endl;

   cout << "3  " << board[0][2] << " " << board[1][2] << " " << board[2][2]
        << "|" << board[3][2] << " " << board[4][2] << " " << board[5][2]
        << "|" << board[6][2] << " " << board[7][2] << " " << board[8][2]
        << endl;

   cout << "   -----+-----+-----" << endl;

   cout << "4  " << board[0][3] << " " << board[1][3] << " " << board[2][3]
        << "|" << board[3][3] << " " << board[4][3] << " " << board[5][3]
        << "|" << board[6][3] << " " << board[7][3] << " " << board[8][3]
        << endl;

   cout << "5  " << board[0][4] << " " << board[1][4] << " " << board[2][4]
        << "|" << board[3][4] << " " << board[4][4] << " " << board[5][4]
        << "|" << board[6][4] << " " << board[7][4] << " " << board[8][4]
        << endl;

   cout << "6  " << board[0][5] << " " << board[1][5] << " " << board[2][5]
        << "|" << board[3][5] << " " << board[4][5] << " " << board[5][5]
        << "|" << board[6][5] << " " << board[7][5] << " " << board[8][5]
        << endl;

   cout << "   -----+-----+-----" << endl;

   cout << "7  " << board[0][6] << " " << board[1][6] << " " << board[2][6]
        << "|" << board[3][6] << " " << board[4][6] << " " << board[5][6]
        << "|" << board[6][6] << " " << board[7][6] << " " << board[8][6]
        << endl;

   cout << "8  " << board[0][7] << " " << board[1][7] << " " << board[2][7]
        << "|" << board[3][7] << " " << board[4][7] << " " << board[5][7]
        << "|" << board[6][7] << " " << board[7][7] << " " << board[8][7]
        << endl;

   cout << "9  " << board[0][8] << " " << board[1][8] << " " << board[2][8]
        << "|" << board[3][8] << " " << board[4][8] << " " << board[5][8]
        << "|" << board[6][8] << " " << board[7][8] << " " << board[8][8]
        << endl;

   cout << endl;
 
   return;
}

/**********************************************************************
 * The function, getInput(), allows the user to input options according
 * to the option display.
 ***********************************************************************/
char getInput()
{
   char input;
   cout << "> ";
   cin >> input;

   return input;
}

/**********************************************************************
 * The function, optionE(), allows the user to make changes to the
 * sudoku puzzle where there are blank spaces. It also calculates
 * the location of the text within the array.
 ***********************************************************************/
void optionE(char board[][9])
{
   char coordinate;
   int number;
   char change;
   
   cout << "What are the coordinates of the square: ";
   cin >> coordinate >> number;

   coordinate = toupper(coordinate);

   int row = (number - 1);
   int column = (coordinate - 65);

   if (board[column][row] == ' ')
   {
      cout << "What is the value at '" << coordinate << number
           << "': ";
      cin >> change;

      if (board[column][0] == change ||
          board[column][1] == change ||
          board[column][2] == change ||
          board[column][3] == change ||
          board[column][4] == change ||
          board[column][5] == change ||
          board[column][6] == change ||
          board[column][7] == change ||
          board[column][8] == change)
         cout << "ERROR: Value '" << change << "' in square '"
              << coordinate << number << "' is invalid" << endl;

      else if (board[0][row] == change ||
               board[1][row] == change ||
               board[2][row] == change ||
               board[3][row] == change ||
               board[4][row] == change ||
               board[5][row] == change ||
               board[6][row] == change ||
               board[7][row] == change ||
               board[8][row] == change)
         cout << "ERROR: Value '" << change << "' in square '"
              << coordinate << number << "' is invalid" << endl;

                     
      else
         board[column][row] = change;
      
      cout << endl;
   }
   
   else
   {
      cout << "ERROR: Square '" << coordinate << number
           << "' is filled" << endl;
      cout << endl;
   }

   return;
   
}

/**********************************************************************
 * This function gets the coordinates from the user.
 ***********************************************************************/
void getCoordinates(char coordinate1, int number1)
{
   cout << "What are the coordinates of the square: ";
   cin >> coordinate1 >> number1;
   return;
}

/**********************************************************************
 * This function displays the possible values.
 ***********************************************************************/
void optionS(char coordinate1, int number1, char board[][9])
{
   int row1 = (coordinate1 - 65);
   int column1 = (number1 - 1);
   int startX = row1 / 3 * 3;
   int startY = column1 / 3 * 3;
   char possVal[9];
   
}

/**********************************************************************
 * This function gets the new file-name from the user.
 ***********************************************************************/
void getWriteFileName(char fileName[])
{
   cout << "What file would you like to write your board to: ";
   cin >> fileName;
   return;
}

/**********************************************************************
 * This function writes the edited puzzle to a new file.
 ***********************************************************************/
void writeFile(char fileName[], char board[][9])
{
   ofstream output;
   output.open(fileName);

   for (int i = 0; i < 9; i++)
   {
      for (int j = 0; j < 9; j++)
      {
         if (board[j][i] == ' ')
            board[j][i] = '0';
         output << board[j][i] << " ";
      }
         
      output << endl;
   }

   output.close();

   cout << "Board written successfully" << endl;
   
   return;
}
              
/**********************************************************************
 * Main() connects all of the functions together to initiate the
 * program.
 ***********************************************************************/ 
int main()
{
   char fileName[256];
   char board[9][9];
   char coordinate1;
   int number1;

   getFileName(fileName);
   readFile(fileName, board);
   displayOption();
   displayBoard(board);
   
   while (fileName[256])
   {
      char input = getInput();
      if (input == 'd' || input == 'D')
         displayBoard(board);
      if (input == '?')
      {
         displayOption();
         cout << endl;
      }
      if (input == 'e' || input == 'E')
         optionE(board);
      if (input == 's' || input == 'S')
         getCoordinates(coordinate1, number1);
         
      if (input == 'q' || input == 'Q')
         break;
   }
   getWriteFileName(fileName);
   writeFile(fileName, board);
   
   
   return 0;
}
