/***********************************************************************
* Program:
*    Checkpoint 01b, Arrays          (e.g. Checkpoint 01a, review)  
*    Brother Falin, CS165
* Author:
*    Jason Reed
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Function: getSize
 * Purpose: This asks the user the size of the list.
 ***********************************************************************/
int getSize()
{
   int size = 0;
   cout << "Enter the size of the list: ";
   cin >> size;
   return size;
}

/**********************************************************************
 * Function: getList
 * Purpose: This asks the user to input multiples.
 ***********************************************************************/
void getList(int size, char list[])
{
   for (int i = 0; i < size; i++)
   {
      cout << "Enter number for index " << i << ": ";
      cin >> list[i];
      
   }
   return;
}

/**********************************************************************
 * Function: displayMultiples
 * Purpose: This shows which multiples are divisible by 3.
 ***********************************************************************/
void displayMultiples(int size, char list[])
{
   cout << endl;
   cout << "The following are divisible by 3:" << endl;

   for (int i = 0; i < size; i++)
   {
      if (list[i] % 3 == 0)
         cout << list[i] << endl;
   }
  
   return;

}
     
/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   char list[20];
   int size = getSize();
   getList(size, list);
   displayMultiples(size, list);
   return 0;
}
