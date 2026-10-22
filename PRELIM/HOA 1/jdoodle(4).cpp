#include <iostream>
#include <cmath>

class Triangle {
private:
    double totalAngle;
    double angleA, angleB, angleC;
    double sideA, sideB, sideC;

public:
    Triangle(double A, double B, double C,
             double a, double b, double c);

    void setValues(double A, double B, double C,
                   double a, double b, double c);

    bool validateTriangle();

    double computePerimeter();

    double computeArea();

    void triangleType();
};

int main() {
    Triangle set1(60, 60, 60, 5, 5, 5);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle\n";
        std::cout << "Perimeter: " << set1.computePerimeter() << std::endl;
        std::cout << "Area: " << set1.computeArea() << std::endl;
        set1.triangleType();
    }
    else {
        std::cout << "The shape is not a valid triangle\n";
    }

    return 0;
}

Triangle::Triangle(double A, double B, double C,
                   double a, double b, double c) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = a;
    sideB = b;
    sideC = c;
}

void Triangle::setValues(double A, double B, double C,
                         double a, double b, double c) {
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;

    sideA = a;
    sideB = b;
    sideC = c;
}

bool Triangle::validateTriangle() {
    return (totalAngle == 180);
}

double Triangle::computePerimeter() {
    return sideA + sideB + sideC;
}

double Triangle::computeArea() {
    double s = computePerimeter() / 2;
    return std::sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

void Triangle::triangleType() {
    if (angleA < 90 && angleB < 90 && angleC < 90) {
        std::cout << "Triangle Type: Acute-angle" << std::endl;
    }
    else if (angleA > 90 || angleB > 90 || angleC > 90) {
        std::cout << "Triangle Type: Obtuse-angle";
    }
    
}

