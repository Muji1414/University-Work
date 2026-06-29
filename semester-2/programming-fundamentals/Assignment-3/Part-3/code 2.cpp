#include <iostream>
using namespace std;


int main()
{
    int r, c;
    
    cout << "Enter rows and columns: ";
    cin >> r >> c;
    
    
    int seats[r][c];
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << "Enter roll number: ";
            cin >> seats[i][j];
        }
    }
    
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << seats[i][j] << " ";
        }
        
        cout << endl;
    }
    
    
    return 0;
}
