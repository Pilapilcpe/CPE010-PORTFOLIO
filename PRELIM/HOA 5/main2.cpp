#include <iostream>
#include "QUEUE.h"

int main(){
    

    qnode<char>* front = nullptr;
    qnode<char>* back = nullptr;


    enqueue(&front, &back, 'L');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'O');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'R');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'E');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'E');
    std::cout << front->data << " " << back->data << std::endl;
    enqueue(&front, &back, 'N');
    std::cout << front->data << " " << back->data << std::endl;
    dequeue(&front, &back);
    std::cout << front->data << " " << back->data << std::endl;
    frontvar(&front);
    Display(&front, &back);
    



    return 0;
}