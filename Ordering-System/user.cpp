//
//  CS103-2 :: Users cpp File
//
//  Created by Thierry Gibbons.
//

#include "headerFiles/user.h"

Users::Users()
{
}

Users::~Users()
{
}


// Create a new user
void Users::createUser(int username, string password, string name, bool isManager)
{
    // Read json user file, store info into json data object
    json data = file.readFromFile(file.userJsonFile);

    // Create a new user
    User user;
    // Prompt user for username, password and name
    cout << "Enter a username: ";
    cin >> user.username;
    cout << "Enter a password: ";
    cin >> user.password;
    cout << "Enter a name: ";
    cin >> user.name;
    cout << "Is this user a manager? (y/n): ";
    char isManager;
    cin >> isManager;
    if (isManager == 'y') {
        user.isManager = true;
    } else {
        user.isManager = false;
    }

    // Add the new user to the users vector
    data.push_back({
        {"username", user.username},
        {"password", user.password},
        {"name", user.name},
        {"isManager", user.isManager}
    });

    // Write the users vector to the users.json file
    file.writeToFile(data, file.userJsonFile);

    // Display new user created in console
    cout << "New user created: " << user.name << endl;
}