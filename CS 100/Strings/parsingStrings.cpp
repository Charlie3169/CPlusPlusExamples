#include <iostream>
#include <string>
using namespace std;


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
    bool good = false;
    string line;
    
              
       
    

        
        while(!good)
        {
            cout << "Enter input string:" << endl;  
            getline(cin, line);
            
            if(line == "q")
            {
                good = true;
                break;
            }
            else if(line.find(',') != string::npos)
            {                                
                cout << "First word: " << OutputWithoutWhitespace(line.substr(0, line.find(','))) << endl;
                cout << "Second word: " << OutputWithoutWhitespace(line.substr(line.find(',') + 1, line.length())) << endl << endl;
            }
            else
            {
                cout << "Error: No comma in string." << endl << endl;                 
            }
            

            

        }

        
        
    
    


    
   
   
    
   return 0;
}