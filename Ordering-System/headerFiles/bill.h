//
//  CS103-2 :: Bills Header File
//

/*
Contents:
    - createBill()
    for creating a new bill
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