#include <iostream>


using namespace std;

int main() 
{
    string line;

    cout << "Input an abbreviation:" << endl;
    getline(cin, line);

    bool strFound = false;
    
    if(line.find("LOL") != string::npos)
    {
        cout << "laughing out loud" << endl;
        strFound = true;
    }

    if(line.find("IDK") != string::npos)
    {
        cout << "I don't know" << endl;
        strFound = true;
    }

    if(line.find("BFF") != string::npos)
    {
        cout << "best friends forever" << endl;
        strFound = true;
    }

    if(line.find("IMHO") != string::npos)
    {
        cout << "in my humble opinion" << endl;
        strFound = true;
    }

    if(line.find("TMI") != string::npos)
    {
        cout << "too much information" << endl;
        strFound = true;
    }

    if(!strFound)
    {
        cout << "Unknown" << endl;
    }

    

   

   return 0;
}