#include "headerFiles/bill.h"


Bill::Bill()
{
}

Bill::~Bill()
{
}

void Bill::createBill(const int& id) {

	data = file.selectObjectById(file.orderJsonFile, id, "orderID");

	int customerID;
	vector<menuItem> items;
	bool isPaid;
	int price;
	int currentOrderID = data.at("orderID");

	for (const auto& orderJson : data.at("orderID"))
	{

		if (currentOrderID == id)
		{

			customerID = data.at("customerID");

			for (auto& menuItemJson : data.at("items")) {

				menuItem item;
				item.id = menuItemJson.at("id");
				item.name = menuItemJson.at("name");
				item.price = menuItemJson.at("price");

				items.push_back(item);
			}

			isPaid = data.at("isPaid");
			price = data.at("price");

		}
	}

	std::cout << "Customer: " << customerID << "\n Items: \n";

	for (const auto& item : items) {
		std::cout << "\n- " << item.name << ", Price: $" << item.price << std::endl;
	}

	std::cout << " has Paid: " << isPaid << "\n Total Cost: $" << price << endl;
}
