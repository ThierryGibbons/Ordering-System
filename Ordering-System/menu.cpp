#include "headerFiles/menu.h"



Menu::Menu()
{    
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

menuItem Menu::getMenuItem(const int& id)
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

void Menu::modifiyMenu(const int& id)
{
    //read json file and store it into data
    data = file.readFromFile(file.menuJsonFile);

    menuItem menu{id,name,price};
     
    //loop over each json object untill you find the one you want
    for (auto& item : data) {
        if (item["id"] == id) {
            //store item 
            menu.name = item["name"];
            menu.price = item["price"];

            //display to user and promt them to change name and price
            std::cout << "\n Change Name of: " << menu.name << " to: ";
            std::cin >> menu.name;

            std::cout << "\n Change price from: $" << menu.price << " to: $";
            std::cin >> menu.price;

            //store name and price back into json object
            item["name"] = menu.name;
            item["price"] = menu.price;

            break;
        }
    }
    
    //save changes back to json file 
    file.writeToFile(data, file.menuJsonFile);
    
}
