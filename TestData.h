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


void RunBST()
{
    BST bst;

    bst.Add(3);
    bst.Add(5);
    bst.Add(9);
    bst.Add(9);
    bst.Add(1);
    bst.Add(4);
    //bst.Find(7);
    //bst.Find(5);
    //bst.Maximum();

    bst.Delete(bst.GetRoot(),7);
    bst.Delete(bst.GetRoot(),9);
    bst.Delete(bst.GetRoot(),3);

    bst.InOrderTraverse(bst.GetRoot());

}

