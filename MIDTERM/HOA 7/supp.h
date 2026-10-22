#ifndef SORTINGALGO_H
#define SORTINGALGO_H


template <typename T>
void bubbleSort(T arr[],int arrSize)
{
    for (int i =0; i< arrSize - 1; i++){
        for (int j =0; j< arrSize - i - 1; j++){
            if (arr[j] > arr[j +1]){

                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

#endif