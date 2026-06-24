#include <iostream>
using namespace std;

int calculateLowest(int arr[], int size);

int calculateHighest(int arr[], int size);



int main()
{
    int n;
    
    cout << "Enter number of students: ";
    cin >> n;
    
    int marks[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark: ";
        cin >> marks[i];
    }
    
    cout << "Lowest: " << calculateLowest(marks, n) << endl;
    cout << "Highest: " << calculateHighest(marks, n) << endl;
    
    
    
    return 0;
}



int calculateLowest(int arr[], int size)
{
    int low = arr[0];
    
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < low)
        low = arr[i];
    }
    
    
    return low;
}



int calculateHighest(int arr[], int size)
{
    int high = arr[0];
    
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > high)
        high = arr[i];
    }
    
    
    return high;
}
