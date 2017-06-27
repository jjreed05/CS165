/***********************************************************************
* Program:
*    Assignment 01, Genetic Geneaology  
*    Brother Falin, CS165
* Author:
*    Jason Reed
* Summary: 
*    This program compares 10 characters of a person's DNA strand to
*    that person's relatives. The program then tells the user the
*    percentage of how much the DNA strands are similar.
*
*    Estimated:  2.0 hrs   
*    Actual:     2.5 hrs
*      The hardest part of the assignment was debugging issues.
************************************************************************/

#include <iostream>
#include <string>
using namespace std;

/**********************************************************************
 * The getDna() function asks for the user's DNA sequence.
 ***********************************************************************/
void getDna(string &dna)
{
   cout << "Enter your DNA sequence: ";
   getline(cin, dna);

   return;
}

/**********************************************************************
 * The getRelatives() function asks the user for how many relative
 * that they want the program to compare.
 ***********************************************************************/
int getRelatives()
{
   int relatives = 0;
   cout << "Enter the number of potential relatives: ";
   cin >> relatives;

   return relatives;
}

/**********************************************************************
 * The getNames() function asks the user for their relative's names
 * for DNA comparison.
 ***********************************************************************/
void getNames(int relatives, string names[256])
{
   cin.ignore();
   cout << endl;
   for (int i = 0; i < relatives; i++)
   {
      cout << "Please enter the name of relative #" << (i + 1) << ": ";
      getline(cin, names[i]);
   }
   return;
}

/**********************************************************************
 * The getRelDNA() function prompts the user to input their relative's
 * DNA strands.
 ***********************************************************************/
void getRelDna(int relatives, string names[256], string relDna[256])
{
   cout << endl;
   for (int i = 0; i < relatives; i++)
   {
      cout << "Please enter the DNA sequence for " << names[i] << ": ";
      getline(cin, relDna[i]);
   }
   return;
}

/**********************************************************************
 * This function displays the percentages of how much the DNA strands
 * are similar.
 ***********************************************************************/
void displayResults(int relatives, string relDna[256],
                    string names[256], string dna)
{
   cout << endl;
   int result;
   for (int i = 0; i < relatives; i++)
   {
      result = 0;
      for (int j = 0; j < 10; j++)
      {
         if (relDna[i][j] == dna[j])
            result += 1;
      }
      cout << "Percent match for " << names[i] << ": "
           << (result * 10) << "%" << endl;
   }

   return;
}

/**********************************************************************
 * The function main() initializes the program.
  ***********************************************************************/
int main()
{
   string dna;
   string names[256];
   string relDna[256];
   string comparison[256];
   getDna(dna);
   int relatives = getRelatives();
   getNames(relatives, names);
   getRelDna(relatives, names, relDna);
   displayResults(relatives, relDna, names, dna);
   
   return 0;
}
