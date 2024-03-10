/*
* Author:  Selik Samai
* Date:  03/10/2024
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


int main()
{
    std::string studentID = "";
    std::string student = "";

    for (;;)
    {
        MainMenu(studentID, student);
    }

    return 0;
}

