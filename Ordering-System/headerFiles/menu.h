//
//  CS103-2 :: Menu Header File
//

/*
Contents:
    - addMenuItem()
    for adding a new menu item to the menu.json file

    - getMenuItem()
    for getting a menu item from the menu.json file

    - getMenu()
    for getting the entire menu from the menu.json file

    - modifiyMenu()
    for modifiying a menu item in the menu.json file
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

    menuItem getMenuItem(const int& id);//for getting a menu item from the menu.json file

    void getMenu();//for getting the entire menu from the menu.json file

    void modifiyMenu(const int& id);

private:

    FileMangment file;

    json data;

    string name;
    float price;

public:

    int id;

};




#endif