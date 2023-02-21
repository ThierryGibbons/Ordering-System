//
//  CS103-2 :: File Management Header File
//
//  Created by Thierry Gibbons & Jared Evans.
//

/*
Contents:
*/

#pragma once
#include <fstream>
#include <iostream>
#include "json.h"
using json = nlohmann::json;




class FileMangment
{
public:
	FileMangment();

	~FileMangment();

	void writeToFile(const json& j, const std::string& filePath);

	json readFromFile(const std::string& fileParth, const std::string& id);

private:

	json jsonObject;
	
public:
	
	std::string menuJsonFile = "jsonFiles/menu.json";
	std::string userJsonFile = "jsonFiles/user.json";
	std::string orderJsonFile = "jsonFiles/order.json";

};

