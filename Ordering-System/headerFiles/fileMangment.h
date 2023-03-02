//
//  CS103-2 :: File Management Header File
//

/*
Contents:
	- writeToFile()
	to write a json object to a file

	- readFromFile()
	to read a json file and return it as a json object

	- selectObjectById()
	to select a json object from a file using an id

	- checkFileExists()
	to check if a file exists

	- checkFileID()
	to check the id of the last object in a file
*/

#pragma once
#include <fstream>
#include <iostream>
//just including the json api needed to use json files
#include "json.h"
using json = nlohmann::json;




class FileMangment
{
public:
	FileMangment();

	~FileMangment();

	// writes a json object to a file
	void writeToFile(const json& j, const std::string& filePath);

	//reads and retuns a whole json file (in a form of an array)
	json readFromFile(const std::string& fileParth);

	//reads and retuns a json object using an "id" code to pick the object you want
	json selectObjectById(const std::string& filePath, int id, const std::string& key);

	//retuns a true or false if a file exists or not
	bool checkFileExists(const std::string& filePath);

	////to check id in json file, retuns the id with 1 added to it
	int checkFileID(const std::string& filePath, const std::string& key);

private:

	json jsonObject;

public:
	//can be used anywhere in the code instead of tring to write the file text each time:)
	std::string menuJsonFile = "jsonFiles/menu.json";
	std::string userJsonFile = "jsonFiles/user.json";
	std::string orderJsonFile = "jsonFiles/order.json";

};

