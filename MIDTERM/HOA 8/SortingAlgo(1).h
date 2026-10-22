#ifndef SORTINGALGO_H
#define SORTINGALGO_H


template <typename T>
void shellSort(T arr[], int size){
    for (int interval = size/2; interval >= 1; interval/=2){
        
        for (int i=interval; i < size; i++){
            T temp= arr[i];
            int j= i;

            while (j >= interval && arr[j - interval] > temp){
                arr[j] = arr[j - interval];
                j -= interval;
            }

            arr[j]= temp;
        }
    }
}

template <typename T>
int partition(T arr[], int low, int high){
    T pivot= arr[high];
    int i= low - 1;

    for (int j= low; j < high; j++){
        if (arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high){
    if (low < high){
        int pivotIndex= partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
template <typename T>
void merge(T arr[], int left, int middle, int right){
    int size1= middle - left + 1;
    int size2= right - middle;

    T* leftArr= new T[size1];
    T* rightArr= new T[size2];

    for (int i=0; i < size1; i++){
        leftArr[i]=arr[left + i];
    }

    for (int j= 0; j < size2; j++){
        rightArr[j] =arr[middle + 1 + j];
    }
    int i= 0;
    int j= 0;
    int k= left;

    while (i < size1 && j < size2){
        if (leftArr[i] <= rightArr[j]){
            arr[k] = leftArr[i];
            i++;
        }
        else{
            arr[k]= rightArr[j];
            j++;
        }
        k++;}

    while (i < size1){
        arr[k]= leftArr[i];
        i++;
        k++;
    }

    while (j <size2){
        arr[k]= rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

template <typename T>
void mergeSort(T arr[], int left, int right){
    if (left < right){
        int middle=left +(right - left)/2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
#endif