#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int maxSize=100;
int unsortedArr[maxSize];

void displayArr(int arr[]);

int main()
{
    srand(time(0));

    for (int i =0; i <maxSize; i++)
    {
        unsortedArr[i]=rand() % 100;
    }

    std::cout <<"Unsorted: \n";
    displayArr(unsortedArr);

    std::cout <<"\nBubble sort: \n";
    bubbleSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout <<"\nInsertion sort: \n";
    insertionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout <<"\nSelection sort: \n";
    selectionSort(unsortedArr, maxSize);
    displayArr(unsortedArr);


    return 0;
}

void displayArr(int arr[])
{
    for (int i =0; i< maxSize; i++)
    {
        std::cout <<arr[i]<< " ";
    }

    std::cout <<std::endl;
}