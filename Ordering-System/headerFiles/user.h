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
} User;

class Users
{
public:
    Users();
    ~Users();

    // Create a new user
    void createUser();

    int username;
    string password;
    string name;
    bool isManager;

private:
    // FileMangment object
    FileMangment file;

    json data;

};

#endif