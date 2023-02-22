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
    data = file.readFromFile(file.orderJsonFile);


    Order newOrder;
    newOrder.customerID = customerID;
    newOrder.items = items;
    newOrder.orderID = nextOrderID;
    newOrder.isPaid = false;
    newOrder.price = 0;
    for (int i = 0; i < items.size(); i++) {
        newOrder.price += items[i].price;
    }
    nextOrderID++;

    //push order into a json file 
    data.push_back({
        {"customerID",newOrder.customerID},
        {"items", newOrder.items},
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
