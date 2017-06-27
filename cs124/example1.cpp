/***********************************************************************
 * This demo program is designed to:
 *       Using pointers to refer to locations in memory.
 *
 * NOTE: I know this looks "alot like" assignment 3.4.  Please hand-
 *       type the code rather than copy-paste so you can get used to
 *       the pointer syntax, including where the *'s and &'s go. 
 ************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Very simple program.
 ***********************************************************************/
int main()
{
   // start off with money in the accounts
   float accountSam = 120.01;     // original account of Sam
   float accountSue = 398.21;     // Sue does a better job saving
   float * pAccount;              // uninitialized pointer

   // who will pay...
   if (accountSam > accountSue)   // warning: do not try this on an actual date
      pAccount = &accountSam;     // the & gets the address of the account.
   else                           //     This is much like a debit card number
      pAccount = &accountSue;

   // not an expensive dinner
   float priceDinner = 21.65;

   // use the debit card to pay
   *pAccount -= priceDinner;      // remove price of dinner from Sue's account
   *pAccount -= priceDinner * 0.15; // don't forget the tip

   // report
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);
   cout << "Sam's balance: $"
        << accountSam << endl;    // since pAccount points to accountSue,
   cout << "Sue's balance: $"
        << accountSue << endl;    //     only accountSue will have changed
   

   return 0;
}

