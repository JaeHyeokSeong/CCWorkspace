#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include <iostream>

// enum for traversal method
enum traversal{
    INORDER_TRAVERSAL = 1,
    POSTORDER_TRAVERSAL
};

// node structure
typedef struct Node{
    int data;
    Node* left, *right;
}Node;

// create a new node from heap memory and return
Node* create_new_node(const int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// remove a node memory from heap memory
void remove_node_memory(const Node* node){
    delete node;
}

// find a node which has the biggest data in tree
Node* find_max_node(Node* node){
    if(node == NULL) return node;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

// print node data
void print_node_data(const Node* node){
    std::cout << node->data << ' ';
}

// print new line
void print_new_line(){
    std::cout << '\n';
}

// inorder traversal
void inorder_traversal(const Node* node, void (*func)(const Node*)){
    if(node != NULL){
        inorder_traversal(node->left, func);
        func(node);
        inorder_traversal(node->right, func);
    }
}

// postorder traversal
void postorder_traversal(const Node* node, void (*func)(const Node*)){
    if(node != NULL){
        postorder_traversal(node->left, func);
        postorder_traversal(node->right, func);
        func(node);
    }
}
 
// use recursive function to find proper insertion position
Node* insert_operation(Node* node, const int data){
    if(node == NULL) node = create_new_node(data);
    else if(node->data > data) node->left = insert_operation(node->left, data);
    else if(node->data < data) node->right = insert_operation(node->right, data);
    else{
        // duplicated data is not allowed
    }
    return node;
}

// use recursive function to find proper removing position
Node* remove_operation(Node* node, const int data){
    if(node == NULL) return node;

    if(node->data > data) node->left = remove_operation(node->left, data);
    else if(node->data < data) node->right = remove_operation(node->right, data);
    else{
        // target data has found
        Node* ptr = node;
        // 4 cases
        // no childs both left and right
        if(node->left == NULL && node->right == NULL){
            remove_node_memory(node);
            node = NULL;
        }
        // left child exist and no right child
        else if(node->left != NULL && node->right == NULL){
            node = node->left;
            remove_node_memory(ptr);
        } 
        // right child exist and no left child
        else if(node->right != NULL && node->left == NULL){
            node = node->right;
            remove_node_memory(ptr);
        }
        // both left right childs exist
        else{
            ptr = find_max_node(node->left);
            node->data = ptr->data;
            node->left = remove_operation(node->left, ptr->data);
        }
    }
    return node;
}

// Binary Search Tree class 
class Binary_Search_Tree{
    private:
        Node* root;
    public:
        // constructor
        Binary_Search_Tree(){
            root = NULL;
        }
        // deconstructor
        ~Binary_Search_Tree(){
            // remove nodes' addresses from heap memory
            postorder_traversal(root, remove_node_memory);
        }
        // insert 
        void insert(const int data){
            root = insert_operation(root, data);
        }
        // remove
        void remove(const int data){
            root = remove_operation(root, data);
        }
        // show
        void show(){
            int choice = 0;
            std::cout << "[1] INORDER_TRAVERSAL, [2] POSTORDER_TRAVERSAL, [Any Number] CANCEL\n";
            std::cin >> choice;
            switch(choice){
                case INORDER_TRAVERSAL:
                    inorder_traversal(root, print_node_data);
                    print_new_line();
                    break;
                case POSTORDER_TRAVERSAL:
                    postorder_traversal(root, print_node_data);
                    print_new_line();
                    break;
                default:
                    std::cout << "Canceled\n";
                    break;
            }
        }
};

#endif // BINARY_SEARCH_TREE_HPP  