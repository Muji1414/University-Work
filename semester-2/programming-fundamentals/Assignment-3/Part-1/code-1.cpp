#include <iostream>
using namespace std;

double calculateAverage(int arr[], int size)
{
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    
    double avg = sum / size;
    
    return avg;
}

int main()
{
    int numb;
    
    cout << "Enter number of students: ";
    cin >> numb;
    
    int scores[numb];
    
    for (int i = 0; i < numb; i++)
    {
        cout << "Enter score: ";
        cin >> scores[i];
    }
    
    cout << "Average score: " << calculateAverage(scores, numb);
    
	
	return 0;
}
