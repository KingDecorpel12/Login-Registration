//
// Created by Omar Hegazy on 2/13/23.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isLoggedIn()
{
    string username, password, un, pw;

    cout << "Enter username: " << endl;
    cin >> username;

    cout << "Enter password: " << endl;
    cin >> password;

    ifstream read("data\\" + username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    int choice;

    cout << "Type 1 to register. Type 2 to login." << endl;
    cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Create a username: " << endl;
        cin >> username;

        cout << "Create a password: " << endl;
        cin >> password;

        cout << "Successful registration!" << endl;

        ofstream file;
        file.open("data\\" + username + ".txt");

        file << username << endl << password << endl;

        file.close();

        main();
    }

    else if(choice == 2)
    {
        bool status = isLoggedIn();

        if (status == true)
        {
            cout << "Successfully logged in!" << endl;
            return 1;
        }

        else if (!status)
        {
            cout << "Your login info is incorrect, or does not exist. Please try again!" << endl;
            return 0;
        }
    }
}

