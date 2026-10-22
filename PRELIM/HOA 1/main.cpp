#include <iostream>

void sumtwonum(int a, int b);
bool isgreater(int a, int b);
bool logicop(bool x, bool y);

int main(){
int num1, num2;
bool val1, val2;

std::cout<< "number: ";
std::cin>>num1;
std::cout<< "number: ";
std::cin>>num2;

sumtwonum(num1, num2);

if (isgreater(num1,num2))
std::cout<<num1<<" is greater than "<<num2<<std::endl;
else
std::cout<<num1<< " is less than "<<num2<<std::endl;

std::cout<< "enter a value: ";
std::cin>> val1;
std::cout<< "enter a value: ";
std::cin>> val2;

if (logicop(val1,val2))
std::cout<< "Logical Operations are successful!";

return 0;
}

void sumtwonum(int a, int b){
    std::cout<<"sum = "<<a + b<<std::endl;

}

bool isgreater(int a, int b){
    return a>b;
}

bool logicop(bool x, bool y){
    std::cout<<"\nLOGICAL OPERATIONS"<<std::endl;
    std::cout<<"x AND y = "<<(x&&y)<<std::endl;
    std::cout<<"x OR y = "<<(x||y)<<std::endl;
    std::cout<<"NOT x = "<<(!x)<<std::endl;
    std::cout<<"NOT y = "<<(!y)<<std::endl;
    std::cout<<"x XOR y = "<<(x!=y)<<std::endl;

    return true;
}