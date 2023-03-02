//
//  CS103-2 :: Main C++ File
//
//  Created by Thierry Gibbons.
//

/*
Contents:
    e
*/

#include "headerFiles/fileMangment.h"
#include "headerFiles/user.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    FileMangment file;
    Users users;
        
    User user;
    //if the user is the manager
    if (users.isManager(users.loggedinUserID))
    {
        std::cout << "im a manager";
    }
    else
    {

    }
        

    users.logoutAllUsers();

   
    
   

    system("pause>0");//system will be removed just here for testing
    //return 0;
}