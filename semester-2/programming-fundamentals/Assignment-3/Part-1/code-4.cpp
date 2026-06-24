#include <iostream>
using namespace std;

double calculateVoltage(double current, double resistance);

int main()
{
    double current, resistance;
    
    cout << "Enter current and resistance: ";
    cin >> current >> resistance;
    
    cout << "Total Voltage: " << calculateVoltage(current, resistance) << " V";
    
	
	return 0;
}




double calculateVoltage(double current, double resistance)
{
    double volt = current * resistance;
    
    return volt;
}
