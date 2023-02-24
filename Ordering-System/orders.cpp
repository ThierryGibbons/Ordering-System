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

void Orders::getOrder()
{
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
