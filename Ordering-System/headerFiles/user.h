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

#include "fileMangment.h"

using namespace std;

// Define the user structure
typedef struct {
    int username;
    string password;
    string name;
    bool isManager;
    bool isLogin;
} User;

class Users
{
public:
    Users();
    ~Users();

    // Create a new user
    void createUser();

    // Get a user from the users.json file
    User getUser(int userName);

    // Get all users from the users.json file
    void getUsers();

    // Check if a user exists
    bool userExists(int userName);

    // Check if a user's password is correct
    bool passwordCorrect(int userName, string password);

    // Check if a user is a manager
    bool isManager(int userName);

    //logout all users
    void logoutAllUsers();

private:
    // FileMangment object
    FileMangment file;

    json data;

    User user;

    int newUserID;
    std::string newUserPassword;

public:

    bool loggedin = false;
    int loggedinUserID;
};

#endif