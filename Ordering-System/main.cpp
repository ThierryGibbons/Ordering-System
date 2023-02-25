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
#include <vector>

using namespace std;

int main() {
    Menu menu;
    Orders orders;
    FileMangment file;

    //menu.addMenuItem();

    //most of this is only here for testing :)

    menu.getMenuItem(2);

    vector<menuItem> items;

    for (int i = 1; i < 6; i++) {
        menuItem item = menu.getMenuItem(i);
        items.push_back(item);
    }
    
    menu.getMenu();

    orders.createOrder(1,items);
    

    system("pause>0");//system will be removed just here for testing
    //return 0;
}