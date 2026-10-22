#include <iostream>

bool binarySearch(int data[], int low, int high, int key) {

    if (low > high) {
        return false;
    }
    int mid = (low + high)/2;
    std::cout <<"middle= "<< data[mid]<< std::endl;

    if (data[mid] == key) {
        return true;
    }
    else if (key < data[mid]) {
        return binarySearch(data,low, mid - 1, key);
    }
    else {
        return binarySearch(data, mid + 1,high,key);
    }
}

int main() {
    int data[10] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    int key = 8;

    if (binarySearch(data, 0, 9, key)) {
        std::cout <<"8 is found"<<std::endl;
    } else {
        std::cout <<"8 is not found"<<std::endl;
    }

    return 0;
}