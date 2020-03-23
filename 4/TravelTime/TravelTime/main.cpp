/*
 TravelTime.cpp
 CSIT 839 - 26953
 Purpose: to prompt user
 to enter hours and minutes for 2 days
 and use a structure to store hours
 and minutes
*/


#include <iostream>
using namespace std;


/* Structure */

struct TravelTime
{
    int hours;
    int minutes;
} ;


/* Function Prototype */

TravelTime sum(TravelTime t1, TravelTime t2);
void show_time(TravelTime t);



/* Main */

int main()
{
    
    TravelTime Day1, Day2, Day3 = {5, 56};
    
    
    cout << "*** Day 1 Travel ***" << endl;
    cout << "Enter hours for day 1: ";
    cin >> Day1.hours;
    cout << "Enter minutes for day 1: ";
    cin >> Day1.minutes;
    
    cout << endl;
    
    cout << "*** Day 2 Travel ***" << endl;
    cout << "Enter hours for day 2: ";
    cin >> Day2.hours;
    cout << "Enter minutes for day 2: ";
    cin >> Day2.minutes;
    

    /* Display two-day travel */
    cout << "\nYour trip summary for two-day travel: ";
    
    show_time(sum(Day1, Day2));
    
    /* Display three-day travel */
    
    cout << "\n*** Day 3 Travel (given) *** " << endl
    << Day3.hours << " hours, " << Day3.minutes << " minutes" << endl << endl;
    
     cout << "Your trip summary for three-day travel: ";
    
    show_time(sum(sum(Day1, Day2), Day3));
    
    
    return 0;
}

/* Functions */

TravelTime sum(TravelTime t1, TravelTime t2)
{
    TravelTime totalTime;
    int i = 0;
    
    totalTime.hours = t1.hours + t2.hours;
    totalTime.minutes = t1.minutes + t2.minutes;
    
    
    while (i <= totalTime.minutes/60)
    {
        totalTime.hours+= totalTime.minutes/60;
        if (totalTime.minutes/60 >= 1)
        {
            totalTime.minutes = totalTime.minutes % 60;
        }
        
        i++;
    }
    
    return totalTime;
}


void show_time(TravelTime totalTime)
{
    cout << totalTime.hours << " hours, " << totalTime.minutes << " minutes";
    
    cout << endl;
}
