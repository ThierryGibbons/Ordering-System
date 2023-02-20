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
    //read from file returns a json object
    cout << endl << file.readFromFile("menu.json") << endl;


    system("pause>0");//system will be removed just here for testing
    //return 0;
}