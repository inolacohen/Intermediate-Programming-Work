/*
 CDAccount.cpp
 CSIT 839 - 26953
 Purpose: to create a structure named CDAccount.
 to calculate the new balance after user inputs
 balance. interestRate and term
 
 */

#include <iostream>
#include <iomanip>

using namespace std;

// structure CDACCOUNT stores balance, interest rate, and term
struct CDAccount
{
    double balance;
    double interestRate;
    double term;              // months until maturity
};

/* Function prototype */

void getData (CDAccount& Account); // prompt user to input balance, interastRate, and term


int main( )
{
    double totalBalance, term;
    
    CDAccount Account;
    
    getData(Account);
    
    Account.interestRate = Account.interestRate / 100;
    term = Account.term / 12;
    totalBalance = (1 + (term)*(Account.interestRate)) * Account.balance;
    
    cout << "\nWhen your CD matures in " << Account.term << " months,\nit will have a balance of $" << totalBalance << endl << endl;
    
    return 0;
}


void getData(CDAccount& Account)
{
    cout << "Enter account balance: ";
    cin >> Account.balance;
    
    cout << "Enter account interest rate: ";
    cin >> Account.interestRate;
    
    cout << "Enter the number of months until maturity (must be 12 or fewer months): ";
    cin >> Account.term;
    while (Account.term > 12)
    {
        cout << "Please enter number of months that is 12 or less: ";
        cin >> Account.term;
    }
}


