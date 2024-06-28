#include <iostream>
#include <cmath>

using namespace std;

void InputFractions(int & Num1, int & Denom1, int & Num2, int & Denom2, int & Num3, int & Denom3, int & Num4, int & Denom4)
/* This function will allow the user to enter four fractions. */
{
        cout << "Please enter four fractions" << endl;
        //Used for loop to reduce repetitiveness at the cost of needing to use a switch statement
        for(int i = 1; i < 5; ++i)
        {
            int tempNum = 0;
            int tempDenom = 0;
            while(true)
            {
                cout << "Enter numerator #" << i << ": ";
                switch(i)
                {
                    case 1:
                        cin >> Num1;
                        tempNum = Num1;
                        break;
                    case 2:
                        cin >> Num2;
                        tempNum = Num2;
                        break;
                    case 3:
                        cin >> Num3;
                        tempNum = Num3;
                        break;
                    case 4:
                        cin >> Num4;
                        tempNum = Num4;
                        break;                        
                }
                
                if(tempNum >= 0)
                {
                    break;
                }
                else
                {
                    cout << "Numerator must not be negative!" << endl;
                }
            }

            while(true)
            {
                cout << "Enter denominator #" << i << ": ";
                switch(i)
                {
                    case 1:
                        cin >> Denom1;
                        tempDenom = Denom1;
                        break;
                    case 2:
                        cin >> Denom2;
                        tempDenom = Denom2;
                        break;
                    case 3:
                        cin >> Denom3;
                        tempDenom = Denom3;
                        break;
                    case 4:
                        cin >> Denom4;
                        tempDenom = Denom4;
                        break;                        
                }                

                if(tempDenom > 0)
                {
                    break;
                }
                else if(tempDenom == 0)
                {
                    cout << "Denominator must not be zero" << endl;
                }
                else if(tempDenom < 0)
                {
                    cout << "Denominator must not be negative!" << endl;
                }
            }

        }        
        cout << endl;
}


int GreatestCommonFactor(int n1, int n2)
{
    //GCF of Num and Denom is the number to reduce both
    if(n2 > n1)
    {
        //Preserves order to keep the code simpler
        int temp = n2;
        n2 = n1;
        n1 = temp;
    }

    //Euclid's Algorithm
    while (n2 != 0)
    {
        int temp = n2;
        n2 = n1 % n2;
        n1 = temp;
    }
    return n1;
}

void Reduce1(int & Num, int & Denom)
{
    int c1 = GreatestCommonFactor(Num, Denom);    

    Num /= c1;
    Denom /= c1;    
}

void Reduce1Print(int & Num, int & Denom)
{
    //Useful to have a separate print so that Reduce1 can be used on its own
    int oldNum = Num;
    int oldDenom = Denom;

    Reduce1(Num, Denom);              

    cout << oldNum << "/" << oldDenom << " is reduced to " << Num << "/" << Denom << endl;    
}

void Reduce2(int & Num, int & Denom, int & leadingTerm)             
{        
    Reduce1(Num, Denom);
            
    leadingTerm = Num / Denom; 
    Num = Num % Denom;    
}

void Reduce2Print(int & Num, int & Denom, int & leadingTerm)                  
{    
    int oldNum = Num;
    int oldDenom = Denom;    

    Reduce2(Num, Denom, leadingTerm);

    cout << oldNum << "/" << oldDenom << " is reduced to " << leadingTerm << " and " << Num << "/" << Denom << endl; 
}

void ReverseReduce2(int & Num, int & Denom, int & leadingTerm)   
{
    //Undoes Reduce2 to keep things simple; otherwise value would be lost in the leading digits
    if(leadingTerm > 0)
    {
        Num = Num + leadingTerm * Denom;  
        leadingTerm = 0;      
    }
}


void AddFractions(int & Num1, int & Denom1, int & leadingTerm1, int & Num2, int & Denom2, int & leadingTerm2)
{
    int oldNum2 = Num2;
    int oldDenom2 = Denom2;

    ReverseReduce2(Num1, Denom1, leadingTerm1);
    ReverseReduce2(Num2, Denom2, leadingTerm2);
    
    cout << "Sum of " << Num1 << "/" << Denom1 << " and " << Num2 << "/" << Denom2 << " is "; 

    if (Denom1 != Denom2)
    {
            Num1 = Num1 * Denom2;
            Num2 = Num2 * Denom1;
            Denom1 = Denom1 * Denom2;
            Denom2 = Denom2 * Denom1;
            Num1 = Num1 + Num2;
    }
    else
    {
            Num1 = Num1 + Num2;
    }

    //Undoes the state change in the second fraction
    Num2 = oldNum2;
    Denom2 = oldDenom2;

    cout << Num1 << "/" << Denom1 << endl; 

    //Used to display the change in the new fraction
    int oldNum1 = Num1;
    int oldDenom1 = Denom1;    

    Reduce1(Num1, Denom1);
    cout << oldNum1 << "/" << oldDenom1 << " reduced by reduce1 is " << Num1 << "/" << Denom1 << endl;

    Reduce2(Num1, Denom1, leadingTerm1);
    cout << oldNum1 << "/" << oldDenom1 << " reduced by reduce2 is " << leadingTerm1 << " and " << Num1 << "/" << Denom1 << endl << endl;
    ReverseReduce2(Num1, Denom1, leadingTerm1);
}

bool IsGreater(int & Num1, int & Denom1, int & Num2, int & Denom2)
{
    double f1 = (double) Num1 / Denom1;
    double f2 = (double) Num2 / Denom2;

    if(f1 > f2)
    {
        cout << Num1 << "/" << Denom1 << " is greater than " << Num2 << "/" << Denom2 << endl;
        return true;
    }
    else
    {
        cout << Num1 << "/" << Denom1 << " is (not) greater than " << Num2 << "/" << Denom2 << endl;
        return false;
    }    
}

void FracPower(int & Num, int & Denom, int Power)
{
    int oldNum = Num;
    int oldDenom = Denom;  

    Num = pow(Num, Power);
    Denom = pow(Denom, Power);

    cout << oldNum << "/" << oldDenom << " raised to power " << Power << " is " << Num << "/" << Denom << endl;
}


int main()
{
    char answer;
    do
    {

            int Num1, Denom1, Num2, Denom2, Num3, Denom3, Num4, Denom4 = 0;
            int leadingTerm1, leadingTerm2, leadingTerm3, leadingTerm4 = 0;            

            InputFractions(Num1, Denom1, Num2, Denom2, Num3, Denom3, Num4, Denom4);

            Reduce1Print(Num1, Denom1);
            Reduce1Print(Num2, Denom2);
            Reduce1Print(Num3, Denom3);
            Reduce1Print(Num4, Denom4);

            cout << endl;

            Reduce2Print(Num1, Denom1, leadingTerm1);
            Reduce2Print(Num2, Denom2, leadingTerm2);
            Reduce2Print(Num3, Denom3, leadingTerm3);
            Reduce2Print(Num4, Denom4, leadingTerm4);

            cout << endl;

            AddFractions(Num1, Denom1, leadingTerm1, Num2, Denom2, leadingTerm2);
            AddFractions(Num1, Denom1, leadingTerm1, Num3, Denom3, leadingTerm3);
            AddFractions(Num2, Denom2, leadingTerm2, Num3, Denom3, leadingTerm3);
            AddFractions(Num2, Denom2, leadingTerm2, Num4, Denom4, leadingTerm4);
            
            IsGreater(Num1, Denom1, Num2, Denom2);
            IsGreater(Num1, Denom1, Num3, Denom3);
            IsGreater(Num2, Denom2, Num4, Denom4);
            IsGreater(Num3, Denom3, Num4, Denom4);

            cout << endl;

            FracPower(Num1, Denom1, 4);
            FracPower(Num2, Denom2, 3);
            FracPower(Num3, Denom3, 2);
            FracPower(Num4, Denom4, 1);           

            cout << endl;

            cout <<"Would you like to do another set of fractions? ";
            cin >> answer;
            cout << endl;

    } while ((answer == 'y') || (answer == 'Y'));

    return(0);

}
