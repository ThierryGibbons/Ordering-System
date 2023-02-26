#include "headerFiles/bill.h"


Bill::Bill()
{
}

Bill::~Bill()
{
}

void Bill::createBill( const int orderID)
{

	orderStrut = orders.getOrder(orderID);



    std::cout << "customer: " << orderStrut.customerID << " items: \n";
    for (const auto& item : orderStrut.items) {
        std::cout  << "\n-Name: " << item.name << ", Price: $" << item.price << std::endl;
    }
    std::cout << " has paid: " << orderStrut.isPaid << "\n total cost: $" << orderStrut.price << endl;

}

void Bill::emailBill(const int orderID)
{
}
