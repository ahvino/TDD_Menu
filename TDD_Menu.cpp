/*
    Overview
        Write a program that has a menu with 3 items, the 3rd is exit.  Have items 1 and 2 do something constructive and utilize contitionals (if/else statements)   utilizing the Test Driven Development process. 
        Course objectives in this assignment:    
    
    Guidelines:
        A Versioning Control system such as git must be used.
    
    Example of Test Driven Development
        1. Commit the current state of your code to your Versioning Control system.  If using github,use a new repository.
        2. Complete at least 2 kinds of testing and a short paragraph on what you have chosen to use on this assignment along with all results.
    Expectations:
        The program should execute 2 related tasks that do something worthwhile.  There should be a loop around the menu to have it execute until the exit condition is reached.  The method of testing is your choice.
    
    Deliverables:
        Submit your github URL that contains all the files for your project.  Submit a video of all functionality.  Submit your analysis of the performance.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <thread>

std::string SetStudentName()
{
    std::string name = "";
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    if (name.size() > 0)
    {
        std::cout<< ""
    }
    else
    {

    }

    return name;
}


std::string SetStudentID()
{
    std::string ID = "";
    std::cout << "Enter your student ID: ";
    std::getline(std::cin, ID);

    return ID;
}

void MainMenu()
{   
    std::cout << "MAIN MENU" << std::endl;
    std::cout << "Enter menu option: " << std::endl;
    std::cout << "1. Enter Name \n2. Student ID# \n3. Exit \n" << std::endl;

    std::string menuVal;
    std::cout << "Option: ";
    std::getline(std::cin, menuVal);

    int val = std::stoi(menuVal);
    std::string student;
    std::string studentID;

    switch (val)
    {
        case 1:
            student = SetStudentName();
            break;
        case 2:
            studentID = SetStudentID();
            break;
        case 3:
            std::cout << "Exiting program..." << std::endl;
            exit(EXIT_SUCCESS);
            break;

        default:
            std::cout << "The menu option you entered was invalid, please try again with an appropriate menu option. "<<std::endl;
            std::cout << "\n\n...THIS SCREEN WILL CLEAR IN 5 SECONDS...";
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));

            system("CLS");
            MainMenu();
            break;
    }

}
int main()
{
    MainMenu();

    return 0;
}

