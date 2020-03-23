/*
 InventoryMain.cpp
 CSIT 839 - 26953
 Purpose: to design an inventory class
 that can hold information for an item
 in a retail store's inventory.
 */

//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Inventory.h"                                                 //contains inventory class declaration
using namespace std;


int main()
{
    Inventory Inventory1;                                               //declare an inventory object (default -> constructor)
    cout << "\nDemonstrating the default constructor..." << endl;
    
    cout << "Item number: " << setw(7)
         << Inventory1.getItemNumber() << endl;
    
    cout << "Quantity: " << setw(10)
         << Inventory1.getQuantity() << endl;
    
    cout << "Cost: " << setw(14) << fixed << "$" << setprecision(2)
         << Inventory1.getCost() << endl;
    
    cout << "Total cost:" << setw(9) << "$" << setprecision(2) << fixed
         << Inventory1.calTotalCost(Inventory1.getQuantity(), Inventory1.getCost()) << endl;
    
    
    Inventory Inventory2(124, 12, 84.95);                             //inventory object for overloaded constructor
    cout << "\nDemonstrating the overloaded constructor..." << endl;
    
    cout << "Item number: " << setw(9)
         << Inventory2.getItemNumber() << endl;
    
    cout << "Quantity: " << setw(11)
         << Inventory2.getQuantity() << endl;
    
    cout << "Cost: " << setw(14) << fixed << "$" << setprecision(2)
         << Inventory2.getCost() << endl;
    
    cout << "Total cost: " << setw(8) << "$" << setprecision(2) << fixed
         << Inventory2.calTotalCost(Inventory2.getQuantity(), Inventory2.getCost()) << endl;
    
    
    Inventory Inventory3;
    int number, quantity;
    double cost;
    
    cout << "\nDemonstrating the 'set' functions... " << endl;
    
    cout << "Item number: ";
    cin >> number;
    
    Inventory3.setItemNumber(number);
    
    while (Inventory3.validateInt(number) == false)
    {
            cout << "Item number must be 0 or greater. Please re-enter: ";
            cin >> number;
    }
    
    cout << "Quantity: ";
    cin  >> quantity;
    
    
    while (Inventory3.validateInt(quantity) == false)
    {
        cout << "Quantity must be 0 or greater. Please re-enter: ";
        cin >> quantity;
    }
    
    Inventory3.setQuantity(quantity);
    
    cout << "Cost: ";
    cin >> cost;
    
    while (Inventory3.validateFloat(cost) == false)
    {
        cout << "Cost must be $0.00 or greater. Please re-enter: ";
        cin >> cost;
    }
    
    Inventory3.setCost(cost);

    cout << "Total cost: " << "$" << setprecision(2) << fixed
         << Inventory3.calTotalCost(Inventory3.getQuantity(), Inventory3.getCost()) << endl;
    
    
    return 0;
}
