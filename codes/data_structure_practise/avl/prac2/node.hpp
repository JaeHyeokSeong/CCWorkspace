#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>

class Node{
    public:
        int data, height;
        Node* left;
        Node* right;
        Node(const int data);
};

namespace nde{
    // create Node object from heap memory and return the object
    Node* new_node(const int data);
    // delete Node object from heap memory
    void delete_node(const Node* node);
}

#endif // NODE_HPP