/*
 CheckWriting.cpp
 Co Sci 839 - 26953
 Purpose: to translate numbers into their respective words
 */

#include <iostream>
#include <string>
using namespace std;


class Numbers
{
private:
    int number;

public:
    string lessThanTwenty[20] = { " ", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    
    string tens[10] = { " ", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninty" };
    
    string hundred = "Hundred";
    
    string thousand = "Thousand";
    void print();                       // To print the English description
    Numbers(int x) {
        number = x;
    }

};


int main()
{
     int num;
    
    cout << "This program translates whole dollar amounts"
         << " into words for the purpose of writing checks." << endl;
    
    cout << "Enter an amount to be translated into words: ";
    cin >> num;                                  // Get user input
    Numbers number(num);                         // Create object
    number.print();                              // Call print function and display to user
    cout << endl;
    
    while (num > 0)                              // Continue getting input until negative number is inputted
    {
        cout << "Enter another number: ";
        cin >> num;
        Numbers number(num);
        number.print();
        cout << endl;
    }
    
    return 0;
}

void Numbers::print()
{
    if (number > 999)                          // Getting thousand string
    {
        
        cout << lessThanTwenty[(number / 1000)] << " " << thousand << " ";
        number %= 1000;
    }
    
    if (number > 99 && number < 1000)          // Getting hundred string
    {
        cout << lessThanTwenty[number / 100] << " " << hundred << " ";
        number %= 100;
    }
    
    
    if (number >= 20)                         // Getting tens string if it is (10, 20, 30, etc.)
    {
        cout << tens[(number / 10)] << " ";
        number %= 10;
    }
    else if (number >= 10 && number < 20)     // Getting strings between 10-20 (not including 10 and 20)
    {
        cout << lessThanTwenty[(number)] << " ";
    }
    
    
    if (number > 0 && number < 10)          // Getting ones strings (1-9)
    {
        
        cout << lessThanTwenty[number] << " ";
    }
}
    

