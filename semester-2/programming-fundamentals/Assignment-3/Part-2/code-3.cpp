#include <iostream>
using namespace std;

double celsiusToFahrenheit(double c);

int main()
{
    double temp;
    
    cout << "Enter temperature in Celsius: ";
    cin >> temp;
    
    cout << "Fahrenheit: " << celsiusToFahrenheit(temp) << endl;
    
    
    return 0;
}



double celsiusToFahrenheit(double c)
{
    double f = (c * 9 / 5) + 32;
    
    return f;
}
