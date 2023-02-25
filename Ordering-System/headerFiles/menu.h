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

/*
* becuse we will be reading and writing to a json in more then just one file ill make a file manager file
* 
#include <fstream>
#include "nlohmann/json.hpp"
*/
#include "fileMangment.h"
using namespace std;
using json = nlohmann::json;



// Define the menu item structure
typedef struct {
    int id;
    string name;
    float price;
} menuItem;


class Menu
{
public:
    Menu();
    ~Menu();

    void addMenuItem();//for adding a new menu item to the menu.json file

    menuItem getMenuItem(int id);//for getting a menu item from the menu.json file

    void getMenu();//for getting the entire menu from the menu.json file

private:

    FileMangment file;
        
    json data;
    
    string name;
    float price;
    
public:

    int id;
    
};




#endif