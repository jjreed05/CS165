/***********************************************************************
* Program:
*    Project 04, Monthly Budget  
*    Brother Grimmett, CS124
* Author:
*    Jason Reed
* Summary: 
*    This program is for input variables. The computer asks a number of
*    questions about personal income. The user inputs the answers.
*    The program then inputs the answers to the budget. The program 
*    calculates anticipated taxes and also the anticipated tithe
*    offerings.
*
*    Estimated:  1.0 hrs   
*    Actual:     0.5 hrs
*      The most difficult part was getting the if statements to work.
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
 * The "computeTithing()" function computes the user's anticipated
 * monthly tithing for the budget.
 ***********************************************************************/
float computeTithing(float income)
{
   float anticipatedTithing = income * 0.10;

   return anticipatedTithing;
}


/**********************************************************************
 * The "computeTax()" function computes the user's anticipated monthly
 * tax for the budget.
 ***********************************************************************/
float computeTax(float income)
{

   float yearlyIncome = (income * 12);
   float yearlyTax;

   if (yearlyIncome >= 0 && yearlyIncome < 15100)
      yearlyTax = (yearlyIncome * 0.10);

   else if (yearlyIncome >= 15100 && yearlyIncome < 61300)
      yearlyTax = 1510 + 0.15 * (yearlyIncome - 15100);

   else if (yearlyIncome >= 61300 && yearlyIncome < 123700)
      yearlyTax = 8440 + 0.25 * (yearlyIncome - 123700);

   else if (yearlyIncome >= 123700 && yearlyIncome < 188450)
      yearlyTax = 24040 + 0.28 * (yearlyIncome - 123700);

   else if (yearlyIncome >= 188450 && yearlyIncome < 336550)
      yearlyTax = 42170 + 0.33 * (yearlyIncome - 188450);

   else if (yearlyIncome >= 336550)
      yearlyTax = 91043 + 0.35 * (yearlyIncome - 336550);

   float monthlyTax = yearlyTax  / 12;

   return monthlyTax;
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

   float anticipatedTithing = computeTithing(income);
   float monthlyTax = computeTax(income);
   
   cout << "The following is a report on your monthly expenses" << endl;
   cout << "\tItem                  Budget          Actual\n";
   cout << "\t=============== =============== ===============\n";
   cout << "\tIncome          $ " << setw(10) << income << setw(5)
        << "$" << setw(11) << income << endl;
   
   cout << "\tTaxes           $ " << setw(10) << monthlyTax << setw(5)
        << "$" << setw(11) << taxes <<  endl;
   
   cout << "\tTithing         $ " << setw(10) << anticipatedTithing << setw(5)
        << "$" << setw(11) << tithing << endl;
   
   cout << "\tLiving          $ " << setw(10) << budgetLiving << setw(5)
        << "$" << setw(11) << actualLiving << endl;
   
   cout << "\tOther           $ " << setw(10) << (income - (0.10 * income)
                                                  - budgetLiving - monthlyTax)
        << setw(5) << "$" << setw(11) << other << endl;
   
   cout << "\t=============== =============== ===============\n";
   
   cout << "\tDifference      $ " << setw(10) << 0.0 << setw(5)
        << "$" << setw(11) << (income - taxes - tithing - actualLiving - other)
        << endl;
   
   return 0;
}
