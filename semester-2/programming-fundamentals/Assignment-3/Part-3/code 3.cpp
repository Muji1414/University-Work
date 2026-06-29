#include <iostream>
using namespace std;

int findGCD(int a, int b);

int main()
{
    cout << findGCD(48, 18);
    
    
    return 0;
}

int findGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        
        b = a % b;
        a = temp;
    }
    
    return a;
}
