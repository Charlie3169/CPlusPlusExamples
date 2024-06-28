#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    int nrows;
    int power = 0;


    cout << "Enter the number of table rows: ";
    cin >> nrows;


    cout << "    x     log10(x)       log2(x)       ln(x)" << endl;
    for (int i = 1; i < nrows; i = i + pow(10,power))
    {
        cout << setprecision(9) << fixed << setw(5) << i << "   " << setw(5) << log10(i) << "   " << setw(5)  << log2(i) << "   " << setw(5) << log(i) << endl;
        if(log10(i) >= (power + 1))
        {
            power++;
        }

    }
    




    return 0;
}