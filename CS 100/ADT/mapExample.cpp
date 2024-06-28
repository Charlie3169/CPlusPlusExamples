#include <iostream>
#include <map>
#include <string>

using namespace std;

int main () 
{
    
    map<string, int> statePopulation;

    // 2013 population data from census.gov
    statePopulation.emplace("CA", 38332521);
    statePopulation.emplace("AZ", 6626624);
    statePopulation.emplace("MA", 6692824);

    cout << "Population of Arizona in 2013 is "
            << statePopulation.at("AZ")
            << "." << endl;

    // 2014 estimated population
    statePopulation.at("AZ") = 6871809;

    cout << "Population of Arizona in 2014 is "
            << statePopulation.at("AZ")
            << "." << endl;


    //Example 2
    map<int, double> raceTimes;
    int userDistKm;
        
    raceTimes.emplace(5, 23.14);
    raceTimes.emplace(15, 78.5);
    raceTimes.emplace(25, 120.75);
        
    cout << "Enter race distance in km (0 to exit): " << endl;
    cin >> userDistKm;

    while(userDistKm != 0) 
    {
        
        cout << "Best time for " << userDistKm << " km race is: "
            << raceTimes.at(userDistKm)
            << " minutes." << endl << endl;
            
        cout << "Enter race distance in km (0 to exit): " << endl;
        cin >> userDistKm;      
   }

   return 0;
}