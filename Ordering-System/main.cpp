//
//  CS103-2 :: Main C++ File
//

#include "headerFiles/fileMangment.h"
#include "headerFiles/user.h"
#include "headerFiles/menu.h"
#include "headerFiles/orders.h"

#include <iostream>
#include <vector>

using namespace std;

//main loop functions
void addMenuItemsToOrder(Menu menu, Orders orders);

int main() {
    //call to classes
    FileMangment file;
    Users users;
    Menu menu;
    Orders orders;

    //call to struts
    User user;
    OrderData orderData;
    menuItem menuItem;

    //verabiles
    int userInput;
    std::string stringUserInput;
    bool setlogout = true;

    users.login();

    while (true)
    {
        //if the user is the manager
        if (users.isManager(users.loggedinUserID))
        {
            while (setlogout)
            {
                //main menu 

                std::cout << "\n here is your managers menu\n";

                std::cout << "\n-1:add new user\n";
                std::cout << "\n-2:add new menu item\n";
                std::cout << "\n-3:modifiy menu item\n";
                std::cout << "\n-4:open full menu\n";
                std::cout << "\n-5:add new order\n";
                std::cout << "\n-6:confirm order\n";
                std::cout << "\n-7:cancel order\n";
                std::cout << "\n-8:open order\n";
                std::cout << "\n-9:open all orders\n";
                std::cout << "\n-10:open all users\n";

                std::cout << "\n-11:log out\n";

                std::cout << "\n input a number to select sub-menu: ";
                std::cin >> userInput;

                switch (userInput)
                {
                case 1:
                    //handle new users
                    users.createUser();

                    break;
                case 2:
                    //handle new menu item
                    menu.addMenuItem();
                    break;
                case 3:
                    //handle modifiy menu item
                    std::cout << "select menu item by id: ";
                    std::cin >> userInput;

                    menu.modifiyMenu(userInput);
                    break;
                case 4:
                    //handle open full menu
                    menu.getMenu();
                    break;
                case 5:
                    addMenuItemsToOrder(menu, orders);
                    break;
                case 6:
                    //handle confirm order
                    std::cout << "input order id of the order you want to confirm: ";
                    std::cin >> userInput;

                    orders.confirmOrder(userInput);
                    break;
                case 7:
                    //handle cancel order
                    std::cout << "input order id of the order you want to cancal: ";
                    std::cin >> userInput;

                    orders.cancelOrder(userInput);
                    break;
                case 8:
                    //handle open order
                    std::cout << "input order id of the order you want to open: ";
                    std::cin >> userInput;

                    orderData = orders.getOrder(userInput);

                    std::cout << "\norder ID: " << userInput;
                    std::cout << "\ncustomer ID: " << orderData.customerID;
                    std::cout << "\nhas paid: " << orderData.isPaid;

                    for (const auto& menuItem : orderData.items) {
                        std::cout << "\n - " << menuItem.name << " $" << menuItem.price ;
                    }

                    std::cout << "\ntotal cost: $" << orderData.price;
                    break;
                case 9:
                    //handle open all orders
                    orders.getAllOrders();
                    break;
                case 10:
                    //handle open all users
                    users.getUsers();
                    break;
                case 11:
                    //handle logging out
                    users.logoutAllUsers();
                    setlogout = false;
                    break;

                default:
                    break;
                }


            }
            users.login();
            setlogout = true;
        }
        else
        {
            //for other users
            while (setlogout)
            {
                //main menu 

                std::cout << "\n here is your menu\n";

                                
                
                std::cout << "\n-1:open full menu\n";
                std::cout << "\n-2:add new order\n";
                std::cout << "\n-3:confirm order\n";
                std::cout << "\n-4:cancel order\n";
                std::cout << "\n-5:open order\n";
                std::cout << "\n-6:open all orders\n";
                std::cout << "\n-7:log out\n";

                std::cout << "\n input a number to select sub-menu: ";
                std::cin >> userInput;

                switch (userInput)
                {                
                case 1:
                    //handle open full menu
                    menu.getMenu();
                    break;
                case 2:
                    addMenuItemsToOrder(menu, orders);
                    break;
                case 3:
                    //handle confirm order
                    std::cout << "input order id of the order you want to confirm: ";
                    std::cin >> userInput;

                    orders.confirmOrder(userInput);
                    break;
                case 4:
                    //handle cancel order
                    std::cout << "input order id of the order you want to cancal: ";
                    std::cin >> userInput;

                    orders.cancelOrder(userInput);
                    break;
                case 5:
                    //handle open order
                    std::cout << "input order id of the order you want to open: ";
                    std::cin >> userInput;

                    orderData = orders.getOrder(userInput);

                    std::cout << "order ID: " << orderData.orderID;
                    std::cout << "\ncustomer ID: " << orderData.customerID;
                    std::cout << "\nhas paid: " << orderData.isPaid;

                    for (const auto& menuItem : orderData.items) {
                        std::cout << " - " << menuItem.name << " $" << menuItem.price << std::endl;
                    }

                    std::cout << "\ntotal cost: $" << orderData.price;
                    break;
                case 6:
                    //handle open all orders
                    orders.getAllOrders();
                    break;
                case 7:
                    //handle logging out
                    users.logoutAllUsers();
                    setlogout = false;
                    break;

                default:
                    break;
                }
            }
            users.login();
            setlogout = true;
        }
    }
    
        

    users.logoutAllUsers();

   
    
    return 0;
}

void addMenuItemsToOrder(Menu menu, Orders orders)
{
    int userInput;
    vector<menuItem> items;
    char isfinished;
    

    do
    {
        std::cout << "\nselect menu item by id: ";
        std::cin >> userInput;
        //handle open menu item
        menuItem menuItemVar = menu.getMenuItem(userInput);



        items.push_back(menuItemVar);

        std::cout << "\ncontinue adding items? (y/n):";

        std::cin >> isfinished;
        

    } while (isfinished == 'y');
   

    //handle add new order
    std::cout << "\nadd a number for customer ID: ";
    std::cin >> userInput;




    orders.createOrder(userInput, items);
}
