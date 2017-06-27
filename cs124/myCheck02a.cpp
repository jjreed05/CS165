/***********************************************************************
* Program:
*    Checkpoint 02a, Structs  
*    Brother Falin, CS165
* Author:
*    Jason Reed
* Summary: 
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct User
{
   string firstName;
   string lastName;
   int identification;
};
    
void prompt(struct User & input)
{
   cout << "Please enter your first name: ";
   getline(cin, input.firstName);
   cout << "Please enter your last name: ";
   getline(cin, input.lastName);
   cout << "Please enter your id number: ";
   cin >> input.identification;
}

void display(const User & output)
{
   cout << endl;
   cout << "Your information:"   << endl;
   cout << output.identification << " - " 
        << output.firstName      << " " 
        << output.lastName       << endl;        
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{  
   User user;
   prompt(user);
   display(user);
   return 0;
}
