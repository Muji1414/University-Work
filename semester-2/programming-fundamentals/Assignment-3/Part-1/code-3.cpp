#include <iostream>
using namespace std;

int calculatePower(int base, int exp);

int main()
{
    int base, exp;
    
    cout << "Enter base and exponent: ";
    cin >> base >> exp;
    
    cout << base << " raised to the power " << exp << " is: " << calculatePower(base, exp);
    
    
    return 0;
}



int calculatePower(int base, int exp)
{
    int ans = 1;
    
    
    for (int i = 0; i < exp; i++)
    {
        ans = ans * base;
    }
    
    
    return ans;
}
