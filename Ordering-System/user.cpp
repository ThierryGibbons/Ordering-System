//
//  CS103-2 :: Users cpp File
//
//  Created by Thierry Gibbons.
//

#include "headerFiles/user.h"

Users::Users()
{
    std::cout << "enter userID: ";
    std::cin >> newUserID;
    std::cout << "enter your password: ";
    std::cin >> newUserPassword;

    while (!passwordCorrect(newUserID, newUserPassword))
    {
        loggedin = false;
        std::cout << "enter userID: ";
        std::cin >> newUserID;
        std::cout << "enter your password: ";
        std::cin >> newUserPassword;
    }
    loggedin = true;
    loggedinUserID = newUserID;
}

Users::~Users()
{

}

// Create a new user
void Users::createUser()
{
    

   
    // Prompt user for username, password and name
    cout << "Enter a userID: ";
    cin >> user.username;
    cout << "Enter a password: ";
    cin >> user.password;
    cout << "Enter a name: ";
    cin >> user.name;
    cout << "Is this user a manager? (y/n): ";
    char isManager;
    cin >> isManager;
    if (isManager == 'y') {
        user.isManager = true;
    } else {
        user.isManager = false;
    }
    user.isLogin = false;

    // Read json user file, store info into json data object
    data = file.readFromFile(file.userJsonFile);

    // Add the new user to the users vector
    data.push_back({
        {"username", user.username},
        {"password", user.password},
        {"name", user.name},
        {"isManager", user.isManager},
        {"isLogin", user.isLogin}
    });

    // Write the users vector to the users.json file
    file.writeToFile(data, file.userJsonFile);

    // Display new user created in console
    cout << "New user created: " << user.name << endl;
}



User Users::getUser(int userName)
{   

    
    //reads users file and gets json object by "username" and returns a json object
    try
    {
        data = file.selectObjectById(file.userJsonFile, userName, "username");
    }
    catch (const std::exception& e)
    {
        std::cout << "userName ID dosent exsit or cant load json users file: " << e.what() << endl;
    }
    

    //finds the value at a key and stores it into the verabils

    user.isManager = data.at("isManager");
    user.name = data.at("name");
    user.password = data.at("password");
    user.username = data.at("username");

    

    return user;
}

void Users::getUsers()
{

    data = file.readFromFile(file.userJsonFile);

    //loops though each json object
    for (const auto& obj : data) {

        //checks if theres another object or the end of json file
        if (obj.find("name") != obj.end() 
            && obj.find("isManager") != obj.end() 
            && obj.find("password") != obj.end()
            && obj.find("username") != obj.end())
        {

            //displays user id name and if they are a manager of each user 
            cout << "user id is: " << obj["username"] <<" users name is : " << obj.at("name") << " are they a manager :" << obj["isManager"] << endl;
        }
    }
}

bool Users::userExists(int username)
{

    try
    {
        data = file.selectObjectById(file.userJsonFile, username, "username");
    }
    catch (const std::exception& e)
    {  
        std::cout << "this is an empty userID\n";
        return false;
    }

    user.username = data.at("username");

    if (user.username == username) {
        //user exists
        std::cout << "this user ID already Exists: \n";
        return true;
    }
   
        
}

bool Users::passwordCorrect(int username, string password)
{
    //reads users file and gets json object by "username" and returns a json object
    data = file.readFromFile(file.userJsonFile);    

    for (auto& userData : data) {

        user.username = userData["username"];
        user.password = userData["password"];
        user.isLogin = userData["isLogin"];

        //checks if theres another object or the end of json file
        if (userData["username"] == username)
        {
            if (userData["password"] == password) {

                std::cout << "\npassword accepted welcome user: " << user.username << std::endl;

                userData["isLogin"] = true;                

                file.writeToFile(data, file.userJsonFile);
                return true;
            }
        }
    }
    std::cout << "\npassword wrong please check your userID and password are correct.\n";
    return false;
}

bool Users::isManager(int username)
{
    //reads users file and gets json object by "username" and returns a json object
    try
    {
        data = file.selectObjectById(file.userJsonFile, username, "username");
    }
    catch (const std::exception& e)
    {
        std::cout << "userName ID dosent exsit or cant load json users file: " << e.what() << endl;
    }

    user.isManager = data.at("isManager");

    if (user.isManager == true)
    {
        std::cout << "is Manager\n";
        return true;
    }

    return false;
}

void Users::logoutAllUsers()
{
    data = file.readFromFile(file.userJsonFile);


    for (auto& userData : data) {
        if (userData["isLogin"] == true) {

            userData["isLogin"] = false;
        }

    }

    file.writeToFile(data, file.userJsonFile);

}
