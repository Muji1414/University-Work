#include <iostream>
using namespace std;

int calculateSum(int arr[], int size);

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
    
    cout << "Sum: " << calculateSum(marks, n) << endl;
    
    
    return 0;
}



int calculateSum(int arr[], int size)
{
    int sum = 0;
    
    for (int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    
    
    return sum;
}
