//
//  CS103-2 :: Bills Header File
//
//  Created by Thierry Gibbons.
//

/*
Contents:
    - createBill()
    to display bill information to the customer
    potential to be expanded to be printed onto real receipts

    - emailBill()
    to email the receipt to the customer.
*/
#include <iostream>

#include "fileMangment.h"
#include "orders.h"

class Bill
{
public:
	Bill();
	~Bill();

    void createBill( const int orderID);//to display bill information to the customer potential to be expanded to be printed onto real receipts
    

    void emailBill( const int orderID);//to email the receipt to the customer.

private:

    json data;

    FileMangment file;

    Orders orders;

    Order orderStrut;
};

