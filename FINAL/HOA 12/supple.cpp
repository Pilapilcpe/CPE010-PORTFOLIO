#include <iostream>
#include <vector>
#include <string>


int countPaths(const std::vector<std::vector<int>>& mat, int i, int j, int cost) {
    // base case
    if (i < 0 || j < 0 || cost < 0) return 0;

    // base case
    if (i == 0 && j == 0) return (mat[0][0] == cost) ? 1 : 0;

    // recursive case
    return countPaths(mat, i - 1, j, cost - mat[i][j]) +
           countPaths(mat, i, j - 1, cost - mat[i][j]);
}

// Prints paths
void printPaths(const std::vector<std::vector<int>>& mat, int i, int j,
                int sum, int cost, std::string moves) {
    sum += mat[i][j];
    if (sum > cost) return;
    if (i == (int)mat.size() - 1 && j == (int)mat[0].size() - 1) {
        if (sum == cost) std::cout << "  " << moves << "\n";
        return;
    }
    if (j + 1 < (int)mat[0].size()) printPaths(mat, i, j + 1, sum, cost, moves + "R");
    if (i + 1 < (int)mat.size())    printPaths(mat, i + 1, j, sum, cost, moves + "D");
}

int main() {
    std::vector<std::vector<int>> mat = {
        {4, 7, 1, 6},
        {5, 7, 3, 9},
        {3, 2, 1, 2},
        {7, 1, 6, 3}};
    int cost = 25;
    int M = mat.size(), N = mat[0].size();

    std::cout << "Matrix:\n";
    for (const auto& row : mat) {
        for (int v : row) std::cout << v << " ";
        std::cout << "\n";
    }

    std::cout << "\nTarget cost    : " << cost << "\n";
    std::cout << "Number of paths: " << countPaths(mat, M - 1, N - 1, cost) << "\n";
    std::cout << "Paths found:\n";
    printPaths(mat, 0, 0, 0, cost, "");
    return 0;
}