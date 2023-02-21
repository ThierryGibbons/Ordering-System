#include "headerFiles/fileMangment.h"

//function to write to file in a json format
void FileMangment::writeToFile(const json& jsonObject, const std::string& filePath)
{

	if (jsonObject.empty()) {
		std::cout << "Error: jsonObject is empty" << std::endl;
		return;
	}

	std::ofstream writeF(filePath, std::ios::app);

	
	if (!writeF.is_open()) {
		std::cout << "Error: unable to open file " << filePath << " for writing" << std::endl;
		return;
	}
	
	
	
	writeF << jsonObject.dump(4) << std::endl;

	writeF.close();
}

//function to read from a file in a json format
json FileMangment::readFromFile(const std::string& filePath, const std::string& id)
{
	std::ifstream readF(filePath);
	if (!readF.is_open()) {
		std::cout << "ERROR: unable to open file " << filePath << " for reading" << std::endl;
		return json();
	}

	json jsonObject;
	try
	{
		readF >> jsonObject;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: exception thrown while parsing JSON: " << e.what() << std::endl;
		return json();
	}
	
	readF.close();

	if (!jsonObject.is_array()) {
		std::cout << "Error: JSON object is not an array" << std::endl;
		return json();
	}

	for (auto& object : jsonObject) {

		//if (object.find(id) == object.end() || !object["id"].is_string()) {
			//std::cout << "Error: JSON object does not have an 'id' field" << std::endl;
			//return json();
		//}

		if (object["id"] == id) {
			return object;
		}
	}

	std::cout << "Error: object with ID " << id << " not found in file " << filePath << std::endl;

	return json();
}

//on start checks
FileMangment::FileMangment()
{
	std::ifstream fileUser(userJsonFile);
	std::ifstream fileMenu(menuJsonFile);
	std::ifstream fileOrder(orderJsonFile);

	//preforms checks to see if you have the needed files and creats them if not
	if (!fileUser.good()) {
		std::ofstream newFile(userJsonFile);
		newFile.close();
	}
	else
	{
		fileUser.close();
	}

	if (!fileMenu.good()) {
		std::ofstream newFile(menuJsonFile);
		
		newFile.close();
	}
	else
	{
		fileUser.close();
	}

	if (!fileOrder.good()) {
		std::ofstream newFile(orderJsonFile);
		newFile.close();
	}
	else
	{
		fileUser.close();
	}

}

FileMangment::~FileMangment()
{
}