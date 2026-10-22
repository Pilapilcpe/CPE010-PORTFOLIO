#ifndef CPE010_HOA9p1_6_sc2_h
#define CPE010_HOA9p1_6_sc2_H
#include<iostream>

template <typename T>
class GeneralTree{
    private:
    T key;
    GeneralTree<T>* firstChild;
    GeneralTree<T>* nextSibling;

    public:
    GeneralTree(T value);
    ~GeneralTree();

    GeneralTree<T>* find(T value);
    bool addChild(T parentValue,T childValue);

    void preOrder();
    void inOrder();
    void postOrder();

    bool searchPreOrder(T value);
    bool searchInOrder(T value);
    bool searchPostOrder(T value);
    void findData(int choice, T value);
};

template <typename T>
GeneralTree<T>::GeneralTree(T value){
    key= value;
    firstChild= nullptr;
    nextSibling= nullptr;
}

template <typename T>
GeneralTree<T>::~GeneralTree(){
    delete firstChild;
    delete nextSibling;
}

template <typename T>
GeneralTree<T>* GeneralTree<T>::find(T value){
    if(key == value){
        return this;
    }

    if(firstChild != nullptr){
        GeneralTree<T>* found= firstChild->find(value);
        if(found != nullptr){
            return found;
        }
    }

    if(nextSibling != nullptr){
        return nextSibling->find(value);
    }
    return nullptr;
}

template <typename T>
bool GeneralTree<T>::addChild(T parentValue,T childValue){
    GeneralTree<T>* parent= find(parentValue);
    if(parent == nullptr){
        return false;
    }

    GeneralTree<T>* newNode = new GeneralTree<T>(childValue);

    if(parent->firstChild == nullptr){
        parent->firstChild= newNode;
    }else{
        GeneralTree<T>* current= parent->firstChild;
        while(current->nextSibling != nullptr){
            current= current->nextSibling;
        }
        current->nextSibling= newNode;
    }
    return true;
}

template <typename T>
void GeneralTree<T>::preOrder(){
    std::cout<< key << "  ";
 
    for(GeneralTree<T>* current = firstChild; current != nullptr; current=current->nextSibling){
        current->preOrder();
    }
}
 
template <typename T>
void GeneralTree<T>::inOrder(){
 
    if(firstChild == nullptr){
        std::cout<< key << "  ";
        return;
    }

    firstChild->inOrder();
    std::cout << key << "  ";
    for(GeneralTree<T>* current = firstChild->nextSibling; current != nullptr; current=current->nextSibling){
        current->inOrder();
    }
}
 
template <typename T>
void GeneralTree<T>::postOrder(){
    for(GeneralTree<T>* current = firstChild; current != nullptr; current=current->nextSibling){
        current->postOrder();
    }
    std::cout<< key << "  ";
}

template <typename T>
bool GeneralTree<T>::searchPreOrder(T value){
    if(key == value){
        return true;
    }
    for(GeneralTree<T>* current = firstChild; current != nullptr; current=current->nextSibling){
        if(current->searchPreOrder(value)){
            return true;
        }
    }
    return false;
}
 
template <typename T>
bool GeneralTree<T>::searchInOrder(T value){
    if(firstChild == nullptr){
        return key == value;
    }
    if(firstChild->searchInOrder(value)){
        return true;
    }
    if(key == value){
        return true;
    }
    for(GeneralTree<T>* current = firstChild->nextSibling; current != nullptr; current=current->nextSibling){
        if(current->searchInOrder(value)){
            return true;
        }
    }
    return false;
}
 
template <typename T>
bool GeneralTree<T>::searchPostOrder(T value){
    for(GeneralTree<T>* current = firstChild; current != nullptr; current=current->nextSibling){
        if(current->searchPostOrder(value)){
            return true;
        }
    }
    return key == value;
}

template <typename T>
void GeneralTree<T>::findData(int choice, T value){
    bool found = false;

    if(choice == 1){
        found= searchPreOrder(value);
    }else if(choice == 2){
        found= searchInOrder(value);
    }else if(choice == 3){
        found= searchPostOrder(value);
    }
    if(found){
        std::cout << value << " is found!" << std::endl;
    }
}

#endif