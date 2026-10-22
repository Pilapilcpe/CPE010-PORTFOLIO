#include <iostream>

struct Node{
    int val;
    Node* left;
    Node* right;
};
void preorder(Node* n){
    if (n == nullptr) return;
    std::cout<< n->val<<" ";
    preorder(n->left);
    preorder(n->right);
}

int main(){
    Node n4{4, nullptr, nullptr};
    Node n5{5, nullptr, nullptr};
    Node n6{6, nullptr, nullptr};
    Node n2{2, &n4, &n5};
    Node n3{3, nullptr, &n6};
    Node n1{1, &n2, &n3};

    preorder(&n1);
    return 0;
}
