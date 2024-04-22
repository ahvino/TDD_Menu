#pragma once
#include "MergeSort.h"
#include <chrono>
#include "SelectionSort.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include "Stack.h"
#include "Queue.h"
#include "BST.h"
#include <list>
#include <vector>


void PrintArray(int array[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
}

void populateMergeSortArrays(int arraySz)
{
    int * arrayToSort = new int[arraySz];

    srand(time(NULL));


    for (int i = 0; i < arraySz; i++)
    {
        arrayToSort[i] = rand() % arraySz;
    }
    auto start = std::chrono::system_clock::now();

    MergeSort(arrayToSort, 0, arraySz - 1);
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());

    std::cout << "Duration of mergesort of size " << arraySz << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

}




std::vector<std::string> GenerateRandomString(int numOfstrs)
{
    std::vector<std::string> names;
    char characters[] = "abcdefghijklmnopqrstuvwxyz";
    
    for (int i = 0; i < numOfstrs; i++)
    {
        //random name of length 3 or more;
        int length = rand() % 15 + 3;

        std::string name = "";

        int randIndex = 0;

        for (int i = 0; i < length; i++)
        {
            randIndex = rand() % 26;
            name += characters[randIndex];
        }
        //printf("Name is '%s'\n", name.c_str());
        names.push_back(name);
    }

    return names;
}


void QueueUnitTests(int size)
{
    Queue queue;
    int* queueArr = new int[size];

    srand(time(NULL));
    int randomNum;
    for (int i = 0; i < size; i++)
    {
        queueArr[i] = rand() % 100 + 1;
    }

    //measure time for inset to complete
    std::cout << "Clocking time to insert now..." << std::endl;
    auto t1 = std::chrono::system_clock::now();
    for (int i = 0; i < size; i++)
    {
        queue.Push(queueArr[i]);
    }
    auto t2 = std::chrono::system_clock::now();
    std::string duration = std::to_string(std::chrono::duration<double>(t2 - t1).count());
    printf("Total insert time was: '%s' seconds to insert '%i' values.\n", duration.c_str(), queue.Size());

    //measure time to remove queue
    std::cout << "Clocking time to delete now..." << std::endl;
    t1 = std::chrono::system_clock::now();
    for (int i = 0; i < size; i++)
    {
        queue.Pop();
    }
    t2 = std::chrono::system_clock::now();
    duration = std::to_string(std::chrono::duration<double>(t2 - t1).count());

    printf("Total delete time was: '%s' seconds.\n", duration.c_str());

}

void PrintQueue(int size)
{
    Queue queue;
    int* queueArr = new int[size];

    srand(time(NULL));
    int randomNum;
    for (int i = 0; i < size; i++)
    {
        queueArr[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < size; i++)
    {
        queue.Push(queueArr[i]);
    }
    auto t2 = std::chrono::system_clock::now();

    //Print the Queue
    queue.Print();



}

void PrintStack(int size)
{
    Stack stack;
    int* stackArr = new int[size];

    srand(time(NULL));
    int randomNum;
    for (int i = 0; i < size; i++)
    {
        stackArr[i] = rand() % 100 + 1;
    }

    //measure time for inset to complete
    for (int i = 0; i < size; i++)
    {
        stack.Push(stackArr[i]);
    }

    //Print the Queue
    stack.Print();
}


void StackUnitTests(int size)
{
    Stack stack;
    int* stackArr = new int[size];

    srand(time(NULL));
    int randomNum;
    for (int i = 0; i < size; i++)
    {
        stackArr[i] = rand() % 100 + 1;
    }

    //measure time for inset to complete
    std::cout << "Clocking time to insert now..." << std::endl;
    auto t1 = std::chrono::system_clock::now();
    for (int i = 0; i < size; i++)
    {
        stack.Push(stackArr[i]);
    }
    auto t2 = std::chrono::system_clock::now();
    std::string duration = std::to_string(std::chrono::duration<double>(t2 - t1).count());
    printf("Total insert time was: '%s' seconds to insert '%i' values.\n", duration.c_str(), stack.Size());

    //measure time to remove queue
    std::cout << "Clocking time to delete now..." << std::endl;
    t1 = std::chrono::system_clock::now();
    for (int i = 0; i < size; i++)
    {
        stack.Pop();
    }
    t2 = std::chrono::system_clock::now();
    duration = std::to_string(std::chrono::duration<double>(t2 - t1).count());

    printf("Total delete time was: '%s' seconds.\n", duration.c_str());
}




void populateSelectionSortArrays(int arraySz)
{
    int* arrayToSort = new int[arraySz];

    srand(time(NULL));


    for (int i = 0; i < arraySz; i++)
    {
        arrayToSort[i] = rand() % arraySz;
    }

    auto start = std::chrono::system_clock::now();
    SelectionSort(arrayToSort, arraySz);
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());

    //PrintArray(arrayToSort, arraySz);
    std::cout << "Duration of selection sort of size " << arraySz << " ";
    std::cout << "is " << duration<<  "'s seconds." << std::endl;

}


void RunSelectionSortsTests()
{
    populateSelectionSortArrays(100);
    populateSelectionSortArrays(1000);
    populateSelectionSortArrays(10000);
    populateSelectionSortArrays(100000);
}

void RunMergeSortsTests()
{
    populateMergeSortArrays(100);
    populateMergeSortArrays(1000);
    populateMergeSortArrays(10000);
    populateMergeSortArrays(100000);
}


void BSTInsert10000()
{
    int* arrayToSort = new int[10000];

    srand(time(NULL));
    BST bst;

    for (int i = 0; i < 10000; i++)
    {
        arrayToSort[i] = rand() % 10000;
    }

    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < 10000; i++)
    {
        bst.Add(arrayToSort[i], true);
    }
    auto end = std::chrono::system_clock::now();

    bst.InOrderTraverse(bst.GetRoot());
    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());

    std::cout << "Duration of BST inserts of size " << 10000 << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

    bst.Maximum();
}


void BSTInsertAndDeleteTest()
{
    int* arrayToSort = new int[1000];

    srand(time(NULL));
    BST bst;

    for (int i = 0; i < 1000; i++)
    {
        arrayToSort[i] = rand() % 1000;
    }

    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < 1000; i++)
    {
        bst.Add(arrayToSort[i], true);
    }
    auto end = std::chrono::system_clock::now();

    bst.InOrderTraverse(bst.GetRoot());
    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());

    std::cout << "Duration of BST inserts of size " << 1000 << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;


    start = std::chrono::system_clock::now();

    for (int i = 0; i < 1000; i++)
    {
        bst.Delete(bst.GetRoot(), arrayToSort[i]);
    }
    end = std::chrono::system_clock::now();
    duration = std::to_string(std::chrono::duration<double>(end - start).count());


    bst.InOrderTraverse(bst.GetRoot());

    std::cout << "Duration of BST deletes of size " << 1000 << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
}

void BSTInsertsTests(int arrSz)
{
    int* arrayToSort = new int[arrSz];

    srand(time(NULL));
    BST bst;

    for (int i = 0; i < arrSz; i++)
    {
        arrayToSort[i] = rand() % arrSz;
    }

    auto start = std::chrono::system_clock::now();

    for (int i = 0; i < arrSz; i++)
    {
        bst.Add(arrayToSort[i], false);
    }
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());

    std::cout << "Duration of BST inserts of size " << arrSz << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;

}

void RunBST()
{
    //BSTInsertsTests(100);
    //BSTInsertsTests(1000);
    //BSTInsertsTests(10000);
    //BSTInsertsTests(100000);
    //
    BSTInsert10000();
    //
    BSTInsertAndDeleteTest();
}

