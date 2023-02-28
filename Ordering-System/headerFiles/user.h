//
//  CS103-2 :: Users Header File
//
//  Created by Thierry Gibbons.
//

/*
Contents:
    - createUser()
    for creating a new user with a username, password and name.
*/

#ifndef USERS_H
#define USERS_H

#include <iostream>
#include <vector>
#include <string>

#include "fileMangment.h"

using namespace std;

// Define the user structure
typedef struct {
    int username;
    string password;
    string name;
    bool isManager;
} User;

class Users
{
public:
    Users();
    ~Users();

    // Create a new user
    void createUser(int username, string password, string name, bool isManager);

    // Get a user from the users.json file
    User getUser(int username);

    // Get all users from the users.json file
    vector<User> getUsers();

    // Check if a user exists
    bool userExists(int username);

    // Check if a user's password is correct
    bool passwordCorrect(int username, string password);

    // Check if a user is a manager
    bool isManager(int username);

private:
    // FileMangment object
    FileMangment file;
};

#endif