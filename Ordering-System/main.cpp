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

#include <iostream>

using namespace std;

int main() {
    Menu menu;
    FileMangment file;

    menu.addMenuItem();

    //most of this is only here for testing :)

    //read from file returns a json object
    if (menu.id == "3") {
        cout << endl << file.selectObjectById(file.menuJsonFile, "2") << endl;
    }
    
    cout << endl << file.selectObjectById(file.menuJsonFile, "1") << endl;

    system("pause>0");//system will be removed just here for testing
    //return 0;
}