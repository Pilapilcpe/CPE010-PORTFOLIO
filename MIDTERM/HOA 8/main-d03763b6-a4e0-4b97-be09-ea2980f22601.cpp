#include <iostream>
#include <cstdlib>
#include <time.h>
#include "SortingAlgo.h"

const int maxSize=100;
int unsortedArr[maxSize];

void displayArr(int arr[]);

int main()
{
    srand(time(0));

    for (int i =0; i <maxSize; i++){
        unsortedArr[i]=rand() % 100;
    }
    std::cout <<"Unsorted: \n";
    displayArr(unsortedArr);

    std::cout <<"\nShell sort: \n";
    shellSort(unsortedArr, maxSize);
    displayArr(unsortedArr);

    std::cout <<"\nQuick sort: \n";
    quickSort(unsortedArr, 0, maxSize - 1);
    displayArr(unsortedArr);

    std::cout <<"\nMerge sort: \n";
    mergeSort(unsortedArr, 0, maxSize - 1);
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
