//  Inventory.cpp
//  InventoryMain

//

//#include "stdafx.h"
#include <iostream>
#include "Inventory.h"

void Inventory::setItemNumber(int num) {
    itemNumber = num;
}

void Inventory::setQuantity(int quant) {
    quantity = quant;
}

void Inventory::setCost(double price) {
    cost = price;
}

int Inventory::getItemNumber() {
    return itemNumber;
}

int Inventory::getQuantity() {
    return quantity;
}

double Inventory::getCost() {
    return cost;
}

bool Inventory::validateInt(int value)
{
    if (value < 0)
    {
        return false;
    }
    else
        return true;
}

bool Inventory::validateFloat(double cost)
{
    if (cost < 0.00)
    {
        return false;
    }
    else
        return true;
}



double Inventory::calTotalCost(int quantity, double cost)
{
    double totalCost = quantity * cost;
    
    return totalCost;
 }
 

