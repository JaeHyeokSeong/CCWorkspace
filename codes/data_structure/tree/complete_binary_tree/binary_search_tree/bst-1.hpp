#ifndef BST_1_HPP
#define BST_1_HPP

#include <iostream>

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* create_node(const int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* find_max_node(Node* node){
    if(node == NULL) return NULL;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

void realse_memory(Node* node){
    if(node != NULL){
        realse_memory(node->left);
        realse_memory(node->right);
        delete node;
    }
}

Node* remove_operation(Node* node, const int data){
    if(node == NULL) return NULL;

    if(node->data > data) node->left = remove_operation(node->left, data);
    else if(node->data < data) node->right = remove_operation(node->right, data);
    else{
        Node* ptr = node;
        if(node->left == NULL && node->right == NULL){
            delete node;
            node = NULL;
        } else if(node->left != NULL && node->right == NULL){
            node = node->left;
            delete ptr;
        } else if(node->right != NULL && node->left == NULL){
            node = node->right;
            delete ptr;
        } else{
            ptr = find_max_node(node->left);
            node->data = ptr->data;
            node->left = remove_operation(node->left, ptr->data);
        }
    }
    return node;
}

void show_inorder_traversal(const Node* node){
    if(node != NULL){
        show_inorder_traversal(node->left);
        std::cout << node->data << ' ';
        show_inorder_traversal(node->right);
    }
}

class BST{
    private:
        Node* root;
    public:
        BST(){
            root = NULL;
        }
        ~BST(){
            realse_memory(root);
        }
        void add(const int data){
            Node* node = create_node(data);
            if(root == NULL) root = node;
            else{
                Node* ptr = root;
                Node* p_ptr = NULL;
                while(ptr != NULL){
                    p_ptr = ptr;
                    if(ptr->data > data) ptr = ptr->left; 
                    else if(ptr->data < data) ptr = ptr->right;
                    else return; // 중복값 허용 안함
                }
                if(p_ptr->data > data) p_ptr->left = node;
                else p_ptr->right = node;
            }
        }
        bool search(const int data){
            Node* ptr = root;
            while(ptr != NULL){
                if(ptr->data == data) return true;
                else if(ptr->data > data) ptr = ptr->left;
                else ptr = ptr->right;
            }
            return false;
        }
        void remove(const int data){
            root = remove_operation(root, data);
        }
        void show(){
            show_inorder_traversal(root);
            std::cout << '\n';
        }
};

#endif // BST_1_HPP