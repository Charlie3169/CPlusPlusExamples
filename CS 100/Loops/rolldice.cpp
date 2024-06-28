#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

int main() 
{
    bool gameOver = false;

    //Was outputting multiple times per second so had to add in something to change the seed between runs
    int lastRoll = 0;
    

        while(!gameOver)
        {
        
            time_t seed = (time(0) + lastRoll);
            srand(seed);
            
            int firstRoll = rand() % 6 + 1;
            int secondRoll = rand() % 6 + 1;
            int sum = firstRoll + secondRoll;
            lastRoll = sum;

            cout << "Die 1: " << firstRoll << "       Die 2: " << secondRoll << "       Total: " << sum << endl;
        
        
            switch (sum)
            {
                case 7:
                case 9:
                case 11:
                    cout << "You LOST!!" << endl;
                    cout << "Game over." << endl;
                    gameOver = true;
                    break;
                    
                case 2:
                case 3:
                case 5:
                    cout << "You're a WINNER!" << endl;
                    cout << "Game over." << endl;
                    gameOver = true;
                    break;

                case 4:
                case 6:
                case 8:
                case 10:
                case 12:
                    cout << "Let's roll again..." << endl << endl;
                    
                default:
                    break;    
            }
        }
    
    return 0;
}