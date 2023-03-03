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


    OrderData newOrder;

    newOrder.isPaid = false;
    newOrder.price = 0;
    newOrder.customerID = customerID;

    //loop though all items to get prices, add them togeter
    for (int i = 0; i < items.size(); i++) {
        newOrder.price += items[i].price;
    }

    //retuns a int for updating id
    newOrder.orderID = file.checkFileID(file.orderJsonFile, "orderID");


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


OrderData Orders::getOrder(const int& orderID)
{

    OrderData oldOrder;
    oldOrder.customerID = 0;
    oldOrder.price = 0;
    oldOrder.orderID = 0;
    //read order.json file to get order using the order id
    data = file.selectObjectById(file.orderJsonFile, orderID, "orderID");
    //find items key and move into items key
    json items = data.at("items");

    

    //loop over each item in the json file and push them onto the menu item vector
    for (const auto& menuItemJson : items) {
        menuItem getMenuItem;
        getMenuItem.id = menuItemJson["id"];
        getMenuItem.name = menuItemJson["name"];
        getMenuItem.price = menuItemJson["price"];

        oldOrder.items.push_back(getMenuItem);

    }


    //find data at pos and store it into oldOrder strut
    if (!data.empty()) {
        oldOrder.customerID = data.at("customerID");
        oldOrder.isPaid = data.at("isPaid");         
        oldOrder.price = data.at("price");


        return oldOrder;
    }
    else
    {
        std::cout << "error json object is empty or missing elements" << endl;
    }
}

void Orders::getAllOrders()
{
    //read json file and store into data json object
    data = file.readFromFile(file.orderJsonFile);

    //loop over each order and display them
    for (const auto& orderJson : data)
    {
        //check if anything is missing
        if (!orderJson.contains("orderID") || !orderJson.contains("customerID")
            || !orderJson.contains("isPaid") || !orderJson.contains("price")
            || !orderJson.contains("items") || !orderJson["items"].is_array()) {
            std::cerr << "Error: One of the orders in the file is missing required fields.\n";
            continue;
        }


        OrderData order;
        //find data at pos and store it into order strut
        order.customerID = orderJson.at("customerID").get<int>();
        order.isPaid = orderJson.at("isPaid").get<bool>();
        order.price = orderJson.at("price").get<double>();
        order.orderID = orderJson.at("orderID").get<int>();

        std::vector<menuItem> menuItems;
        //loop over each menu item in order and store then i a vector
        for (const auto& menuItemJson : orderJson.at("items"))
        {
            menuItem item;
            item.id = menuItemJson.at("id");
            item.name = menuItemJson.at("name");
            item.price = menuItemJson.at("price");
            menuItems.push_back(item);
        }

       //store vector into the order
        order.items = menuItems;

        //display all info to user
        std::cout << "\n\n - order id: " << order.orderID << std::endl;
        std::cout << "customer: " << order.customerID << " items: \n";
        for (const auto& menuItem : menuItems) {
            std::cout << " - " << menuItem.name << " $" << menuItem.price << std::endl;
        }
        std::cout << " has paid: " << order.isPaid << "\n total cost: $" << order.price << std::endl;
    }
}

void Orders::confirmOrder(const int& orderID)
{
    data = file.readFromFile(file.orderJsonFile);

    //loop over each order if orderID machis change isPaid to true and break
    for (auto& orderJson : data) {
        int currentOrderID = orderJson.at("orderID");

        if (currentOrderID == orderID) {
            orderJson["isPaid"] = true;

            break;
        }
    }

    //save changes back to json file
    file.writeToFile(data, file.orderJsonFile);

    billClass.createBill(orderID);
}

void Orders::cancelOrder(const int& orderID)
{

    data = file.readFromFile(file.orderJsonFile);

    //run over the json file from beging to end to find orderID that machis our input
    auto object = std::find_if(data.begin(), data.end(), [&](const json& obj) {
        return obj["orderID"] == orderID;
    });
    //if the orderID was found the data is erased if not we display that orderID was not found
    if (object != data.end()) {
        data.erase(object);
        std::cout << "Order " << orderID << " removed successfully.\n";
    }
    else
    {
        std::cout << "Order " << orderID << " not found.\n";
    }

    //update the data in the file
    file.writeToFile(data, file.orderJsonFile);
}
