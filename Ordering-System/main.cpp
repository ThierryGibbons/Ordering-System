//
//  CS103-2 :: Main C++ File
//
//  Created by Thierry Gibbons.
//

/*
Contents:
    e
*/

#include "headerFiles/orders.h"
#include "headerFiles/menu.h"
#include "headerFiles/fileMangment.h"
#include "headerFiles/user.h"

#include <iostream>
#include <vector>

using namespace std;

int main() {
    Menu menu;
    Orders orders;
    FileMangment file;
    Users users;

    users.createUser();

    //menu.addMenuItem();

    system("pause>0");//system will be removed just here for testing
    //return 0;
}