#ifndef SUPPLE_H
#define SUPPLE_H

void mergeSort(int arr[], int left, int right){
    if (left >= right) return;

    int mid = (left + right)/ 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    int i =left, j= mid + 1, k = 0;
    int temp[10];

    while (i <= mid && j <= right){
        if (arr[i] < arr[j])
            temp[k++] =arr[i++];
        else
            temp[k++] =arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (int x = 0; x< k; x++)
        arr[left + x] =temp[x];
}
int partition(int arr[], int low, int high){
    int pivot =arr[high];
    int i = low;

    for (int j = low; j < high; j++){
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}
#endif