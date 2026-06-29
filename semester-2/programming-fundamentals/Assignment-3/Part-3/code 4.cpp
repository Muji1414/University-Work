#include <iostream>
using namespace std;

double calculateStrikeRate(int runs, int balls);

int main()
{
    int runs, balls;
    
    cout << "Enter runs and balls: ";
    cin >> runs >> balls;
    
    cout << "Strike Rate: " << calculateStrikeRate(runs, balls);
    
	
	return 0;
}



double calculateStrikeRate(int runs, int balls)
{
    double rate = ((double)runs / balls) * 100;
    
    
    return rate;
}
