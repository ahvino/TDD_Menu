#pragma once

#include <iostream>


void Merge(int  arr[], int left, int mid, int right)
{
    int arrLftSz = mid - left + 1;
    int arrRgtSz = right - mid;

    //create temp arrays
    int * leftArr = new int[arrLftSz];
    int * rightArr = new int[arrRgtSz];

    //copy data into new arrays
    for (int i = 0; i < arrLftSz; i++)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < arrRgtSz; i++)
    {
        rightArr[i] = arr[mid + 1 + i];
    }

    int lftSubArrIndex = 0;
    int rgtSubArrIndex = 0;
    int arrIndex = left;

    while (lftSubArrIndex < arrLftSz && rgtSubArrIndex < arrRgtSz)
    {
        if (leftArr[lftSubArrIndex] <= rightArr[rgtSubArrIndex])
        {
            arr[arrIndex] = leftArr[lftSubArrIndex];
            lftSubArrIndex++;
        }
        else
        {
            arr[arrIndex] = rightArr[rgtSubArrIndex];
            rgtSubArrIndex++;
        }
        arrIndex++;
    }

    while (lftSubArrIndex < arrLftSz)
    {
        arr[arrIndex] = leftArr[lftSubArrIndex];
        arrIndex++;
        lftSubArrIndex++;
    }

    while (rgtSubArrIndex < arrRgtSz)
    {
        arr[arrIndex] = rightArr[rgtSubArrIndex];
        arrIndex++;
        rgtSubArrIndex++;
    }


    delete[] leftArr;
    delete[] rightArr;
}


void printMergeSortArray(int array[], int sz)
{
    std::cout << "\n=======START OF ARRAY======\n";

    for (int i = 0; i < sz; i++)
    {
        std::cout << array[i] << "  ";
    }

    std::cout << "\n=======END OF ARRAY======\n";
}

/// <summary>
/// Merge sort splits the array into 2 parts via along the mid variable,
/// we then recursively call erge sort until the left is greater than 
/// or equal to the right
/// </summary>
/// <param name="arr"></param>
/// <param name="left"></param>
/// <param name="right"></param>
void MergeSort(int arr[], int left, int right)
{

    if (left >= right) return;

    //recursively call megre sort
    int mid = left + (right - left) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    Merge(arr, left, mid, right);

}