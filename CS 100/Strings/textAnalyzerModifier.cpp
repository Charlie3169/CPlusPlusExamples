#include <iostream>
#include <string>
#include <cstring>
using namespace std;

//Returns the number of characters in usrStr
int GetNumOfCharacters(const string usrStr) 
{
    /*
    int numChar = 0;
    for (size_t i = 0; i < usrStr.size(); i++)
    {    
        if(usrStr.at(i))
        {
            numChar++;
        }
    }
    */

    return usrStr.length();  
   
   
}

string OutputWithoutWhitespace(string usrStr) 
{    
    string newString;
    for (int i = 0; i < usrStr.size(); i++)
    {                    
        if(!isspace(usrStr[i]))
        {
            newString.push_back(usrStr[i]);
        }
    }      

    return newString;
   
}

int main() 
{
    string line;

    cout << "Enter a sentence or phrase:" << endl;
    getline(cin, line);
    cout << endl << "You entered: " << line << endl;
    int numChar = GetNumOfCharacters(line);
    
    cout << endl << "Number of characters: " << numChar << endl;


    cout << "String with no whitespace: " << OutputWithoutWhitespace(line) << endl;

   return 0;
}