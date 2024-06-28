#include <iostream>
// FIXME include the string library
using namespace std;

int main() 
{
    string line;

    cout << "Enter text:" << endl;
    getline(cin, line);
    cout << "You entered: " << line << endl;

    if(line.find("BFF") != string::npos)
    {
        cout << "BFF: best friend forever" << endl;
    }

    if(line.find("IDK") != string::npos)
    {
        cout << "IDK: I don't know" << endl;
    }

    if(line.find("JK") != string::npos)
    {
        cout << "JK: just kidding" << endl;
    }

    if(line.find("TMI") != string::npos)
    {
        cout << "TMI: too much information" << endl;
    }

    if(line.find("TTYL") != string::npos)
    {
        cout << "TTYL: talk to you later" << endl;
    }

   

   return 0;
}