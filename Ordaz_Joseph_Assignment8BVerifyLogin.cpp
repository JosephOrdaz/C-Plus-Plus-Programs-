// Ordaz, Joseph
// CIS-5 132
// 07/15/25
// This program verifies the username and password from a file
// is correct

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
bool checkCredentials(string username, string password);

int main() 
{
    login();
    system("pause");
    return 0;
}

void login() // Checks login is correct or not
{
    string user, pass;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;

    while (attempts < MAX_ATTEMPTS)
    {
        cout << "Login\n\n";
        cout << "Username: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (checkCredentials(user, pass))
        {
            cout << "Login successful!\n";
            return;
        }
        else
        {
            attempts++;
            int remaining = MAX_ATTEMPTS - attempts;

            if (remaining > 0)
            {
                cout << "Invalid username or password. You have " << remaining << " remaining.\n\n";
            }
            else
            {
                cout << "Attempts exceeded.\n";
            }
        }
    }
}

// Function to get login and password from thfile
bool checkCredentials(string username, string password)

{
    ifstream file("CorrectData.txt"); 
    string fileUsername, filePassword;

    if (file)
    {
        getline(file, fileUsername);
        getline(file, filePassword);
        file.close();

        return (username == fileUsername && password == filePassword);
    }
    else  // if the password does not work or an error in the file 
    {
        cout << "Error: Could not open file.\n";
        return false;
    }
}
