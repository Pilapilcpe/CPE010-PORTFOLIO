#include <iostream>

int sequentialSC(int arr[], int size, int k) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == k) {
            count++;
        }
    }
    return count;
}

int main() {
    int dataset[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    int k;

    std::cout <<"search element: ";
    std::cin >> k;

    int count = sequentialSC(dataset, 10, k);

    std::cout <<"No. of repeating instances: " << count << std::endl;


    return 0;
}