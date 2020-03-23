/*
 WordSeparater.cpp
 Co Sci 839 - 26953
 Purpose: to write a program that accepts an
 input as a sentence in which all of the words are
 run together (no spaces), but the first character of
 each word is uppercase. Convert the sentence to a string
 in which the words are separated by spaces and only the first
 word starts with an uppercase letter.
 */

#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

string split(string);


int main()
{
    string stringInput;
    
    cout << "Enter a sentence: ";               // Ask for user input
    cin >> stringInput;                         // Recieve user input
    
    cout << split(stringInput) << endl;         // Function call to split sentence and
                                                // display new sentence
    
    return 0;
}

string split(string finalString)
{
    /* Loop starts at index 1 not 0 because we don't need to add space before the first letter
     of the sentence, also we do not need to turn first letter of sentence into lower case */
    
    for (int i = 1; i < finalString.length(); i++)               // Loop through entire string
    {
        if (isupper(finalString[i]))                            // Search for any capital letters
        {
            /* Because we are adding space characters for every capital letter (except the first) we are adding
             more characters to the string = meaning we need to increment index to accomodate index for space characters */
            
            i++;
            finalString.insert(i - 1, " ");                   // Add space character to the left of every capital letter
            finalString[i] = tolower(finalString[i]);         // Convert all capital letters (except first, why loop starts at
                                                              // index 1 not 0) to lower case
        }
    }
    return finalString;
}
