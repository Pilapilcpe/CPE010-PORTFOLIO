#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> // will be used for our seeding function
#include "nodes.h"
#include "searching.h"

int main() {

    int dataset[5] = {10, 20, 30, 40, 50};

    int item;
    std::cout << "number to search: ";
    std::cin >> item;

    if (linearSearch(dataset, 5, item)) {
        std::cout <<"Searching is successful\n";
    }
    else {
        std::cout <<"Searching is unsuccessful\n";
    }
    //create linked list for linear search
    Node<char> *name1 = new_node('l');
    Node<char> *name2 = new_node('o');
    Node<char> *name3 = new_node('r');
    Node<char> *name4 = new_node('e');
    Node<char> *name5 = new_node('e');
    Node<char> *name6 = new_node('n');


    //linked list
    name1->next = name2;
    name2->next = name3;
    name3->next = name4;
    name4->next = name5;
    name5->next = name6;
    name6->next = NULL;

    //show linked list
    Node<char>* current = name1;


    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;


    if (linearLS(name1, 'n')) {
        std::cout <<"Searching is successful";
    }
    else {
        std::cout <<"Searching is unsuccessful";
    }

    if (binarySearch(dataset, 5, 30)) {
    std::cout << "\nelement is found";
    }
    else {
        std::cout << "\nelement is not found";
}

    Node<int>* node1 = new_node(10);
    Node<int>* node2 = new_node(20);
    Node<int>* node3 = new_node(30);
    Node<int>* node4 = new_node(40);
    Node<int>* node5 = new_node(50);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    Node<int>* head = node1;
    std::cout << "\nLinked List: ";

    Node<int>* current2 = head;

    while (current2 != NULL) {
        std::cout << current2->data << " ";
        current2 = current2->next;
    }
    std::cout << std::endl;
    int searchItem;

    std::cout << "Enter number to search: ";
    std::cin >> searchItem;

    if (binarySearchLL(head, searchItem)) {
        std::cout <<"element is found" << std::endl;
    }
    else {
        std::cout <<"element is not found" << std::endl;
    }

    return 0;
}