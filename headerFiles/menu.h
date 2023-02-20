//
//  CS103-2 :: Menu Header File
//
//  Created by Thierry Gibbons.
//

/*
Contents:
    - addMenuItem()
    for adding a new menu item to the menu.json file

    - menuItem struct
    for storing menu item data

    - getMenuItem()
    for getting a menu item from the menu.json file

    - getMenu()
    for getting the entire menu from the menu.json file
*/

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include "nlohmann/json.hpp"

using namespace std;
using json = nlohmann::json;

json data;

// Define the menu item structure
typedef struct {
    string name;
    float price;
} menuItem;

// get console input of new menu item and put into menu.json file
void addMenuItem() {
    string name;
    float price;
    cout << "Enter the name of the menu item: ";
    cin >> name;
    cout << "Enter the price of the menu item: ";
    cin >> price;
    menuItem newItem = {name, price};
    // add new menu item to menu.json file
    data["name"] = newItem.name;
    data["price"] = newItem.price;

    ofstream file("./json/menu.json");
    file << data.dump();

    cout << "New menu item added: " << newItem.name << " $" << newItem.price << endl;
}

#endif