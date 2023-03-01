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
    for creating a new order with a unique order ID, addingand adjusting items, and paying for the order


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

#include "fileMangment.h"
#include "menu.h"
#include "bill.h"



using namespace std;


// Define the order structure
typedef struct {
    int customerID;
    vector<menuItem> items;
    int orderID;
    bool isPaid;
    float price;
} OrderData;


class Orders
{
public:
    Orders();
    ~Orders();

    //theres no need for it to return anytime we will just add it direcly to the json file 
    void createOrder(int customerID, vector<menuItem> items);// for creating a new order with a unique order ID, addingand adjusting items, and paying for the order

    OrderData getOrder(const int& orderID); //for getting an order from the orders.json file to be displayed to the userand for potential editing

    void getAllOrders(); //for getting all orders from the orders.json file to be displayed to the user and for potential editing

    void confirmOrder(const int& orderID); //for confirming an order and adding it to the orders.json file

    void cancelOrder(const int& orderID); //for cancelling an order and removing it from the orders.json file


private:
    //please note that we will have to upate this every time the app starts or it will be set back to 1 :)
    int nextOrderID = 1; // variable to keep track of the next order ID

    FileMangment file;

    json data;

    Bill billClass;

};


#endif
