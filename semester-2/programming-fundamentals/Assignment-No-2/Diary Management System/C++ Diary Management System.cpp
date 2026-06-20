#include <iostream>
#include <string>

using namespace std;

// Global variables
string savedUsername;
string savedPassword;

string diaryTitles[20];
string diaryContents[20];

int totalEntries = 0;

// Function prototypes
void registerUser();
bool loginUser();
int displayMenu();
void createEntry();
void viewAllEntries();
void readFullEntry();
void editEntry();
void deleteOneEntry();
void deleteAllEntries();

int main()
{
    cout << "========== PERSONAL STUDENT DIARY ==========\n";

    registerUser();

    if (!loginUser())
    {
        cout << "\nLogin Failed!\n";
        return 0;
    }

    int choice;

    do
    {
        choice = displayMenu();

        switch (choice)
        {
            case 1:
                createEntry();
                break;

            case 2:
                viewAllEntries();
                break;

            case 3:
                readFullEntry();
                break;

            case 4:
                editEntry();
                break;

            case 5:
                deleteOneEntry();
                break;

            case 6:
                deleteAllEntries();
                break;

            case 7:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}

// Register user
void registerUser()
{
    cout << "\n------- REGISTER USER -------\n";

    cout << "Enter Username: ";
    getline(cin, savedUsername);

    while (savedUsername == "")
    {
        cout << "Username cannot be empty. Enter again: ";
        getline(cin, savedUsername);
    }

    cout << "Enter Password: ";
    getline(cin, savedPassword);

    while (savedPassword == "")
    {
        cout << "Password cannot be empty. Enter again: ";
        getline(cin, savedPassword);
    }

    cout << "\nRegistration Successful!\n";
}

// Login user
bool loginUser()
{
    string username;
    string password;

    cout << "\n--------- LOGIN ---------\n";

    cout << "Enter Username: ";
    getline(cin, username);

    cout << "Enter Password: ";
    getline(cin, password);

    if (username == savedUsername && password == savedPassword)
    {
        cout << "\nLogin Successful!\n";
        return true;
    }

    return false;
}

// Display menu
int displayMenu()
{
    int choice;

    cout << "\n========== MAIN MENU ==========\n";
    cout << "1. Create New Diary Entry\n";
    cout << "2. View All Entries\n";
    cout << "3. Read Full Entry\n";
    cout << "4. Edit An Entry\n";
    cout << "5. Delete One Entry\n";
    cout << "6. Delete All Entries\n";
    cout << "7. Exit\n";
    cout << "Enter Choice: ";

    cin >> choice;

    cin.ignore();

    return choice;
}

// Create entry
void createEntry()
{
    if (totalEntries >= 20)
    {
        cout << "\nDiary is full. Maximum 20 entries allowed.\n";
        return;
    }

    string title;
    string content;

    cout << "\nEnter Title: ";
    getline(cin, title);

    while (title == "")
    {
        cout << "Title cannot be empty. Enter again: ";
        getline(cin, title);
    }

    cout << "Enter Content: ";
    getline(cin, content);

    diaryTitles[totalEntries] = title;
    diaryContents[totalEntries] = content;

    totalEntries++;

    cout << "\nEntry Added Successfully!\n";
}

// View all entries
void viewAllEntries()
{
    if (totalEntries == 0)
    {
        cout << "\nNo Entries Found.\n";
        return;
    }

    cout << "\n========== ALL ENTRIES ==========\n";

    for (int i = 0; i < totalEntries; i++)
    {
        cout << i + 1 << ". " << diaryTitles[i] << endl;
    }
}

// Read full entry
void readFullEntry()
{
    if (totalEntries == 0)
    {
        cout << "\nNo Entries Available.\n";
        return;
    }

    int entryNo;

    viewAllEntries();

    cout << "\nEnter Entry Number: ";
    cin >> entryNo;

    cin.ignore();

    if (entryNo < 1 || entryNo > totalEntries)
    {
        cout << "Invalid Entry Number.\n";
        return;
    }

    cout << "\nTitle: " << diaryTitles[entryNo - 1] << endl;
    cout << "Content: " << diaryContents[entryNo - 1] << endl;
}

// Edit entry
void editEntry()
{
    if (totalEntries == 0)
    {
        cout << "\nNo Entries Available.\n";
        return;
    }

    int entryNo;

    viewAllEntries();

    cout << "\nEnter Entry Number To Edit: ";
    cin >> entryNo;

    cin.ignore();

    if (entryNo < 1 || entryNo > totalEntries)
    {
        cout << "Invalid Entry Number.\n";
        return;
    }

    cout << "Enter New Title: ";
    getline(cin, diaryTitles[entryNo - 1]);

    cout << "Enter New Content: ";
    getline(cin, diaryContents[entryNo - 1]);

    cout << "\nEntry Updated Successfully!\n";
}

// Delete one entry
void deleteOneEntry()
{
    if (totalEntries == 0)
    {
        cout << "\nNo Entries Available.\n";
        return;
    }

    int entryNo;

    viewAllEntries();

    cout << "\nEnter Entry Number To Delete: ";
    cin >> entryNo;

    cin.ignore();

    if (entryNo < 1 || entryNo > totalEntries)
    {
        cout << "Invalid Entry Number.\n";
        return;
    }

    for (int i = entryNo - 1; i < totalEntries - 1; i++)
    {
        diaryTitles[i] = diaryTitles[i + 1];
        diaryContents[i] = diaryContents[i + 1];
    }

    totalEntries--;

    cout << "\nEntry Deleted Successfully!\n";
}

// Delete all entries
void deleteAllEntries()
{
    if (totalEntries == 0)
    {
        cout << "\nNo Entries Available.\n";
        return;
    }

    totalEntries = 0;

    cout << "\nAll Entries Deleted Successfully!\n";
}
