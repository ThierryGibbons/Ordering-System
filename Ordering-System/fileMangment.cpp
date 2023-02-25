#include "fileMangment.h"

//function to write to file in a json format
void fileMangment::addToFile(const json& jsonObject, const std::string& filePath)
{
	std::ofstream writeF(filePath);
	writeF << std::setw(4) << jsonObject << std::endl;
}

//function to read from a file in a json format
json fileMangment::readFromFile(const std::string& filePath)
{
	std::ifstream readF(filePath);
	json jsonObject;
	readF >> jsonObject;
	return jsonObject;
}

//on start checks
fileMangment::fileMangment()
{
	std::ifstream fileUser("user.json");
	std::ifstream fileMenu("menu.json");
	std::ifstream fileOrder("order.json");

	//preforms checks to see if you have the needed files and creats them if not
	if (!fileUser.good()) {
		std::ofstream newFile("user.json");
		newFile.close();
	}
	else
	{
		fileUser.close();
	}

	if (!fileMenu.good()) {
		std::ofstream newFile("menu.json");
		newFile.close();
	}
	else
	{
		fileUser.close();
	}

	if (!fileOrder.good()) {
		std::ofstream newFile("order.json");
		newFile.close();
	}
	else
	{
		fileUser.close();
	}

}

fileMangment::~fileMangment()
{
}