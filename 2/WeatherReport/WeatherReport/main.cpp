/*
 WeatherReport.cpp
 Co Sci 839 - 26953
 Purpose: to store the highest
and lowest temperatures for 12
 months of the year. To calculate
 and display the aveage high, average
 low, and the highest and lowest temps.
 for the year.
 */



#include <iostream>
using namespace std;

/* Prototypes */
void getData(int twoDim[][2], int rows);
int averageHigh(int twoDim[][2], int rows);
int averageLow(int twoDim[][2], int rows);
int indexHighTemp(int twoDim[][2], int rows);
int indexLowTemp(int twoDim[][2], int rows);


const int ROW_SIZE = 12;


int main()
{
    
    int temperatures[ROW_SIZE][2];    //2D array
    
    getData(temperatures, ROW_SIZE);
    
    
    return 0;
}

/* Functions */

void getData(int twoDim[][2], int rows)
{
    int indexHigh,
        indexLow;
    
    cout << "Enter high temperature for each month:" << endl;
    
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < rows; j++)
      {
          cin >> twoDim[j][i];
      }
    }
    
    cout << "Enter low temperature for each month:" << endl;
    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            cin >> twoDim[j][i];
        }
    }
    
    cout << "Average high temperature: " << averageHigh(twoDim, rows) << endl;
    
    cout << "Average low temperature: " << averageLow(twoDim, rows) << endl;

    
    indexHigh = indexHighTemp(twoDim, rows);
    indexLow = indexLowTemp(twoDim, rows);
 
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (indexHigh == j)
            {
                cout << "Highest temperature: " << twoDim[j][i] << endl;
            }
        }
    }
    
    
    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if (indexLow == j)
            {
                cout << "Lowest temperature: " << twoDim[j][i] << endl;
            }
        }
    }
    
}

/* To get the average of the high temperatures */
int averageHigh(int twoDim[][2], int rows)
{
    int sumOfHigh = 0,
        average;
    
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            sumOfHigh += twoDim[j][i];
        }
    }
    
    average = sumOfHigh/rows;
    
    return average;
}


/* To get the average of the low temperatures */
int averageLow(int twoDim[][2], int rows)
{
    int sumOfLow = 0, average;
    
    for (int i = 1; i < 2; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            sumOfLow += twoDim[j][i];
        }
    }
    
    average = sumOfLow/rows;
    
    
    return average;
}

/* index of the highest temperature */
int indexHighTemp(int twoDim[][2], int rows)
{
    int indexOfHigh = 0,
        highestNumber = twoDim[0][0];
    
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if(twoDim[j][i] > highestNumber)
            {
                highestNumber = twoDim[j][i];
                indexOfHigh = j;
            }
        }
    }

    return indexOfHigh;
}

/* index of the lowest temperature */
int indexLowTemp(int twoDim[][2], int rows)
{
    int indexOfLow = 0,
        lowestNumber = twoDim[0][1];
    
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            if(twoDim[j][i] < lowestNumber)
            {
                lowestNumber = twoDim[j][i];
                indexOfLow = j;
            }
        }
    }
    
    return indexOfLow;
}
