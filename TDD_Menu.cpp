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
#include <stdlib.h>
#include "MyLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "TestData.h"
#include "HashTable.h"
#include <vector>
#include <unordered_set>
#include <functional>

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
    printf("===========================================================================.\n");
    printf("Print stack of size 100.\n");
    PrintStack(100);

    printf("===========================================================================.\n");
    printf("Print queue of size 100.\n");
    PrintQueue(100);


    printf("===========================================================================.\n");
    printf("Running stack unit tests with sizes '%d', '%d', '%d'.\n",100, 1000, 10000 );

    StackUnitTests(100);

    StackUnitTests(1000);

    StackUnitTests(10000);
    printf("===========================================================================.\n");

    printf("===========================================================================.\n");
    printf("Running queue unit tests with sizes '%d', '%d', '%d'.\n", 100, 1000, 10000);

    QueueUnitTests(100);

    QueueUnitTests(1000);

    QueueUnitTests(10000);
    printf("===========================================================================.\n");

    
}


void HashCompare()
{
    std::vector<std::string> names = GenerateRandomString(100);

    HashTable ht1(names.size() * 10);
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < names.size(); i++)
    {
        ht1.Insert(names[i]);
    }
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert of size " << 100 << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


    std::unordered_set<std::string> ht2;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.insert(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert of size using built in hash" << 100 << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
}

void DisplayAndFind100()
{
    std::vector<std::string> names = GenerateRandomString(100);

    HashTable ht1(names.size() * 10);

    for (int i = 0; i < names.size(); i++)
    {
        ht1.Insert(names[i]);
    }

    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < names.size(); i++)
    {
        ht1.FindValue(names[i]);
    }

    auto end = std::chrono::system_clock::now();

    auto duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Find of size " << 100 << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
}


void HashTests(int dataSize)
{
    std::vector<std::string> names = GenerateRandomString(dataSize);


    // INSERTS================================================================
    HashTable ht(names.size() * 10);
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


    std::unordered_set<std::string> ht2;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.insert(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert using built hash of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    // FIND================================================================
    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.FindValue(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Find of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.find(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Find using built in hash function of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    // DELETE================================================================
    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.Delete(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Delete of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.erase(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Erase using built in hash function of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

}


void Hash100()
{

    std::vector<std::string> names = GenerateRandomString(100);


    // INSERTS================================================================
    HashTable ht(names.size() * 10);
    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


    std::unordered_set<std::string> ht2;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.insert(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert using built hash of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    // FIND================================================================
    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.FindValue(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Find of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.find(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Find using built in hash function of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    // DELETE================================================================
    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.Delete(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Delete of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.erase(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Erase using built in hash function of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


}

void Hash1000()
{
    std::vector<std::string> names = GenerateRandomString(1000);

    HashTable ht(names.size() * 10);

    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


    std::unordered_set<std::string> ht2;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.insert(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert using built hash of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
    //ht.Display();
}



void Hash10000()
{
    std::vector<std::string> names = GenerateRandomString(10000);

    HashTable ht(names.size() * 10);

    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


    std::unordered_set<std::string> ht2;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht2.insert(names[i]);
    }
    end = std::chrono::system_clock::now();

    duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Insert using built hash of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
    //ht.Display();
}

void RunHashSetup()
{
    std::vector<std::string> names = GenerateRandomString(5);

    HashTable ht(names.size() * 10);

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    //ht.Display();
}

void BasicInsertRuns()
{
    Hash100();
    Hash1000();
    Hash10000();
}

void BasicDeleteRuns()
{
    Hash100();
    Hash1000();
    Hash10000();
}


void Delete100()
{
    std::vector<std::string> names = GenerateRandomString(100);

    HashTable ht(names.size() * 10);

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    ht.Display();
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.Delete(names[i]);
    }
    auto end = std::chrono::system_clock::now();

    auto duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Delete of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
    ht.Display();
}


void Delete1000()
{
    std::vector<std::string> names = GenerateRandomString(1000);

    HashTable ht(names.size() * 10);

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    ht.Display();
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.Delete(names[i]);
    }
    auto end = std::chrono::system_clock::now();

    auto duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Delete of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
    ht.Display();
}


void Delete10000()
{
    std::vector<std::string> names = GenerateRandomString(10000);

    HashTable ht(names.size() * 10);

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    ht.Display();
    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < names.size(); i++)
    {
        ht.Delete(names[i]);
    }
    auto end = std::chrono::system_clock::now();

    auto duration = std::to_string(std::chrono::duration<double>(end - start).count());
    std::cout << "Duration of Delete of size " << names.size() << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
    ht.Display();
}

void BasicFindRuns()
{
    Hash100();
    Hash1000();
    Hash10000();
}


void ShowcaseCollisions()
{
    std::vector<std::string> names = GenerateRandomString(1000);

    HashTable ht(names.size() * 3);

    for (int i = 0; i < names.size(); i++)
    {
        ht.Insert(names[i]);
    }

    ht.Display();

}


int main()
{
    //StartMenu();
    //HashCompare();
    //DisplayAndFind100();
    //BasicInsertRuns();
    printf("====================================\n");
    HashTests(100);
    printf("====================================\n");
    HashTests(1000);
    printf("====================================\n");
    HashTests(10000);
    printf("====================================\n");

    ShowcaseCollisions();
    //RunHashSetup();
    //CheckLists();


    return 0;
}

