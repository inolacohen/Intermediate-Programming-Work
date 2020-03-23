/*
 FindOccOfLargest.cpp
 CSIT 839 - 26953
 
 Purpose: to write a program that prompts the user
 to enter 6 integers. The program finds and displays
 the largest numbers, smallest numbers, and number of
 occurence elements of the largest numbers.
 
 
 Pseudocode:
 1. Read 6 numbers from the user and store in array
 2. Find the largest and smallest elements of the
 array using for loop
 3. Find the occurence of the largest number using for loop
 4. Display the results
 
 */

#include <iostream>

using namespace std;


int main() {
    
    int NUM_SIZE = 6;
    int numArray[NUM_SIZE], i, largestCount = 0;
    int smallest, largest;
    
    /* Get user input for 6 numbers & store in array */
    
    cout << "You can enter six integer numbers." << endl;
        for (i = 0; i < NUM_SIZE; i++)
        {
            cout << "Enter a number: ";
            cin >> numArray[i];
        }
   /* Display array elements */
    
    cout << "The array elements are: ";
        for (i = 0; i < NUM_SIZE; i++)
        {
            cout << numArray[i] << " ";
        }
        cout << endl;
    
    smallest = numArray[0];
    largest = numArray[0];
   
    
    /* Find the largest number */
    
    for (i = 1; i < NUM_SIZE; i++)
    {
        if (numArray[i] > largest)
        {
            largest = numArray[i];
        }
    }
    cout << "The largest number is " << largest << endl;
    
    /* Find the smallest number */
    
    for (i = 1; i < NUM_SIZE; i++)
    {
        if (numArray[i] < smallest)
        {
            smallest = numArray[i];
        }
    }
    cout << "The smallest number is " << smallest << endl;
    
    
    /* Find the occurrence of the largest number  */
    
    for (i = 0; i < NUM_SIZE; i++)
    {
        if (largest == numArray[i])
        {
            largestCount++;
        }
    }
    
    cout << "The occurrence count of the largest number is " << largestCount << endl << endl;
    
    
    return 0;
}
