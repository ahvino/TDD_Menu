#pragma once
/* 
*Phase 1 - Selection Sort Algorithm
*   Use your previos data loading program and add sorting to it. 
*   Implement the Selection Sort algorithm for the array or choose any sort algorithm to implement
*/
#include <iostream>


void printSelectionSortArray(int array[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        std::cout << array[i] << "  ";
    }
    std::cout << std::endl;
}


void SelectionSort(int array[], int arrSz)
{

    if (arrSz > 1)
    {
        for (int j = 0; j < arrSz - 1; j++)
        {
            for (int i = j + 1; i < arrSz; i++)
            {
                if (array[j] > array[i])
                {
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                }
            }
        }
    }
}


/// <summary>
/// Used to swap the lower element into the correct order/position
/// </summary>
/// <param name="arr"></param>
/// <param name="index1"></param>
/// <param name="index2"></param>
/// <returns></returns>
int & SortSwap(int *arr, int index1, int index2)
{
    int temp1 = arr[index1];    // 3
    int temp2 = arr[index2];    // 5

    arr[index1] = arr[index2];  // 5
    arr[index2] = temp1;        //3

    return *arr;
}