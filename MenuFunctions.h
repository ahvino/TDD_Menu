#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <regex>
#include <ctype.h>

bool ValidStudentID(std::string stuId)
{
    bool valid = false;

    if (stuId.size() > 4)
    {
        for (int i = 0; i < stuId.size(); i++)
        {
            if (isdigit(stuId[i]))
            {
                valid = true;
            }
            else
            {
                valid = false;
            }
        }
    }

    return valid;
}


/// <summary>
/// Function for setting the students ID
/// </summary>
/// <returns>Student ID</returns>
std::string SetStudentID()
{
    bool isValidId;

    std::string ID = "";
    std::cout << "Enter your student ID: ";
    std::getline(std::cin, ID);

    isValidId = ValidStudentID(ID);
    if (!isValidId) 
    { 

        ID = ""; 
    }

    return ID;
}

/// <summary>
/// Function for setting the students name
/// </summary>
/// <returns>Students name </returns>
std::string SetStudentName(bool & isValid)
{
    std::string name = "";
    std::cout << "Enter your name or type '0' to go back to the main menu: ";
    std::getline(std::cin, name);

    if (name.size() > 0 && name != "0")
    {
        isValid = true;
        std::cout << "Thanks, " << name << "!" << std::endl;
    }
    else if (name == "0")
    {
        isValid = false;
        system("CLS");      
    }
    else
    {
        isValid = false;
    }

    return name;
}

void MainMenu(std::string & studentID, std::string & student)
{  
    std::string studentInfo;
    std::string menu;

    if (student.size() > 0 && studentID.size() > 0)
    {
        studentInfo = "\n" + student + "   " + studentID + "\n";
        menu = studentInfo + "MAIN MENU";
    }
    else
    {
        menu = "MAIN MENU";

    }
    std::cout << menu << std::endl;
    std::cout << "Enter menu option: " << std::endl;
    std::cout << "1. Enter Name \n2. Student ID# \n3. Exit \n" << std::endl;

    std::string menuVal;
    std::cout << "Option: ";
    std::getline(std::cin, menuVal);

    int val = std::stoi(menuVal);


    switch (val)
    {
        case 1:
            bool validName;
            menu = "MAIN MENU";
            student = SetStudentName(validName);


            break;
        case 2:
            studentID = SetStudentID();
            break;
        case 3:
            std::cout << "Exiting program..." << std::endl;
            exit(EXIT_SUCCESS);
            break;

        default:
            std::cout << "The menu option you entered was invalid, please try again with an appropriate menu option. " << std::endl;
            std::cout << "\n\n...THIS SCREEN WILL CLEAR IN 5 SECONDS...";
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));

            system("CLS");
            break;
    }

}