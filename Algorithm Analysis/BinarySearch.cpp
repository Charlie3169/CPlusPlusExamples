#include <iostream>

using namespace std;

int BinarySearch(int inputList[], int low, int high, int target)
{    
    if(low > high) //Bootstrap condition - empty list
    {
        return -1;
    }
    else
    {
        int mid = (low + high) / 2; 
        if(target == inputList[mid]) return mid; //Return found index
        
        if(target < inputList[mid])
        {
            BinarySearch(inputList, low, mid -1, target); // Search lower half
        } 
        else
        {
            BinarySearch(inputList, mid + 1, high, target); //Search upper half
        }
    }
    
}

// Divide the search space into n partitions at every step by repeatedly applying an operation (based on n) to a complex number 
// that reduces it. Basically nested hashing
int OmnarySearch(int inputList[], int complexInputSignature, int target)
{

}

int main() 
{  
    int testList[] = {10, 20, 30, 50, 60, 80, 110, 130, 140, 170};
    int testTarget = 110;
    cout << "Index: " << BinarySearch(testList, 0, 9, 110) << endl;


    return 0;
}