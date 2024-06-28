#include <iostream>
// FIXME include the string library
using namespace std;

int main() 
{
    string line;

    cout << "Enter text:" << endl;
    getline(cin, line);
    cout << "You entered: " << line << endl;
    cout << "Expanded: ";

    if(line.find("BFF") != string::npos)
    {
        line.replace(line.find("BFF"),3, "best friend forever");        
    }

    if(line.find("IDK") != string::npos)
    {
        line.replace(line.find("IDK"),3, "I don't know");             
    }

    if(line.find("JK") != string::npos)
    {
        line.replace(line.find("JK"),2, "just kidding");               
    }

    if(line.find("TMI") != string::npos)
    {
        line.replace(line.find("TMI"),3, "too much information");                   
    }

    if(line.find("TTYL") != string::npos)
    {
        line.replace(line.find("TTYL"),4, "talk to you later");                
    }

    cout << line << endl;



   

   return 0;
}