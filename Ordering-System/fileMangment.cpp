

#include "headerFiles/fileMangment.h"

//function to write to file in a json format
void FileMangment::writeToFile(const json& jsonObject, const std::string& filePath)
{
		
	//opens needed file
	std::ofstream writeF(filePath);

	//checks if file cant be open for what ever reason and outputs an error messege to the user
	if (!writeF.is_open()) {
		std::cout << "Error: unable to open file " << filePath << " for writing" << std::endl;
		return;
	}
	
	
	//writes json object to file
	writeF << std::setw(4) << jsonObject << std::endl;
	//closes file
	writeF.close();
}


json FileMangment::selectObjectById(const std::string& filePath, const std::string& id, const std::string& key)
{
	// read the JSON file into a JSON object
	json jsonObject = readFromFile(filePath);

	// iterate over the objects in the array
	for (const auto& obj : jsonObject) {
		// check if the object has the specified id field
		if (obj.find(key) != obj.end() && obj[key] == id) {
			// return the object if the id matches
			return obj;
		}
	}

	// throw an exception if the id was not found
	throw std::runtime_error("Error: JSON object with id '" + id + "' not found");
	
}

bool FileMangment::checkFileExists(const std::string& filePath)
{
	//opens file
	std::ifstream checkFile(filePath);
	//checks if file exists
	if (!checkFile.good()) {

		checkFile.close();
		return false;
	}
	else
	{
		checkFile.close();
		return true;
	}
	
}

//function to read from a file in a json format
json FileMangment::readFromFile(const std::string& filePath)
{
	//opens file
	std::ifstream readF(filePath);
	//checks if can open file if it cant displays error to user
	if (!readF.is_open()) {
		std::cout << "ERROR: unable to open file " << filePath << " for reading" << std::endl;
		return json();
	}

		
	try
	{
		//trys to open and read full json obeject and stores it into jsonObject
		readF >> jsonObject;
	}
	catch (const std::exception& e)
	{
		//if fails will catch and displays a exception error to user
		std::cout << "Error: exception thrown while parsing JSON: " << e.what() << std::endl;
		return json();
	}
	//closes file
	readF.close();

	// If the top-level JSON value is an array, return it directly
	if (jsonObject.is_array()) {
		return jsonObject;
	}

	// If the top-level JSON value is an object, wrap it in an array
	if (jsonObject.is_object()) {
		return json::array({ jsonObject });
	}

	// Otherwise, return an empty JSON object
	return json();
	
}

//on start checks
FileMangment::FileMangment()
{
	std::ifstream fileUser(userJsonFile);
	std::ifstream fileMenu(menuJsonFile);
	std::ifstream fileOrder(orderJsonFile);

	//preforms checks to see if you have the needed files and creates them if not
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