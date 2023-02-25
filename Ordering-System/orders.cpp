#include "headerFiles/orders.h"

Orders::Orders()
{
}

Orders::~Orders()
{
}
//function to create a new order with a unique order ID
Order Orders::createOrder(int customerID, vector<menuItem> items)
{
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
    return newOrder;
	
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
