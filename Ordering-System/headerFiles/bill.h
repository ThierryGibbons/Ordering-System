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
#ifndef BILL_H
#define BILL_H

#include "fileMangment.h"
#include "menu.h"
#include <vector>
#include <iostream>



class Bill
{
public:
	Bill();
	~Bill();

    void createBill(const int& id);

private:

    FileMangment file;
    
    json data;
};




#endif