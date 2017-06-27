/***********************************************************************
* Program:
*    Checkpoint 01a, C++ Basics         
*    Brother Falin, CS165
* Author:
*    Jason Reed
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
using namespace std;

/***********************************************************************
 * Function: displayHello()
 * Purpose: This displays the hello text.
 ***********************************************************************/
void displayHello()
{
   cout << "Hello CS 165 World!" << endl;
   return;
}

/***********************************************************************
 * Function: getName()
 * Purpose: This gets the user's name.
 ***********************************************************************/
void getName(char name[])
{
   cout << "Please enter your first name: ";
   cin >> name;
   return;
}

/***********************************************************************
 * Function: getAge()
 * Purpose: This asks the user for their age.
 ***********************************************************************/
int getAge()
{
   int age = 0;
   cout << "Please enter your age: ";
   cin >> age;
   return age;
}

/***********************************************************************
 * Function: displayResults()
 * Purpose: This displays the name and age of the user.
 ***********************************************************************/
void displayResults(char name[], int age)
{
   cout << "Hello " << name << ", you are " << age
        << " years old." << endl;
   return;
}

/***********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   char name[256];
   displayHello();
   getName(name);
   int age = getAge();
   cout << endl;
   displayResults(name, age);
   
   return 0;
}
