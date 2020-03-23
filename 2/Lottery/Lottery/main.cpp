/*
 Lottery.cpp
 CSIT 839 - 26953
 Purpose: to write a program that randomly
 generates a lottery of a five-digit number
 ranging from 0-9 and store in array. The
 program asks the user to enter a fve-digit
 number in a range from 0-9 and store in another array
 */


/* Function Prototypes */

void WinningDigits(int[], int);
bool PlayerDigits(int[], int);
int countMatches(int[], int[], int);
void getNumberString(int);


#include <iostream>
#include <string>
#include <ctime>

using namespace std;

int main()
{
    int PLAYER_SIZE = 5, WINNING_SIZE = 5, i;
    int winningDigits[WINNING_SIZE], playerDigits[PLAYER_SIZE];
    int amountMatching;
    string answer;
    
    do
    {
        cout << "Enter the 5 digits of your lottery number (between 0-9), seperated by blanks: ";
        
        PlayerDigits(playerDigits, 5);
        WinningDigits(winningDigits, 5);
        countMatches(winningDigits, playerDigits, 5);
        
        
        cout << "Winning number: ";
        for (i = 0; i < WINNING_SIZE; i++)
        {
            winningDigits[i] = rand() % 10;
            cout << winningDigits[i] << " ";
        }
        cout << endl;
        
        
        cout << "Your number: ";
        for (i = 0; i < PLAYER_SIZE; i++)
        {
            cout << playerDigits[i] << " ";
        }
        cout << endl << endl;
       
        
        amountMatching = countMatches(winningDigits, playerDigits, 5);
        
        getNumberString(amountMatching);
        
        cout << "\nDo you want to try again? (Y/N) ";
        cin >> answer;
        cout << endl;
        
    } while (answer == "Y" || answer == "y" || answer == "Yes" || answer == "yes" || answer == "YES");
    
    return 0;
}


void WinningDigits(int winningNumbers[], int WINNING_SIZE)
{
    unsigned int seed;
    seed = time(0);
    srand(seed);
}


bool PlayerDigits(int playerNumbers[], int PLAYER_SIZE)
{
    int i;
    
    for ( i = 0; i < PLAYER_SIZE; i++)
    {
        cin >> playerNumbers[i];
    }
    
    for (i = 0; i < PLAYER_SIZE; i++)
    {
        //cout << playerNumbers[i] << " ";                //for validation
        
        while (playerNumbers[i] < 0 || playerNumbers[i] > 9)
        {
            cout << "Please re-enter a valid number for entry #"
            << i + 1 << ": ";
            cin >> playerNumbers[i];
        }
    }
    
    return true;
}


int countMatches(int winningNumbers[], int playerNumbers[], int ARRAY_SIZE)
{
    int i, count = 0;
    for (i = 0; i < ARRAY_SIZE; i ++)
    {
        if (winningNumbers[i] == playerNumbers[i])
        {
            count++;
        }
    }
    return count;
}

void getNumberString(int AmountMatching)
{
    cout << "You have " << AmountMatching << " matching digit(s)" << endl;
}
