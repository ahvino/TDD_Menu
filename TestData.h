#pragma once
#include "MergeSort.h"
#include <chrono>
#include "SelectionSort.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>


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
    //PrintArray(arrayToSort, arraySz);
    auto start = std::chrono::system_clock::now();

    MergeSort(arrayToSort, 0, arraySz - 1);
    auto end = std::chrono::system_clock::now();

    std::string duration = std::to_string(std::chrono::duration<double>(end - start).count());

    std::cout << "Duration of mergesort of size " << arraySz << " ";
    std::cout << "is " << duration << "'s seconds." << std::endl;
    //PrintArray(arrayToSort, arraySz);

}


void populateSelectionSortArrays(int arraySz)
{
    int* arrayToSort = new int[arraySz];

    srand(time(NULL));


    for (int i = 0; i < arraySz; i++)
    {
        arrayToSort[i] = rand() % arraySz;
    }
    //PrintArray(arrayToSort, arraySz);

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


