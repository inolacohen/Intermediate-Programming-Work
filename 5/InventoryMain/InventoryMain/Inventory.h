//  Inventory.h - Inventory class specificiation file


#ifndef Inventory_h
#define Inventory_h

//Inventory class declaration
class Inventory
{
private:
    int itemNumber;                     //to hold the item's number
    int quantity;                       //to hold the quantity of the item on hand
    double cost;                        //to hold the wholesale per unit-cost of the item
    
public:
    Inventory()                         //default parameter values
    {
        itemNumber = 0;
        quantity = 0;
        cost = 0.00;
    }
    Inventory(int n, int q, double c)      //constructor #2: overloaded constructor
    {
        itemNumber = n;
        quantity = q;
        cost = c;
    }
    
    //set values of private member variables
    void setItemNumber(int);
    void setQuantity(int);
    void setCost(double);
    
    //get values of private member variables
    int getItemNumber();
    int getQuantity();
    double getCost();
    
    //member functions
    double calTotalCost(int, double);
    bool validateInt(int);
    bool validateFloat(double);
    
};


#endif /* Inventory_h */
