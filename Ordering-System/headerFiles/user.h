//
//  CS103-2 :: Users Header File
//

/*
Contents:
    - createUser()
    for creating a new user

    - getUser()
    for getting a user from the users.json file

    - getUsers()
    for getting all users from the users.json file

    - userExists()
    for checking if a user exists

    - passwordCorrect()
    for checking if a user's password is correct

    - isManager()
    for checking if a user is a manager

    - logoutAllUsers()
    for logging out all users

    - login()
    for starting a login process
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

    //starts a login prosess
    void login();

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