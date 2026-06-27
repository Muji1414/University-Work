#include <iostream>
using namespace std;

void sortLetters(char arr[], int size);

int main()
{
    char arr[5];
    
    cout << "Enter 5 characters: ";
    
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    
    sortLetters(arr, 5);
    
    cout << "Sorted Letters: ";
    
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    return 0;
}



void sortLetters(char arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
