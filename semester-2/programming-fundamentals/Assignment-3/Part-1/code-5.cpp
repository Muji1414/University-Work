#include <iostream>
#include <string>
using namespace std;

bool findPlayer(string arr[], int size, string target);


int main()
{
    string team[] = {"BobziTheKing", "Rizu", "NaseemBeautyParlor", "Virat", "Stokes", "KLRahul", "JofraArcher", "DeVilliers", "MitchellStarc", "ChrisGayle", "Warner"};
    int size = 11;
    string target;
    
    
    cout << "Enter player name: ";
    cin >> target;
    
    
    if (findPlayer(team, size, target))
    {
    	cout << "Player is in the team";
	}
	
    else
    {
    	cout << "Player not found";
	}
	
	
    return 0;
}

bool findPlayer(string arr[], int size, string target)
{
    
	for (int i = 0; i < size; i++)
    {
    	
        if (arr[i] == target)
        {
        	return true;
		}
    }
    
    
    
    return false;
}
