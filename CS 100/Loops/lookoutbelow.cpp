#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    const int G = 32; //Gravitational constant
    const double CD = 0.0012; //Drag coeffiecient
    const double TIME_INTERVAL = 0.001;
    const double EPSILION = 0.01; //tolerance
    
    double x, velocity = 0;

    
    //Friends time to reach strike point and time for balloon to reach ground
    double time1, time2;       
    

    double verDist, walkSpeed, horDist;    
    
    cout << "Please input the walking distance from your friend to the strike point (ft)" << endl;
    cin >> horDist;
    cout << "Please input your friend's walking speed (ft/sec): " << endl;
    cin >> walkSpeed;    
    cout << "Please input your height above your friend (ft): " << endl;
    cin >> verDist;
    
    int numIterationsTime2 = 0;
    while(x < verDist)
    {
        velocity = velocity - (CD * velocity - G) * TIME_INTERVAL;
        x = x + velocity * TIME_INTERVAL; 

        ++numIterationsTime2;
    }
    time2 = numIterationsTime2 * TIME_INTERVAL;



    int numIterationsTime1 = 0;
    while(horDist > 0)
    {
        horDist = horDist - walkSpeed * TIME_INTERVAL;
                
        ++numIterationsTime1;
    }

    time1 = numIterationsTime1 * TIME_INTERVAL;


    cout << "It will take " << setprecision(2) << fixed  << time1 << " seconds for them to reach the balloon point" << endl;
    cout << "It will take " << setprecision(2) << fixed << time2 << " seconds for your balloon to travel to the ground" << endl;
    if(fabs(time1 - time2) <= EPSILION)
    {
        cout << "Bingo, you hit your friend successfully" << endl;
    }
    else if(time1 - time2 <= 0)
    {
        cout << "It is too late to drop your balloon" << endl;
    }
    else
    {
        cout << "If you wait " << setprecision(2) << fixed << time1 - time2 << " seconds, you will hit them" <<endl;
    }      


    return 0;
}