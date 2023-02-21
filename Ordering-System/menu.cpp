#include "headerFiles/menu.h"



Menu::Menu()
{
    //i think a part of this causes an error if the file dosent exists the error will only apper for the first item added so its fine
    // check if the JSON file already exists
    if (!file.checkFileExists(file.menuJsonFile)) {
        // if not, create an empty array and write it to the file 
        json emptyArray = json::array();
        file.writeToFile(emptyArray, file.menuJsonFile);
    }
}

Menu::~Menu()
{
}


// get console input of new menu item and put into menu.json file
void Menu::addMenuItem() {  
        
    //promping user for adding menu items
    cout << "Enter the name of the menu item: ";
    cin >> name;
    cout << "Enter the price of the menu item: ";
    cin >> price;
    cout << "Enter Uneck id code of the menu item: ";
    cin >> id;
    menuItem newItem = { id, name, price };

    //reading every thing currently on the json file and storing it inside of the data veraible
    data = file.readFromFile(file.menuJsonFile);

    // add new menu item to json file 
        
    data.push_back({
        {"id",newItem.id},
        {"name", newItem.name},
        {"price", newItem.price}
        });

    //writes to json file menu.json
    file.writeToFile(data, file.menuJsonFile);
    //out puts info to user;
    cout << "New menu item added: " << newItem.name << " $" << newItem.price << endl;
}

void Menu::getMenuItem()
{

}

void Menu::getMenu()
{
}
