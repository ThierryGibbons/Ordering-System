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
#include "json.h"
using json = nlohmann::json;


class fileMangment
{
public:
	fileMangment();

	~fileMangment();

	void addToFile(const json& j, const std::string& filePath);

	json readFromFile(const std::string& fileParth);

private:

	json jsonObject;
		
};
