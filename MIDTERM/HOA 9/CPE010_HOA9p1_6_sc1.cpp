#include "CPE010_HOA9p1_6_sc2.h"
#include <iostream>

int main(){

    GeneralTree<char> tree('A');

    tree.addChild('A', 'B');
    tree.addChild('A', 'C');
    tree.addChild('A', 'D');
    tree.addChild('A', 'E');
    tree.addChild('A', 'F');
    tree.addChild('A', 'G');

    tree.addChild('D', 'H');

    tree.addChild('E', 'I');
    tree.addChild('E', 'J');

    tree.addChild('F', 'K');
    tree.addChild('F', 'L');
    tree.addChild('F', 'M');

    tree.addChild('G', 'N');

    tree.addChild('J', 'P');
    tree.addChild('J', 'Q');

    std::cout << "Pre-order:  ";
    tree.preOrder();
    std::cout << std::endl;
 
    std::cout << "In-order:   ";
    tree.inOrder();
    std::cout << std::endl;
 
    std::cout << "Post-order: ";
    tree.postOrder();
    std::cout << std::endl;

    tree.findData(1, 'J');
    tree.findData(2, 'P');
    tree.findData(3, 'N');
    tree.findData(1, 'Z');

    tree.addChild('G', 'O');
 
    tree.findData(1, 'O');
    tree.findData(2, 'O');
    tree.findData(3, 'O');
    std::cout << std::endl;

    std::cout << "Pre-order:  ";
    tree.preOrder();
    std::cout << std::endl;

    std::cout << "In-order:   ";
    tree.inOrder();
    std::cout << std::endl;

    std::cout << "Post-order: ";
    tree.postOrder();
    std::cout << std::endl;

    return 0;
}