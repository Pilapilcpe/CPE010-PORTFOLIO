#include <iostream>
#include <cmath>

double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}

int main() {
    double x1, y1, x2, y2;

    std::cout << "enter the first points (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "enter the second points x2 y2: ";
    std::cin >> x2 >> y2;

    std::cout << "distance is= " << distance(x1, y1, x2, y2);

    return 0;
}

