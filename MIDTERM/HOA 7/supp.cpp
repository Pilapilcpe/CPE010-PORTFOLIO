#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sortingAlgo.h"

const int maxSize= 100;
int unsortedArr[maxSize];

void displayArr(int arr[])
{
    for (int i=0; i<maxSize; i++){
        std::cout<< arr[i]<< " ";
    }
}


int main()
{
    srand(time(0));
    for (int i = 0; i<maxSize; i++){
        unsortedArr[i]= rand() % 5 +1;
    }

    std::cout <<"Unsorted Votes:\n";
    displayArr(unsortedArr);

    bubbleSort(unsortedArr, maxSize);

    std::cout <<"\nSorted Votes:\n";
    displayArr(unsortedArr);

    int count[6]= {0};
    for (int i= 0; i<maxSize; i++) {
        count[unsortedArr[i]]++;
    }

    std::cout << "\nResults:\n";
    std::cout << "Candidate 1: "<< count[1]<<" votes\n";
    std::cout << "Candidate 2: "<< count[2]<<" votes\n";
    std::cout << "Candidate 3: "<< count[3]<<" votes\n";
    std::cout << "Candidate 4: "<< count[4]<<" votes\n";
    std::cout << "Candidate 5: "<< count[5]<<" votes\n";


    int winner= 1;
    for (int i= 2; i<= 5;i++){
        if (count[i] > count[winner])
        {
            winner= i;
        }
    }

    std::cout << "\nWinner: Candidate "<< winner << std::endl;

    return 0;
}