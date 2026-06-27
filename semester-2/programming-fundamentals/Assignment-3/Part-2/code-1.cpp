#include <iostream>
using namespace std;

int calculate2Low(int arr[], int size);
int calculate2High(int arr[], int size);

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
    
    cout << "2nd Lowest: " << calculate2Low(marks, n) << endl;
    cout << "2nd Highest: " << calculate2High(marks, n) << endl;
    
    
    return 0;
}



int calculate2Low(int arr[], int size)
{
    int low = arr[0], low2 = arr[1];
    
    if (low2 < low)
    {
        int temp = low;
        low = low2;
        low2 = temp;
    }
    
    
    for (int i = 2; i < size; i++)
    {
        if (arr[i] < low)
        {
            low2 = low;
            low = arr[i];
        }
        
        else if (arr[i] < low2)
        {
            low2 = arr[i];
        }
    }
    
    return low2;
}



int calculate2High(int arr[], int size)
{
    int high = arr[0], high2 = arr[1];
    
    
    if (high2 > high)
    {
        int temp = high;
        high = high2;
        high2 = temp;
    }
    
    
    for (int i = 2; i < size; i++)
    {
        if (arr[i] > high)
        {
            high2 = high;
            high = arr[i];
        }
        
        
        else if (arr[i] > high2)
        {
            high2 = arr[i];
        }
    }
    
    
    return high2;
}
