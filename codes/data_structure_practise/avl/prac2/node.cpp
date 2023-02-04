#include "node.hpp"

Node::Node(const int data){
    this->data = data;
    this->height = 1;
    this->left = NULL;
    this->right = NULL;
}

Node* nde::new_node(const int data){
    return new Node(data);
}
void nde::delete_node(const Node* node){
    delete node;
}