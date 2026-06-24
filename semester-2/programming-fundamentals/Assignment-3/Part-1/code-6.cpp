#include <iostream>
using namespace std;

int calculateLength(char arr[]);

int main()
{
    char word[100];
    
    cout << "Enter a word: ";
    cin >> word;
    
    cout << "Length of the word is: " << calculateLength(word);
    
    
    
    return 0;
}



int calculateLength(char arr[])
{
    int count = 0;
    
    while (arr[count] != '\0')
    {
        count++;
    }
    
    
    return count;
}
