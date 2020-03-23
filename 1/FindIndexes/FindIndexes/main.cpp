/*
 FindIndexes.cpp
 CSIT 839 - 26953
 Purpose: to write a program that generates 15
 integers randomly from 1 to 100 and stores in
 an array. The program will find the first occurrence
 of the smallest element and the last occurrence of the
 largest element in the array.
 
 Pseudocode:
 1. generate a random array
 2. print random array
 3. display the largest element and its position
 4. display the smallest element and its position
*/

//#include "stdafx.h"        -->         // doesn't work on mac
#include <iostream>
using namespace std;

/* Function Prototypes */

const int ARRAY_SIZE = 15;
void printArray(const int[], int);
int lastLargestIndex(const int[], int);
int firstSmallestIndex(const int[], int);

int main()
{
    int numbersArray[ARRAY_SIZE], i, j = 0, k = 0;
    int largestNumber, smallestNumber;
    unsigned int seed;
    seed = time(0);
    srand(seed);
    
    cout << "List elements: ";
    
    
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        numbersArray[i] = rand() % 100;
    }
    
    
    /* Pass randomly-generated array to print function */
    
    printArray(numbersArray, ARRAY_SIZE);
    
    largestNumber = lastLargestIndex(numbersArray, ARRAY_SIZE);
    
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (largestNumber == numbersArray[i])
        {
            j = i;
        }
    }
    
    smallestNumber = firstSmallestIndex(numbersArray, ARRAY_SIZE);
    
    for (i = 0; i < ARRAY_SIZE; i++)
    {
        if (smallestNumber == numbersArray[i])
        {
            k = i;
        }
    }
    
    
    cout << "The largest element in this list is " << largestNumber
         << " at the position [" << j + 1 << "]" << endl;
    
    cout << " The smallest element in this list is " << smallestNumber
         << " at the position [" << k + 1 << "]" << endl << endl;
    
    
    return 0;
}


void printArray(const int list[], int sizeX)
{
    int i;
    
    for (i = 0; i < sizeX; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl << endl;
}


int lastLargestIndex(const int list[], int sizeX)
{
    int largest = list[0], i;
    for (i = 0; i < sizeX; i++)
    {
        if (list[i] > largest)
        {
            largest = list[i];
        }
    }
    
    return largest;
}


int firstSmallestIndex(const int list[], int sizeX)
{
    int smallest = list[0], i;
    for (i = 0; i < sizeX; i++)
    {
        if (list[i] < smallest)
        {
            smallest = list[i];
        }
    }
    
    return smallest;
}


