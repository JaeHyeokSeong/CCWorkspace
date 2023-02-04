#ifndef AVL_HPP
#define AVL_HPP
#include <iostream>

typedef struct Node{
    int data, height;
    Node* left, *right;
}Node;
// create a new node
Node* new_node(const int data){
    Node* node = new Node;
    node->height = 1;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// delete a node
void delete_node(const Node* node){
    delete node;
}
// return a node's height
int get_height(const Node* node){
    if(node == NULL) return 0;
    return node->height;
}
// adjust node height
void adjust_height(Node** node){
    (*node)->height = std::max(get_height((*node)->left), get_height((*node)->right)) + 1;
}
// return node's balance factor
int get_balance_factor(const Node* node){
    if(node == NULL) return 0;
    return get_height(node->left) - get_height(node->right);
}
// LL
Node* LL(Node* node){
    Node* child_node = node->left;
    node->left = child_node->right;
    child_node->right = node;
    adjust_height(&node);
    adjust_height(&child_node);
    return child_node;
}
// RR
Node* RR(Node* node){
    Node* child_node = node->right;
    node->right = child_node->left;
    child_node->left = node;
    adjust_height(&node);
    adjust_height(&child_node);
    return child_node;
}
// LR
Node* LR(Node* node){
    node->left = RR(node->left);
    return LL(node);
}
// RL
Node* RL(Node* node){
    node->right = LL(node->right);
    return RR(node);
}
// adjust balance factor
Node* adjust_balance_factor(Node* node){
    if(node == NULL) return node;
    int balance_factor = get_balance_factor(node);
    if(balance_factor >= 2){
        balance_factor = get_balance_factor(node->left);
        if(balance_factor >= 0) node = LL(node);
        else node = LR(node);
    } else if(balance_factor <= -2){
        balance_factor = get_balance_factor(node->right);
        if(balance_factor <= 0) node = RR(node);
        else node = RL(node);
    }
    return node;
}
// return a node which has the biggest data
Node* get_max_node(Node* node){
    if(node == NULL) return node;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}
// insert operation
Node* insert_operation(Node* node, const int data){
    if(node == NULL) return new_node(data);
    else if(node->data > data) node->left = insert_operation(node->left, data);
    else if(node->data < data) node->right = insert_operation(node->right, data);
    else{
        // duplicated value is not allowed
    }
    adjust_height(&node);
    return adjust_balance_factor(node);
}
// remove operation
Node* remove_operation(Node* node, const int data){
    if(node == NULL) return node;

    if(node->data > data) node->left = remove_operation(node->left, data);
    else if(node->data < data) node->right = remove_operation(node->right, data);
    else{
        Node* ptr = node;
        // 4 cases
        if(node->left == NULL && node->right == NULL){
            delete_node(node);
            node = NULL;
        } else if(node->left != NULL && node->right == NULL){
            node = node->left;
            delete_node(ptr);
        } else if(node->right != NULL && node->left == NULL){
            node = node->right;
            delete_node(ptr);
        } else{
            ptr = get_max_node(node->left);
            node->data = ptr->data;
            node->left = remove_operation(node->left, ptr->data);
        }
    }

    if(node != NULL){
        adjust_height(&node);
        node = adjust_balance_factor(node);
    }
    return node;
}
// print node data
void print_node_data(const Node* node){
    std::cout << node->data << ' ';
}
// print height and balance factor
void print_height_balance_factor(const Node* node){
    std::cout << "data: " << node->data << ", height: " << get_height(node) << ", balance factor: " << get_balance_factor(node) << '\n';
}
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

class AVL{
    private:
        Node* root;
    public:
        AVL();
        ~AVL();
        void insert(const int data);
        void remove(const int data);
        bool search(const int data);
        void show_inorder() const;
        void show_inorder_height_balance_factor() const;
};

AVL::AVL(){
    root = NULL;
}
AVL::~AVL(){
    postorder_traversal(root, delete_node);
}
void AVL::insert(const int data){
    root = insert_operation(root, data);
}
void AVL::remove(const int data){
    root = remove_operation(root, data);
}
bool AVL::search(const int data){
    Node* ptr = root;
    while(ptr != NULL){
        if(ptr->data == data) return true;
        else if(ptr->data > data) ptr = ptr->left;
        else ptr = ptr->right;
    }
    return false;
}
void AVL::show_inorder() const{
    inorder_traversal(root, print_node_data);
    print_new_line();
}
void AVL::show_inorder_height_balance_factor() const{
    inorder_traversal(root, print_height_balance_factor);
}

#endif // AVL_HPP