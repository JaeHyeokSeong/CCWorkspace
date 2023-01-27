#ifndef BST_HPP
#define BST_HPP

#include <iostream>

typedef struct Node{
    int value;
    Node* left;
    Node* right;
}Node;

Node* create_node(const int value){
    Node* new_node = new Node;
    new_node->value = value;
    new_node->right = NULL;
    new_node->left = NULL;
    return new_node;
}

void delete_memory(Node* n){
    if(n != NULL){
        delete_memory(n->left);
        delete n;
        delete_memory(n->right);
    }
}

void inorder_traversal(Node* n){
    if(n != NULL){
        inorder_traversal(n->left);
        std::cout << n->value << ' ';
        inorder_traversal(n->right);
    }
}

Node* search_max_node(Node* n){
    if(n == NULL) return NULL;

    while(n->right != NULL){
        n = n->right;
    }
    return n;
}

Node* remove_operation(Node* node, const int value){
    if(node == NULL) return node;

    if(node->value > value) node->left = remove_operation(node->left, value);
    else if(node->value < value) node->right = remove_operation(node->right, value);
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
            ptr = search_max_node(node->left);
            node->value = ptr->value;
            node->left = remove_operation(node->left, ptr->value);
        }
    }
    return node;
}

class BST{
    private:
        Node* root;
    public:
        BST(){
            root = NULL;
        }
        ~BST(){
            delete_memory(root);
        }
        void add(const int value){
            Node* node = create_node(value);
            if(root == NULL)
                root = node;
            else{
                Node* ptr = root;
                Node* tmp_p = NULL;
                while(ptr != NULL){
                    tmp_p = ptr;
                    if(value < ptr->value) ptr = ptr->left;
                    else if(value > ptr->value) ptr = ptr->right;
                    else return; // 중복값 허용 안됨
                }
                if(value < tmp_p->value) tmp_p->left = node;
                else tmp_p->right = node;
            }
        }
        bool search(const int value) const{
            Node* ptr = root;

            while(ptr != NULL){
                if(value == ptr->value) return true;
                else if(value < ptr->value) ptr = ptr->left;
                else ptr = ptr->right;
            }
            return false;
        }
        void remove(const int value){
            root = remove_operation(root, value);
        }
        void show(){
            inorder_traversal(root);
            std::cout << '\n';
        }
};

#endif // BST_HPP