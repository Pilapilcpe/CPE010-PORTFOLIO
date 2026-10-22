#include <iostream>
#include <string>
#include "stacklist.h"

int main(){

    std::cout<< "--- PUSHING 'c' 'p' 'e' ---";

    push('c');
    push('p');
    push('e');

    top<char>();

    std::cout<<"\n --- POP all elements --- \n";
    while(!isEmpty<char>()){
        std::cout<<"Popped: "<<pop<char>()<<std::endl;

    }
    std::string expression;
    std::cout<<"\n --- Testing the Underflow --- \n";
    pop<char>();

    std::cout<<"\n --- Display all --- \n";
    display<char>();


// ILOC

    //read input expression
    std::cout << "Enter an expression: ";
    std::getline(std::cin, expression);

    // check whether the symbols are balanced
    if (iloc(expression)) {
        //opening and closing symbols matched
        std::cout << "expression is valid." << std::endl;
    } else {
        // incorrect symbol was found
        std::cout << "expression is invalid" << std::endl;
    }

    return 0;
}