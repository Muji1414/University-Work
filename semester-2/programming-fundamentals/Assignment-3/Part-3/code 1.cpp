#include <iostream>
using namespace std;

int countEvenNumbers(int arr[], int size);
int countOddNumbers(int arr[], int size);

int main()
{
    int n;
    
    cout << "Enter Size of Array: ";
    cin >> n;
    
    int numbers[n];
    
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value in index " << i << ": ";
        cin >> numbers[i];
    }
    
    cout << "Number of Even Numbers in Array: " << countEvenNumbers(numbers, n) << endl;
    cout << "Number of Odd Numbers in Array: " << countOddNumbers(numbers, n) << endl;
   
   
    return 0;
}



int countEvenNumbers(int arr[], int size)
{
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            count++;
        }
    }
    
    
    return count;
}

int countOddNumbers(int arr[], int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 != 0)
        {
            count++;
        }
    }
    return count;
}
