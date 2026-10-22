#include <iostream>
#include "supple.h"

int main(){
    int prices[] = {99, 129, 149, 79, 9,
                    899, 399, 30, 89, 70};

    int n = 10;
    int pivot = partition(prices, 0, n - 1);

    mergeSort(prices, 0, pivot - 1);
    mergeSort(prices, pivot + 1, n - 1);

    std::cout <<"Sorted prices: ";

    for (int i = 0; i < n; i++)
        std::cout<< prices[i]<< " ";
    return 0;
}