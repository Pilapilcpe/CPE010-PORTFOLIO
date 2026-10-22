#include <iostream>
#include "CPE010_HOA9p1_6_sc4.h"

int main(){

    BinarySearchTree<int> tree(2);

    tree.insert(3);
    tree.insert(9);
    tree.insert(18);
    tree.insert(0);
    tree.insert(1);
    tree.insert(4);
    tree.insert(5);

    
    std::cout << "Pre-order: ";
    tree.preOrder();
    std::cout << std::endl;
 
    std::cout << "In-order: ";
    tree.inOrder();
    std::cout << std::endl;
 
    std::cout << "Post-order: ";
    tree.postOrder();
    std::cout << std::endl;
    return 0;
}