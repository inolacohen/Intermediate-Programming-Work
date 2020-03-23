/*
 PopulationStatistics.cpp
 Nov 8, 2018
 CO SCI 839 - 26953
 Purpose: to ask user for city name,
 total population, number of births
 and deaths annually, and to calculate
 the birth and death rates
 population statistics with those values.
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <iomanip>
using namespace std;


class Pop {
    
private:
    long population;                        // Current population
    int numBirths;                          // Annual number of births
    int numDeaths;                          // Annual number of deaths
    
public:
    Pop() {                                 // default constructor
        
        population = 100;
        numBirths = 0;
        numDeaths = 0;
        
    };
    
    Pop(long p, int b, int d) {            // overloaded constructor
        
        population = p;
        numBirths = b;
        numDeaths = d;
    };
   
    /* Setter Function(s) */
    void setPopulation(long);
    void setBirths(int);
    void setDeaths(int);
    
    /* Getter Function(s) */
    long getPopulation();
    double getBirthRate();
    double getDeathRate();
    
};



/* Main */
int main()
{
    Pop Population;
    string townName;
    long totalPop;
    int births, deaths;
    
    string answer;
    
    do {
        cout << "Enter a town name: ";
        getline(cin, townName);                                                         // get user's town name
        
        cout << "Enter total population in " << townName << ": ";                       // population size from user
        cin >> totalPop;
        
        
        Population.setPopulation(totalPop);                                        // set population size in Population object
        
        cout << "Enter annual number of births: ";
        cin >> births;
        Population.setBirths(births);                                             // set number of births in Population object
        
        cout << "Enter annual number of deaths: ";
        cin >> deaths;
        Population.setDeaths(deaths);                                            // set number of deaths in Population object
        
        cout << "\nPopulation Statistics of " << townName << "\n" << endl;
        cout << "Population: " << Population.getPopulation() << endl;           // retrieve population size, call get function
        cout << setprecision(2) << fixed << showpoint;
        cout << "Birth Rate: " << Population.getBirthRate() * 100 << "%" << endl;      // retrieve birth rate call get function
        cout << "Death Rate: " << Population.getDeathRate() * 100 << "%" << endl;      // retrieve birth rate, call get function

        cout << "Another town? (Y/N) ";                                                // Ask to create new object
        cin >> answer;
        
        cin.clear();
        cin.ignore(10000, '\n');
        
    
    } while (answer == "y"|| answer == "Y"|| answer == "yes"|| answer == "Yes"|| answer == "YES");
    
    
    return 0;
}



/* Setter Functions */
void Pop::setPopulation(long p)                   // Set population size in object
{
    if (p < 100)
    {
        cout << "Invalid population. Using default population size of 100" << endl;
        population = 100;
    }
    else
        population = p;
}


void Pop::setBirths(int b)                        // Set number of births in object
{
    if (b >= 0)
    {
        numBirths = b;
    }
    else
    {
        cout << "Invalid number of births. Setting it to 0" << endl;
        numBirths = 0;
    }
    
}


void Pop::setDeaths(int d)                        // Set number of deaths in object
{
    if (d >= 0)
    {
        numDeaths = d;
    }
    else
    {
        cout << "Invalid number of deaths. Setting it to 0" << endl;
        numDeaths = 0;
    }
}



/* Getter Functions */
long Pop::getPopulation()
{
    return population;                            // Retrieve population from Population object
}


double Pop::getBirthRate()
{
    return (numBirths / double (population));     // Calculate and return birth rate, need to
                                                  // convert population to type double
                                                  // in order to divide
}


double Pop::getDeathRate()
{
    return (numDeaths / double (population));     // Calculate and return death rate, need to
                                                  // convert population to type double
                                                  // in order to divide
}
