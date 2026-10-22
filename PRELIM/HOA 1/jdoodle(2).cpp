#include <iostream>

double kelvintofah(double kelvin) {
    return (kelvin - 273.15) * 9 / 5 + 32;
}

int main() {
    double kelvin;

    std::cout << "temperature in Kelvin: ";
    std::cin >> kelvin;

    std::cout << "temperature in Fahrenheit: "
              << kelvintofah(kelvin);

    return 0;
}


