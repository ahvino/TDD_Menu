#define NDEBUG
#pragma once

#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>
#include <regex>
#include <ctype.h>
#include <cassert>
#include <time.h>


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


bool ValidName(std::string name)
{
    bool isValid = false;

    if (name.size() > 0 && name != "0") { isValid = true; }

    return isValid;
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

    if (ValidName(name))
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


void TestValidId()
{
    std::cout << "Running Test 'TestValidId'..." << std::endl;

    assert(ValidStudentID("123456") == true);
    std::cout << " Test 'TestValidID' with '123456' passed!" << std::endl;
}

void TestInvalidId()
{
    std::cout << "Running Test 'TestInvalidId'..." << std::endl;

    assert(ValidStudentID("123") == true);
    std::cout << "Test 'TestInvalidId' with '123' failed!" << std::endl;

}


void TestValidName()
{
    std::cout << "Running Test 'TestValidName'..." << std::endl;

    assert(ValidName("tester") == true);
    std::cout << "Test 'TestValidName' with 'tester' passed!" << std::endl;

}


void TestInvalidName()
{
    std::cout << "Running Test 'TestInvalidName'..." << std::endl;

    assert(ValidName("") == true);
    std::cout << "Test 'TestInvalidName' with '' failed!" << std::endl;

}

void RunRandomUnitTest()
{
    srand(time(NULL));

    int randomNum;
    randomNum = rand() % 4 + 1;


    switch (randomNum)
    {
    case 1:
        TestValidId();

        break;
    case 2:
        TestInvalidId();

        break;
    case 3:
        TestValidName();

        break;
    case 4: 
        TestInvalidName();

        break;
    default: 
        TestInvalidName();

        break;
    }

}

void MenuPrompt()
{
    std::string studentID = "";
    std::string student = "";

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
    std::cout << "1. Enter Name \n2. Student ID# \n3. Run Unit Tests\n4. Exit \n" << std::endl;

    std::string menuVal;
    std::cout << "Option: ";
    std::getline(std::cin, menuVal);
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
    std::cout << "1. Enter Name \n2. Student ID# \n3. Run Unit Tests\n4. Exit \n" << std::endl;

    std::string menuVal;
    std::cout << "Option: ";
    std::getline(std::cin, menuVal);
    
    int val;
    if (menuVal.size() > 0)
    {
        val = std::stoi(menuVal);

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
            std::cout << "Running Unit Tests..." << std::endl;

            RunRandomUnitTest();

            std::cout << "\n\n";
            break;
        case 4:
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
}


void MainMenu(std::string& studentID, std::string& student, bool & rerun)
{
    std::string studentInfo;
    std::string menu;

    //acts as base case to determine if we should stop executing
    if (rerun == false)
    {
        return;
    }

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
    std::cout << "1. Enter Name \n2. Student ID# \n3. Run Unit Tests\n4. Exit \n" << std::endl;

    std::string menuVal;
    std::cout << "Option: ";
    std::getline(std::cin, menuVal);

    int val;
    if (menuVal.size() > 0)
    {
        val = std::stoi(menuVal);

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
            std::cout << "Running Unit Tests..." << std::endl;

            RunRandomUnitTest();

            std::cout << "\n\n";

            break;
        case 4:
            rerun = false;
            break;

        default:
            std::cout << "The menu option you entered was invalid, please try again with an appropriate menu option. " << std::endl;
            std::cout << "\n\n...THIS SCREEN WILL CLEAR IN 5 SECONDS...";
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));

            system("CLS");
            break;
        }
    }

    //recursive function calls itself 
    MainMenu(studentID, student, rerun);

}

