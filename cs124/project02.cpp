/***********************************************************************
* Program:
*    Project 03, Monthly Budget  
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    This program is for input variables. The computer asks a number of
*    questions about personal income. The user inputs the answers.
*    The program then inputs the answers to the budget.
*
*    
*
*    Estimated:  2.0 hrs   
*    Actual:     2.5 hrs
*      The most difficult part was aligning all variables to the format.
************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

/**********************************************************************
 * "int getMonthlyIncome()" is a function that asks the user what their 
 * income is.
 ***********************************************************************/
float getMonthlyIncome()
{
   float income;
   cout << "\tYour monthly income: ";
   cin >> income;

   return income;
}

/**********************************************************************
 * "getBudgetLiving()" is a function that asks the user what their
 * budgeted living expenses is.
 ***********************************************************************/
float getBudgetLiving()
{
   float budgetLiving;
   cout << "\tYour budgeted living expenses: ";
   cin >> budgetLiving;

   return budgetLiving;
}

/**********************************************************************
 * "getActualLiving()" is a function that asks the user what their
 * actual living expenses is.
 ***********************************************************************/
float getActualLiving()
{
   float actualLiving;

   cout << "\tYour actual living expenses: ";
   cin >> actualLiving;

   return actualLiving;
}

/**********************************************************************
 * "getTithing()" is a function that asks the user what their
 * actual tithe offerings is.
 ***********************************************************************/
float getTithing()
{
   float tithing;
   
   cout << "\tYour actual tithe offerings: ";
   cin >> tithing;

   return tithing;
}

   
/**********************************************************************
 * The "main" initiates the program. 
 * The "main" is at the beginning of the program.
 ***********************************************************************/
int main()
{
   float taxes;
   float other;
  
   
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision (2);

   cout << "This program keeps track of your monthly budget" << endl;
   
   cout << "Please enter the following:" << endl;

   float income = getMonthlyIncome();
      
   float budgetLiving = getBudgetLiving();

   float actualLiving = getActualLiving();

   cout << "\tYour actual taxes withheld: ";
   cin >> taxes;

   float tithing = getTithing();

   cout << "\tYour actual other expenses: ";
   cin >> other;
   cout << endl;
   
      
   cout << "The following is a report on your monthly expenses" << endl;
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $ " << setw(10) << income << setw(5)
        << "$" << setw(11) << income << endl;
   
   cout << "\tTaxes           $ " << setw(10) << 0.0 << setw(5)
        << "$" << setw(11) << taxes <<  endl;
   
   cout << "\t Tithing         $ " << setw(10) << (0.10 * income) << setw(5)
        << "$" << setw(11) << tithing << endl;
   
   cout << "\tLiving          $ " << setw(10) << budgetLiving << setw(5)
        << "$" << setw(11) << actualLiving << endl;
   
   cout << "\t Other           $ " << setw(10) << (income - (0.10 * income)
                                                  - budgetLiving)
        << setw(5) << "$" << setw(11) << other << endl;
   
   cout << "\t=============== =============== ===============\n";
   
   cout << "\t Difference      $ " << setw(10) << 0.0 << setw(5)
        << "$" << setw(11) << (income - taxes - tithing - actualLiving - other)
        << endl;
   
   return 0;
}
