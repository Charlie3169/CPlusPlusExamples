#include <string>
#include <iostream>

using namespace std;

class abc {
        int x;
    public:
        abc(int c=10) { x= c; };
        ~abc() {cout << x-1 << " "; };
};

void f()
{
    abc a1;
}


int main()
{
    abc a2(20);
    f();
    


}