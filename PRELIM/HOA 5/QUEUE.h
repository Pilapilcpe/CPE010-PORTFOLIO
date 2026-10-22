#ifndef QUEUE_H
#define QUEUE_H


template <typename T>
class qnode{
    public:
        T data;
        qnode *next;

};


template <typename T>
qnode<T> *new_Node(T newData){
    qnode<T>* newNode = new qnode<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}



template <typename T>
void enqueue(qnode<T>** frontptr, qnode<T>** backptr, T newData){
    qnode<T>* newNode = new_Node(newData);

    if ((*frontptr) == nullptr && (*backptr) == nullptr){
        
        (*frontptr) = newNode;
        (*backptr) = newNode;
    }


   
    (*backptr)->next = newNode;
    (*backptr) = newNode;
    

}



template <typename T>
void dequeue(qnode<T>** frontptr, qnode<T>** backptr){
    qnode<T>* deletenode = nullptr;
    deletenode = (*frontptr);
    



    if ((*frontptr)->next == nullptr && (*backptr)->next == nullptr){
        (*frontptr) = nullptr;
        (*backptr) = nullptr;
        delete deletenode;
        return;
    }


  
    (*frontptr) = deletenode->next;
    deletenode->next = nullptr;
    delete deletenode;
}





template <typename T>
void Display(qnode<T>** frontptr, qnode<T>** backptr)
{

    qnode<T>*  current = (*frontptr);

    while (current !=nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }


    std::cout << std::endl;
}


template <typename T>
void frontvar(qnode<T>** frontptr)
{

    if ((*frontptr) != nullptr)
    {

    }
}
#endif