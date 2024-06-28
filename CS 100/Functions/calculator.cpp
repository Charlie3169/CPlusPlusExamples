
#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

///////////////////////////////////////////////////////////////////////////
// Function definitions get pasted below
///////////////////////////////////////////////////////////////////////////
 
// calculator implementation...
bool calculate(int iselect, double x, double y, double& result) 
{   
    // simulate simple calculator operation   
    // paste body of your calculate function here
    
    bool keepGoing = false;

    do
    {  

        cout << "MENU" << endl;
        cout << "\t1. Add" << endl;
        cout << "\t2. Subtract" << endl;
        cout << "\t3. Multiply" << endl;
        cout << "\t4. Divide" << endl;
        cout << "\tEnter your choice: "; 
        cin >> iselect;

        cout << "Enter your two numbers: ";
        cin >> x;
        cin >> y;

        switch(iselect)
        {
            case 1:
                result = x + y;
                cout << "\nResult: " << result << endl;
                break;

            case 2:
                result = x - y;
                cout << "\nResult: " << result << endl;
                break;

            case 3:
                result = x * y;
                cout << "\nResult: " << result << endl;
                break;

            case 4:
                if(y != 0)
                {
                    result = x / y;
                    cout << "\nResult: " << result << endl;
                    break;
                }
                else
                {
                    cout << "Y cannot be zero!" << endl;
                    return false;
                }                               

            default:
                cout << "Invalid Selection!" << endl;
                return false;               

        }

        cout << "Continue? ";      
        char cont;  
        cin >> cont;      

        if(cont == 'y')
        {
            keepGoing == true;
        }
        else
        {
            keepGoing == false;            
        }
    
    }while(keepGoing);  

    return true;    



}


// whichQuadrant implementation...
int whichQuadrant (const double& x, const double& y) 
{
    // determine quadrant for specified point coordinates
    // paste body of your whichQuadrant function here
    if(x > 0)
    {        
        if(y > 0)
        {        
            return 1;
        }
        else if(y == 0)
        {
            return 100;
        }
        else
        {
            return 4;
        }

    }
    else if(x == 0)
    {
        if(y == 0)
        {        
            return 0;
        }
        else
        {
            return -100;
        }        
    }
    else
    {
        if(y > 0)
        {        
            return 2;
        }
        else if(y == 0)
        {
            return 100;
        }
        else
        {
            return 3;
        }        

    }


    


} 


// determineSubstance implementation...
string determineSubstance(const double& input_boilingpoint) 
{
    // determine specific materials/substances
    // paste body of your determineSubstance function here
    const int WATER = 100;
    const int MECURY = 357;
    const int COPPER = 1187;
    const int SILVER = 2193;
    const int GOLD = 2660;

    if(input_boilingpoint < WATER * 1.05 && input_boilingpoint > WATER * 0.95)
    {   
        return "Water";
    }
    else if(input_boilingpoint < MECURY * 1.05 && input_boilingpoint > MECURY * 0.95)
    {
        return "Mecury";
    }
    else if(input_boilingpoint < COPPER * 1.05 && input_boilingpoint > COPPER * 0.95)
    {
        return "Copper";
    }
    else if(input_boilingpoint < SILVER * 1.05 && input_boilingpoint > SILVER * 0.95)
    {
        return "Silver";
    }
    else if(input_boilingpoint < GOLD * 1.05 && input_boilingpoint > GOLD * 0.95)
    {
        return "Gold";
    }
    else 
    {
        return "Unknown Substance";
    }




}


// compareDelta implementation...
bool compareDelta(const double& number1, const double& number2, const double& delta) 
{
    // evaluate equality of floating-point numbers   
    // paste body of your compareDelta function here
   
}

int main(void) 
{
    //double result;
    //int iselect;
    //double x, y;
    //calculate(iselect, x, y, result);

    //double x1, y1;
    //cin >> x1;
    //cin >> y1;
    //cout << whichQuadrant(x1,y1);
    
    double t;
    cin >> t;
    cout << determineSubstance(t);
    
}

