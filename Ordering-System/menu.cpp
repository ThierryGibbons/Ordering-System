#include "headerFiles/menu.h"



Menu::Menu()
{
}

Menu::~Menu()
{
}


// get console input of new menu item and put into menu.json file
void Menu::addMenuItem() {
    

    string name;
    float price;
    cout << "Enter the name of the menu item: ";
    cin >> name;
    cout << "Enter the price of the menu item: ";
    cin >> price;
    menuItem newItem = { name, price };
    // add new menu item to menu.json file


    data["name"] = newItem.name;
    data["price"] = newItem.price;

    //writes to json file menu.json
    file.writeToFile(data, "menu.json");

    cout << "New menu item added: " << newItem.name << " $" << newItem.price << endl;
}

void Menu::getMenuItem()
{
}

void Menu::getMenu()
{
}
