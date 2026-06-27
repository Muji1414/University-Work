#include <iostream>
using namespace std;

int countVowels(char arr[]);

int main()
{
    char word[100];
    
    cout << "Enter a word: ";
    cin >> word;
    
    
    cout << "Total Vowels: " << countVowels(word) << endl;
    
    
    return 0;
}



int countVowels(char arr[])
{
    int count = 0;
    int i = 0;
    
    
    while (arr[i] != '\0')
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        {
            count++;
        }
        
        i++;
    }
    
    
    return count;
}
