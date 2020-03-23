/*
 SortAndSearch.cpp
 CO SCI 839 - 26953
 Purpose: To write a program that
 sorts and displays the names in
 alphabetical order (use selection
 sort). the program prompts the user
 to enter the name being searched (use
 binary search). the program also makes
 a correction to upper case the first
 character of the first and last name
 
 */


#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>


using namespace std;

void displayNames(string[], int);     //passed the array of names and the number of names
void selectionSort(string[], int);         //passed the array of names and number of names
                                          //to sort into alph. order
string upperCaseIt(string);        //passed a string being searched. convert the
                                        //first character of the first and last name of the string passed into uppercase
bool binarySearch(string[], int, string);     //passed the array of strings, number of
                                                    //strings, and the string being searched for

int main()
{
    string nameArray[] = {"Collins, Bill", "Smith, Bart", "Michalski, Joe",
                                   "Griffin, Jim", "Sanchez, Manny", "Rubin, Sarah",
                                   "Taylor, Tyrone", "Johnson, Jill", "Allison, Jeff",
                                   "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
                                   "Moretti, Bella", "Wu, Hong", "Patel, Renee",
                                   "Harrison, Rose","Smith, Cathy", "Conroy, Pat",
                                   "Kelly, Sean", "Holland, Beth"};
    
    string answer;
    string firstName, lastName, fullName;
    bool checkValue;
    
        
    displayNames(nameArray, 20);
    
    do {
    
    cout << "Type the name to search (Last, First): " << endl;
    cin >> lastName >> firstName;
    
    
    firstName = upperCaseIt(firstName);
    lastName = upperCaseIt(lastName);
    
    
    fullName = lastName + " " + firstName;
    
    
    //cout << lastName << " " << firstName << endl;
    
    
    checkValue = binarySearch(nameArray, 20, fullName);
    
    if (checkValue == false)
    {
        cout << fullName << " was NOT found in the array." << endl;
    }
    if (checkValue == true)
    {
        cout << fullName << " was found in the array." << endl;
    }
    
        
        cout << "Another name search? (Y/N) ";
        cin >> answer;
        
} while (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES");
   
    return 0;
}



void displayNames(string list[], int ARRAY_SIZE)
{
    int i;
    
    selectionSort(list, 20);
    
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        cout << list[i] << endl;
    }
    
    cout << endl;
}



void selectionSort(string list[], int ARRAY_SIZE)
{
    int startScan, minIndex;
    string minValue;
    
    for (startScan = 0; startScan < (ARRAY_SIZE - 1); startScan++)  //(array_size - 1) = (0 - 19)
    {
        minIndex = startScan;
        minValue = list[startScan];
        
        for (int i = startScan + 1; i < ARRAY_SIZE; i++)
        {
            if (list[i] < minValue)
                {
                    minValue = list[i];
                    minIndex = i;
            }
        }
        
        list[minIndex] = list[startScan];
        list[startScan] = minValue;
    }
}



string upperCaseIt(string name)
{
    int i = 0;
    
    name[0] = toupper(name[0]);
    
    for (i = 1; i < name.length(); i++)
        {
            if (isupper(name[i]))
            {
                name[i] = tolower(name[i]);
            }
        }
    return name;
}


bool binarySearch(string array[], int size, string value)
{
    int first = 0, last = size - 1, middle;
    bool found = false;
    
    while (!found && first <= last)
    {
        middle = (first + last) / 2;
        if (array[middle] == value)         // if value is found in the middle
        {
            found = true;
            //position = middle;
        }
        else if (array[middle] > value)     // if value is in lower half
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;            // if value is in upper half
        }
    }
    return found;
}


