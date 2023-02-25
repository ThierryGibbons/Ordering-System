#include "headerFiles/menu.h"



Menu::Menu()
{
    //i think a part of this causes an error if the file dosent exists the error will only apper for the first item added so its fine
    /* check if the JSON file already exists
    if (!file.checkFileExists(file.menuJsonFile)) {
        // if not, create an empty array and write it to the file 
        json emptyArray = json::array();
        file.writeToFile(emptyArray, file.menuJsonFile);
    }
    */
}

Menu::~Menu()
{
}


// get console input of new menu item and put into menu.json file
void Menu::addMenuItem() { 


    menuItem newItem = { id, name, price };
    //promping user for adding menu items
    cout << "Enter the name of the menu item: ";
    cin >> newItem.name;
    cout << "Enter the price of the menu item: ";
    cin >> newItem.price;
    
    

    //reading every thing currently on the json file and storing it inside of the data veraible
    data = file.readFromFile(file.menuJsonFile);

    //retuns a int for updating id
    newItem.id = file.checkFileID(file.menuJsonFile, "id");
           

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

menuItem Menu::getMenuItem(int id)
{

    menuItem item{ id,name,price };
    //reads menu file and gets json object by "id" and returns a json object
    data = file.selectObjectById(file.menuJsonFile, item.id, "id");

    //finds the value at a key and stores it into the verabils
    
    item.name = data.at("name");
    item.price = data.at("price");

    //displays menu item
    cout << item.name << " is $" << item.price << endl;

    return item;
}


void Menu::getMenu()
{
    //reads and returns full json file
    data = file.readFromFile(file.menuJsonFile);

    //loops though each json object
    for (const auto& obj : data) {

        //checks if theres another object or the end of json file
        if (obj.find("name") != obj.end() && obj.find("price") != obj.end() && obj.find("id") != obj.end()) {

            //displays id name and price of each menu item 
            cout << "item id is: " << obj["id"] << obj["name"] << " is $" << obj["price"] << endl;
        }
    }

  
}
