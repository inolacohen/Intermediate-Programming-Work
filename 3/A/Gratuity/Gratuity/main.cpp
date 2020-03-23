/*
 Gratuity.cpp
 Nov 6, 2018
 CO SCI 839 - 26953
 Purpose: to design a TIPS class that calculates
 the gratuity on a restaurant bill.
 */

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


class Tips
{
private:
    double taxRate;
    double tipRate;
    
public:
    Tips(double tax = 6.5, double tip = 15) {                     // Constructor: initial object created is default tax rate: 6.5%
        taxRate = tax;
        tipRate = tip;
    }
    
    /* Setter Function(s) */
    double setTaxRate(double);
    double setTipRate(double);
    
    /* Other Function(s) */
    double computeTip(double, double);
    double computeTax(double, double);
};

/* General Function(s) */
double computeTotalBill(double, double, double);                     // Generic function, it does not access anything
                                                                     // within the class, so it can be outside

int main()
{
    Tips tip;                                                        // Create an object from the class Tips
    double subtotalBill;
    double taxPercent, tipPercent;
    double taxDollar, tipDollar;
    
    string answer;
    

    do {
        cout << "This program will compute a restaurant tip based on\na total bill amount and"
        << " % the patron wishes to tip the server." << endl;
        
        
        /* SubTotal */
        cout << "\nEnter sub-total bill amount: ";
        cin >> subtotalBill;                                                                     // Get user's subtotal for bill
        
        
        /* Tax Computation */
        cout << "Tax % for this location (example 6.5): ";
        cin >> taxPercent;                                                               // Get user's desired tax rate
        taxPercent = (tip.setTaxRate(taxPercent)) / 100;                // Call compute function and convert to decimal for percent
        taxDollar = tip.computeTax(taxPercent, subtotalBill);
        
        cout << "\nThe tax should be $" << setprecision(2) << fixed << showpoint
             << taxDollar << endl;
        
        
        cout << "\n**************** Tip Helper ****************\n" << endl;
        
        /* Tip Computation */
        cout << "Enter desired tip %: ";                                                        // Get user's desired tip rate
        cin >> tipPercent;
        tipPercent = (tip.setTipRate(tipPercent)) / 100;
        
        tipDollar = tip.computeTip(tipPercent, subtotalBill);                   // Call computer function and convert to decimal for percent
        
        cout << "\nThe tip should be $" << setprecision(2) << fixed << showpoint
             << tipDollar << endl;
        
        
        /* Total Bill = subtotal + tip + tax */
        cout << "\n**************** Total Bill ****************\n" << endl;
        cout << "Your total bill, including tip and tax is $" << setprecision(2) << fixed << showpoint
        << computeTotalBill(tipDollar, taxDollar, subtotalBill) << endl;
        
        cout << "\nCompute another tip? (Y/N) ";
        cin >> answer;
        
        cout << endl;
        
    } while (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES");
    
    return 0;
}


double Tips::setTaxRate(double rate)
{
    if (rate > 0)                                                                // If user's value is valid, set their tax rate
    {
        taxRate = rate;
    }
    if (rate <= 0)                                                            // Otherwise, use default tax rate from constructor
    {
        cout << "\nInvalid tax rate. Using default tax rate: 6.5% " << endl;
        taxRate = 6.5;
    }
    return taxRate;
}
double Tips::setTipRate(double rate)
{
    if (rate > 0)                                                                 // If user's value is valid, set their tax rate
    {
        tipRate = rate;
    }
    if (rate <= 0)                                                            // Otherwise, use default tax rate from constructor
    {
        cout << "\nInvalid tip rate. Using default tip rate: 15% " << endl;
        tipRate = 15;
    }
    return tipRate;
}


double Tips::computeTip(double percent, double billSubtotal)
{
    double total;
    
    total = percent * billSubtotal;
    
    return total;
}

double Tips::computeTax(double percent, double billSubtotal)
{
    double total;
    
    total = percent * billSubtotal;
    
    return total;
}


/* Not a member function of class Tips */
double computeTotalBill(double tip, double tax, double billSubtotal)
{
    double total;
    
    total = tip + tax + billSubtotal;
    
    return total;
    
}
