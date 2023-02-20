//
//  CS103-2 :: Orders Header File
//
//  Created by Thierry Gibbons.
//

/*
Contents:
    - createOrder()
    for creating a new order with a unique order ID

    - Order struct
    for storing order data

    - createOrder()
    for creating a new order with a unique order ID, adding and adjusting items, and paying for the order

    - getOrder()
    for getting an order from the orders.json file to be displayed to the user and for potential editing

    - getOrders()
    for getting all orders from the orders.json file to be displayed to the user and for potential editing

    - confirmOrder()
    for confirming an order and adding it to the orders.json file

    - cancelOrder()
    for cancelling an order and removing it from the orders.json file
*/

#ifndef ORDERS_H
#define ORDERS_H

#include <iostream>
#include <vector>
#include <string>

#include "menu.h"

using namespace std;


// Define the order structure
typedef struct {
    int customerID;
    vector<menuItem> items;
    int orderID;
    bool isPaid;
    float price;
} Order;

int nextOrderID = 1; // variable to keep track of the next order ID

//function to create a new order with a unique order ID
Order createOrder(int customerID, vector<menuItem> items) {
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



#endif
