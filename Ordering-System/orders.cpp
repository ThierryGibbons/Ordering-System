#include "headerFiles/orders.h"

Orders::Orders()
{
}

Orders::~Orders()
{
}
//function to create a new order with a unique order ID
void Orders::createOrder(int customerID, vector<menuItem> items)
{
    //read json order file, store info into json data object
    data = file.readFromFile(file.orderJsonFile);


    Order newOrder;
    newOrder.customerID = customerID;
    newOrder.items = items;
    newOrder.orderID = nextOrderID;
    newOrder.isPaid = false;
    newOrder.price = 0;
    //loop though all items to get prices, add them togeter 
    for (int i = 0; i < items.size(); i++) {
        newOrder.price += items[i].price;
    }
    //will need to get to json file find last id and add one to that (this will be fixed later)
    nextOrderID++;

    //create a json array for items
    json itemsArray = json::array();
    //loop though all items in vector and push them into json array
    for (int i = 0; i < items.size(); i++) {
        itemsArray.push_back({
            {"id", items[i].id},
            {"name", items[i].name},
            {"price", items[i].price}
            });
    }

    //push order into a json file 
    data.push_back({
        {"customerID",newOrder.customerID},
        {"items", itemsArray},
        {"isPaid", newOrder.isPaid},
        {"orderID",newOrder.orderID},
        {"price", newOrder.price}
    });

    //writes to json file order.json
    file.writeToFile(data, file.orderJsonFile);

    
	
}


void Orders::getOrder(const std::string& orderID)
{

    Order oldOrder;
    //read order.json file to get order using the order id 
    data = file.selectObjectById(file.orderJsonFile, to_string(oldOrder.orderID), "orderID");

    //creating a vector of menu items to store the json array of menu items already saved
    vector<menuItem> items;

    //loop over each item in the json file and push them onto the menu item vector 
    for (auto& item : data) {
        menuItem getMenuItem;
        getMenuItem.id = item["id"];
        getMenuItem.name = item["name"];
        getMenuItem.price = item["price"];

        items.push_back(getMenuItem);
    }


    //find data at pos and store it into oldOrder strut 
    oldOrder.customerID = data.at("customerID");
    oldOrder.isPaid = data.at("isPaid");
    oldOrder.items = items;
    oldOrder.price = data.at("price");

}

void Orders::getAllOrders()
{
}

void Orders::confirmOrder()
{
}

void Orders::cancelOrder()
{
}
