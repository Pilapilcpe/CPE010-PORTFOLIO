#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <vector>

const int maxSize = 100;
int unsortedArr[maxSize];

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArr(int arr[])
{
    for (int i = 0; i < maxSize; i++){
        std::cout << arr[i] << " ";
    }
}

void countVotes(int arr[], int start, int end, int localCount[])
{
    for (int i = start; i < end; i++){
        localCount[arr[i]]++;
    }
}

int main()
{
    srand(time(0));
    for (int i = 0; i < maxSize; i++){
        unsortedArr[i] = rand() % 5 + 1;
    }

    std::cout << "Unsorted Votes:\n";
    displayArr(unsortedArr);

    bubbleSort(unsortedArr, maxSize);

    std::cout << "\nSorted Votes:\n";
    displayArr(unsortedArr);

    //creates the threads
    const int numThreads = 4;
    int localCounts[numThreads][6] = {};
    std::vector<std::thread> threads;
    int chunk = maxSize / numThreads;

    for (int t = 0; t < numThreads; t++){
        int start = t * chunk;
        int end = (t == numThreads - 1) ? maxSize : start + chunk;
        threads.emplace_back(countVotes, unsortedArr, start, end, localCounts[t]);
    }

    for (auto& th : threads) th.join();
//combines the results from each thread
    int count[6] = {0};
    for (int t = 0; t < numThreads; t++){
        for (int c = 1; c <= 5; c++){
            count[c] += localCounts[t][c];
        }
    }

    std::cout << "\nResults:\n";
    std::cout << "Candidate 1: " << count[1] << " votes\n";
    std::cout << "Candidate 2: " << count[2] << " votes\n";
    std::cout << "Candidate 3: " << count[3] << " votes\n";
    std::cout << "Candidate 4: " << count[4] << " votes\n";
    std::cout << "Candidate 5: " << count[5] << " votes\n";

    int winner = 1;
    for (int i = 2; i <= 5; i++){
        if (count[i] > count[winner])
        {
            winner = i;
        }
    }
    std::cout << "\nWinner: Candidate " << winner << std::endl;

    return 0;
}