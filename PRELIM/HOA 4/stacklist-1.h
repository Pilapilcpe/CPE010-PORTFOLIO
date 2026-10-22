#ifndef STACK_LIST_H
#define STACK_LIST_H


template <typename T>
class Node{
    public:
    T data;
    Node* next;
};

template <typename T>
Node<T> *head = nullptr;

//push
template <typename T>
void push(T newData){
    Node<T>* newNode= new Node<T>;
    newNode->data = newData;
    newNode->next = head<T>;
    head<T> = newNode;

}
//pop
template <typename T>
T pop(){
    if(head<T> ==nullptr){ //check if stack is empty
        std::cout<<"Stack is empty"<<std::endl;
        return T();
    }
    Node<T>* temp = head<T>; //save current top node

    T tempVal= temp->data; //store data

    head<T> =head<T>->next;//move head

    delete temp;//free removed node

    return tempVal; //return removed value
}

//isEmpty
template <typename T>
bool isEmpty(){
    return head<T> ==nullptr;
}

//top
template <typename T>
void top(){
    if(head<T> == nullptr){
        std::cout<<"Stack undeflow"<<std::endl;
        return;
    }
    std::cout<<"\n Top of stack: "<<head<T>->data<<std::endl;
}

//display all
template <typename T>
void display(){
    if (head<T> == nullptr){
        std::cout<<"stack underflow\n";
    }
    Node<T>* temp = head<T>;
    while(temp != nullptr){
        std::cout<<temp->data<<",";
        temp = temp->next;
    }
    std::cout<<"\n";

}

// ILOC
// Checks whether the symbols are balanced
bool iloc(std::string expression){

    // clear the stack
    while(!isEmpty<char>())
        pop<char>();

    // read each character
    for(char ch : expression){

        // ignore characters 
        if(ch != '(' && ch != ')' &&
           ch != '{' && ch != '}' &&
           ch != '[' && ch != ']'){
            continue;
        }

        if(ch == '(' || ch == '{' || ch == '['){
            push<char>(ch); //push 
        }

        // character is a closing symbol
        else{

            // If the stack is empty
            if(isEmpty<char>()){
                std::cout << "Error: Stack is empty." << std::endl;
                return false;
            }

            // pop the top opening symbol
            char topSymbol = pop<char>();

            // check if the symbols matches
            if((ch == ')' && topSymbol != '(') ||
               (ch == '}' && topSymbol != '{') ||
               (ch == ']' && topSymbol != '[')){
                std::cout << "Error: Symbols do not match." << std::endl;
                return false;
            }
        }
    }

    // if the stack is not empty
    if(!isEmpty<char>()){
        std::cout << "Error: Stack is not empty." << std::endl;
        return false;
    }

    // if all symbols matches
    return true;
}
#endif