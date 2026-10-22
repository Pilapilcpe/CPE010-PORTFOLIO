#include <iostream>

int main() {
    int a = 10;
    int b = 20;
    int temp;

    std::cout << "before:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    temp = a;
    a = b;
    b = temp;

    std::cout << "\nafter:\n";
    std::cout << "a = " << a << "\n";
    std::cout << "b = " << b << "\n";

    return 0;
}
