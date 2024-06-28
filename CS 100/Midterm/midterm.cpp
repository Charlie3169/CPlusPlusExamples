#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void calcFee(const double &hrs, double &fee)
{
    double minFee = 2, hourlyRate = 0.5;

    if (hrs <= 3)
    {
        fee = minFee;
    }    
    else
    {
        fee = minFee + (hrs - 3) * hourlyRate;
    }

    if(fee > 10)
    {
        fee = 10;
    }
    
}

double getMeSomePi(const size_t &nterm) 
{
   double piVal = 0;
   double numerator = 4, denominator = 1;

   if(nterm > 0)
   {

       for (int i = 0; i < nterm; i++)
       {    
           
           if(i % 2 == 0)
           {
               piVal += numerator / (denominator + (i * 2));
           }
           else
           {
               piVal -= numerator / (denominator + (i * 2));
           }          
       
       }
   }
   else
   {
       return -1;
   } 
   
   
   return piVal;


}

const double PI = 3.141592654;
const double AREA_OF_SLICE = 14.125; //sq. in.

bool number_of_Pizzas(int people_count, int number_of_slices_per_person, double diameter, int &pizza_count)
{
    
    int slicesNeeded = people_count * number_of_slices_per_person;
    
    double numSlices = (pow((diameter / 2), 2)  * PI) / AREA_OF_SLICE;
    if(numSlices < 1)
    {
        return false;
    }

    double totalSlices = numSlices * pizza_count;

    if(slicesNeeded > totalSlices) 
    {
        return false;
    }
    else
    {
        return true;
    }   


}



double unbiasedAvg(const double data[], const unsigned int size) 
{
    
    double sum = 0;
    size_t minLoc = 0, maxLoc = 0;


    for (size_t i = 0; i < size; i++)
    {
        if(data[maxLoc] < data[i])
        {            
            maxLoc = i;
        }             

    }

    for (size_t i = 0; i < size; i++)
    {
        if(data[minLoc] > data[i])
        {
            minLoc = i;
        }

    }

    for (size_t i = 0; i < size; i++)
    {
        if(i != minLoc && i != maxLoc)
        {
            sum += data[i];
        }
    }
    

    return (sum / size); 
   


}


int numMultiples(int nums[], const unsigned len, const int base)
{
    int numMultiples = 0;

    if(base == -1 || base == 0 || base == 1)
    {
        return len;
    }
    
    for (int i = 0; i < len; i++)
    {
        if(nums[i] % base == 0)
        {
            numMultiples++;
        }
    }
    return numMultiples;  
   


}

double digitsMean(const unsigned &k)
{
    double sum = 0;
    int testK = k;
    int numIterations = 0;
        
    if(k == 0)
    {
        return 0;
    }

    while(testK != 0)
    {
        sum += testK % 10;
        testK /= 10;        
        numIterations++;       
    }

    return sum / numIterations;   

}



int enough (int goal)
{
    int currentVal = 0;
    int numIterations = 0;

    if(goal <= 0)
    {
        return goal;
    }

    while(currentVal < goal)
    {
        numIterations++;
        currentVal += numIterations;
    }

    if(currentVal > goal)
    {
        numIterations--;
    }

    return numIterations;     


}


int halfTreeSum (int height)
{
    int sum = 0;
    for (int i = 0; i < height; i++)
    {
        sum += (height - i) * (i + 1);
    }
    return sum;
}








int main() 
{
    size_t nterm = 2;
    cout << fixed << setprecision(4) << getMeSomePi(nterm);    



    return 0;
}