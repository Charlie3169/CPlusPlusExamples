#include <iostream>
#include <string>

using namespace std;





int GetNumOfNonWSCharacters(const string myStr)
{
    int count = 0;
    for (int i = 0; i < myStr.size(); i++)
    {                    
        if(!isspace(myStr[i]))
        {
            count++;
        }
    }      

    return count;

}

string ReplaceExclamation(string myStr)
{
    for (int i = 0; i < myStr.size(); i++)
    {                    
        if(myStr[i] == '!')
        {
            myStr[i] == '.';
        }
    }    

    return myStr;
}

string ShortenSpace(string myStr) 
{
    string newString;
    for (int i = 0; i < myStr.size() - 1; i++)
    {                    
        if(isspace(myStr[i]) && isspace(myStr[i + 1]))
        {
            newString.push_back(myStr[i]);
            i++;
        }
        newString.push_back(myStr[i]);
    } 
    
    return newString;

}

int GetNumOfWords(const string myStr)
{
    int count = 0;
    string newStr = ShortenSpace(myStr);
    for(int i = 0; i < newStr.size(); i++)
    {                    
        if(isspace(newStr[i]))
        {
            count++;
        }
    }      

    return count + 1;

}

int FindText(string &find, string userText)
{
    
    int pos = userText.find(find);
    int count = 0;
    while(pos != string::npos)
    {
        count++;        
        pos = userText.find(find, pos + 1);
    }

    return count;
    
}

void PrintMenu(string &userStr)
{
    bool isRunning = true;  
    char userChar;

    
    while(isRunning)
    {    
        userChar = 'a';

        cout << "MENU" << endl;
        cout << "c - Number of non-whitespace characters" << endl;
        cout << "w - Number of words" << endl;
        cout << "f - Find text" << endl;
        cout << "r - Replace all !'s" << endl;
        cout << "s - Shorten spaces" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Choose an option:" << endl;

        cin >> userChar;
        string find;   

        switch(userChar)
        {
            case 'c': 
                cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(userStr) << endl << endl;

                break;              
            case 'w':
                cout << "Number of words: " << GetNumOfWords(userStr) << endl;                

                break;
            case 'f':
                
                cout << "Enter a word or phrase to be found:" << endl;
                getline(cin, find);                             
                cout << "\"" << find << "\" instances: " << FindText(find, userStr) << endl << endl;

                break;
            case 'r':
                
                cout << "Edited text: " << ReplaceExclamation(userStr) << endl << endl;;

                break;
            case 's':
                ShortenSpace(userStr);
                cout << "Edited text: " << userStr << endl << endl;

                break;            
            case 'q':

                isRunning = false;
                break;

            default:
                break;
        }

    }

}

int main() 
{
    string line;
    cout << "Enter a sample text:" << endl << endl;
    getline(cin, line);
    
    cout << "You entered: " << line << endl << endl;
    PrintMenu(line);
   

   return 0;
}