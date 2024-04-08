/*
* Author:  Selik Samai
* Date:  03/10/2024
* MS 549 Data Structures and Testing
* Program:  TDD_Menu.cpp
*   Overview
*       Write a program that has a menu with 3 items, the 3rd is exit.  Have items 1 and 2 do something constructive and utilize contitionals (if/else statements)   utilizing the Test Driven Development process.
*       Course objectives in this assignment:
*
*   Guidelines:
*       A Versioning Control system such as git must be used.
*
*   Example of Test Driven Development
*      1. Commit the current state of your code to your Versioning Control system.  If using github,use a new repository.
*      2. Complete at least 2 kinds of testing and a short paragraph on what you have chosen to use on this assignment along with all results.
*   Expectations:
*       The program should execute 2 related tasks that do something worthwhile.  There should be a loop around the menu to have it execute until the exit condition is reached.  The method of testing is your choice.
*
*   Deliverables:
*       Submit your github URL that contains all the files for your project.  Submit a video of all functionality.  Submit your analysis of the performance.
*/

#include "MenuFunctions.h"
#include <memory>
#include "MyLinkedList.h"
#include "Stack.h"

void StartMenu()
{
    std::string studentID = "";
    std::string student = "";

    bool recursiveMenu = true;
    std::unique_ptr<bool> rerun(&recursiveMenu);


    MainMenu(studentID, student, *rerun);

    if (recursiveMenu == false)
    {
        std::cout << "Successfully updated our pointer" << std::endl;

        std::cout << "Exiting program..." << std::endl;
        exit(EXIT_SUCCESS);
    }
}

void CheckLists()
{
    std::cout << "Starting stack..." << std::endl;
    Stack stack;
    stack.Push(5);
    stack.Push(7);
    stack.Push(9);
    stack.Push(3);
    stack.Pop();
    
    std::cout << "Ending linked list..." << std::endl;

}

int main()
{
    //StartMenu();

    CheckLists();

    return 0;
}

