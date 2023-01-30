#ifndef AVL_2_HPP
#define AVL_2_HPP
#include <iostream>
#include <fstream>

typedef struct Node{
    int data;
    Node* left;
    Node* right;
}Node;

Node* get_new_node(const int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void realse_memory(Node* node){
    if(node != NULL){
        realse_memory(node->left);
        realse_memory(node->right);
        delete node;
    }
}

Node* get_max_node(Node* node){
    if(node == NULL) return NULL;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
}

int get_height(const Node* node){
    if(node == NULL) return -1;
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    return std::max(left_height, right_height) + 1;
}

int get_balance_factor(const Node* node){
    if(node == NULL) return -1;
    return get_height(node->left) - get_height(node->right);
}

Node* LL(Node* node){
    Node* child_node = node->left;
    node->left = child_node->right;
    child_node->right = node;
    return child_node;
}

Node* RR(Node* node){
    Node* child_node = node->right;
    node->right = child_node->left;
    child_node->left = node;
    return child_node;
}

Node* LR(Node* node){
    node->left = RR(node->left);
    return LL(node);
}

Node* RL(Node* node){
    node->right = LL(node->right);
    return RR(node);
}

Node* adjust_balance(Node* node){
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

void inorder_traversal(const Node* node){
    if(node != NULL){
        inorder_traversal(node->left);
        std::cout << node->data << ' ';
        inorder_traversal(node->right);
    }
}

void record_balance_factor_error(const Node* node){
    std::string file_name = "error_report.txt";
    std::ofstream file_out;
    file_out.open(file_name, std::ios_base::app);
    file_out << node->data << ' ' << get_height(node) << ' ' << get_balance_factor(node) << '\n';
    file_out.close();    
}

void show_height_balance_factor(const Node* node){
    if(node != NULL){
        show_height_balance_factor(node->left);
        std::cout << "data: " << node->data << ", height: " << get_height(node) << ", balance factor: " << get_balance_factor(node) << '\n';
        if(get_balance_factor(node) >= 2) record_balance_factor_error(node);        
        show_height_balance_factor(node->right);
    }
}

Node* insert_operation(Node* node, const int data){
    if(node == NULL) node = get_new_node(data);
    else if(node->data > data) node->left = insert_operation(node->left, data);
    else if(node->data < data) node->right = insert_operation(node->right, data);
    node = adjust_balance(node);
    return node;
}

Node* remove_operation(Node* node, const int data){
    if(node == NULL) return node;

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
            ptr = get_max_node(node);
            node->data = ptr->data;
            node->left = remove_operation(node->left, ptr->data);
        }
    }
    node = adjust_balance(node);
    return node;
}

class AVL{
    private:
        Node* root;
    public:
        AVL(){
            root = NULL;
        }
        ~AVL(){
            realse_memory(root);
        }
        void insert(const int data){
            root = insert_operation(root, data);
        }
        void remove(const int data){
            root = remove_operation(root, data);
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
        void show() const{
            inorder_traversal(root);
            std::cout << "\n\n[data, height, balance factor information]\n";
            show_height_balance_factor(root);
        }
};  

#endif // AVL_2_HPP