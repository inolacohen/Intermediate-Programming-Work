/*
 September 9, 2018
 CSIT 839 - 26953
 Longest String
 Purpose: to prompt the user to enter
 two strings without spaces. The program
 returns the longest string among two strings.
 */

#include <iostream>
#include <string>
using namespace std;

/* Function Prototypes */

string AskFirstString();                                        /* ask user to enter first string,
                                                                 also validates users input if there a space */

string AskSecondString();                                /* ask user to enter second string,
                                                                validate if there is a space */

string Longest(const string&, const string&);                  /* main program passes the two strings
                                                               without spaces to this function; this
                                                               function will then return the longer
                                                               string value to main function */
/* Functions */

int main() {                                                /* will determine and display the longest
                                                               string or if the strings are equal */
    
    string s1, s2, longest, answer;
    
    cout << "I will display the longest string among the two strings that you enter." << endl;
    
    do
    {
        s1 = AskFirstString();
        
        s2 = AskSecondString();
        
        longest = Longest(s1, s2);
        
        
        /* For validation purposes */
        /*cout << s1 << endl;
        cout << s2 << endl;
        cout << longest << endl;*/
        
        if (s1.size() > s2.size())
        {
            cout << "\n" << s1 << " is the longest string among your two entries, having " << s1.size() << " character(s)!\n" << endl;
        }
        else if (s2.size() > s1.size())
        {
            cout << "\n" << s2 << " is the longest string among your two entries, having " << s2.size() << " character(s)!\n" << endl;
        }
        else
        {
            cout << "\nBoth strings have equal length with " << s1.size() << " character(s)!\n" << endl;
        }
        
        cout << "Would you like to try again? (Y/N) ";
        getline(cin, answer);
        
        /* while (answer != "y" || answer != "Y" || answer != "yes" || answer != "Yes" || answer != "YES" || answer != "n" || answer != "N" || answer != "no" || answer != "No" || answer != "NO")
        {
            cout << "Sorry I do not recognize what you want. Please enter again: ";
            getline(cin, answer);
        } */
        
    } while (answer == "y" || answer == "Y" || answer == "yes" || answer == "Yes" || answer == "YES");
    return 0;
}


string AskFirstString()
{
    string string1;
    int space1;
    
    cout << "\nEnter the first string without space characters: ";
    getline(cin, string1);
    
    do
    {
        space1 = string1.find(' ', 0);

        if (space1  > 0)
        {
            /*cout << string1.find(' ', 0) << endl;                             For validation*/
            cout << "\nSorry, your first string has a space character, try again: ";
            getline(cin, string1);
        }
    } while (space1 > 0);
    
    return string1;
}


string AskSecondString()
{
    string string2;
    
    cout << "\nEnter the second string without space characters: ";
    getline(cin, string2);
    
    while (string2.find(' ', 0) != -1)
    {
        /*cout << string2.find(' ', 0) << endl;                        For validation*/
        cout << "\nSorry, your second string has a space character, try again: ";
        getline(cin, string2);
    }
  
    return string2;
}

string Longest(const string& s1, const string& s2)
{
    string longest;
    
    /*cout << s1.size() << endl;
    cout << s2.size() << endl;*/
    
    if (s1.size() > s2.size())
    {
        longest = s1;
    }
    else
    {
        longest = s2;
    }
   
    return longest;
}
