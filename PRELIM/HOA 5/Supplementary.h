#ifndef SUPPLEMENTARY_H
#define SUPPLEMENTARY_H
#include <iostream>
#include <string>

//STEP 1
class Job {
public:
    int id;
    std::string name; 
    int pages;

    Job(int i, std::string n, int p)
        : id(i), name(n), pages(p) {}
};
 //STEP 2
template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& job) : data(job), next(nullptr) {}
}; 


//STEP 3
template <typename T>
class Printer {
private:
    Node<T>* front;
    Node<T>* back;


public:
    Printer() : front(nullptr), back(nullptr) {}

    ~Printer() {
        while (front != nullptr) {
            Node<T>* temp = front;
            front = front->next;
            delete temp;
        }
    }


    Printer(const Printer&) = delete;
    Printer& operator=(const Printer&) = delete;

    void add(const T& job) {
        Node<T>* newNode = new Node<T>(job);

        if (front == nullptr) {
            front = newNode;
            back = newNode;
        }
        else {
            back->next = newNode;
            back = newNode;
        }


        std::cout << "Job " << job.id << " added." << std::endl;
    }

    void process() {
        while (front != nullptr) {
            Node<T>* temp = front;


            std::cout << "Processing Job " << temp->data.id
                      << " = User: " << temp-> data.name
                      << " = Pages: " << temp-> data.pages
                      << std::endl;

            front = front->next;


            if (front ==nullptr) {
                back =nullptr;
            }

            delete temp;
        }
    }

};

#endif