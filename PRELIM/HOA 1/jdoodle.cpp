#include <iostream>

class Triangle{
    private:
    double totalAngle, angleA, angleB, angleC;
    public:
    Triangle(double A, double B, double C);

    void setAngles(double A, double B, double C);

    bool validateTriangle();

};

int main() {
    Triangle set1(40,30,210);
    if(set1.validateTriangle()){
        std::cout<<"The shape is a valid triangle"<<std::endl;
    } else{
        std::cout<<"The shape is not a valid triangle \n";
    }
    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle= A+B+C;
}

void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle= A+B+C;
}

bool Triangle::validateTriangle() {
    return (totalAngle ==180);
}
