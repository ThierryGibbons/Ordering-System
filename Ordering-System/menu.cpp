#include "headerFiles/menu.h"



Menu::Menu()
{

}

Menu::~Menu()
{
}


// get console input of new menu item and put into menu.json file
void Menu::addMenuItem() {
    
    id++;

    cout << "Enter the name of the menu item: ";
    cin >> name;
    cout << "Enter the price of the menu item: ";
    cin >> price;
    menuItem newItem = { id, name, price };
    // add new menu item to menu.json file

    data = json::array();
    data.push_back({
        {"id",newItem.id},
        {"name", newItem.name},
        {"price", newItem.price}
        });

    //writes to json file menu.json
    file.writeToFile(data, file.menuJsonFile);

    cout << "New menu item added: " << newItem.name << " $" << newItem.price << endl;
}

void Menu::getMenuItem()
{
}

void Menu::getMenu()
{
}
