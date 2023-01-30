#ifndef AVL_3_HPP
#define AVL_3_HPP
#include <iostream>
#include <fstream>
// https://yoongrammer.tistory.com/72
int count_removed_nodes = 0;

typedef struct Node{
    int data, height;
    Node* left, *right;
}Node;

Node* get_new_node(const int data){
    Node* n = new Node;
    n->data = data;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int get_height(const Node* n){
    if(n == NULL) return 0;
    return n->height;
}

int adjust_height(const Node* n){
    return std::max(get_height(n->left), get_height(n->right)) + 1;
}

Node* LL(Node* n){
    Node* c_n = n->left;
    n->left = c_n->right;
    c_n->right = n;
    // 높이 재조정
    n->height = adjust_height(n);
    c_n->height = adjust_height(c_n);
    return c_n;
}

Node* RR(Node* n){
    Node* c_n = n->right;
    n->right = c_n->left;
    c_n->left = n;
    // 높이 재조정
    n->height = adjust_height(n);
    c_n->height = adjust_height(c_n);
    return c_n;
}

Node* LR(Node* n){
    n->left = RR(n->left);
    return LL(n);
}

Node* RL(Node* n){
    n->right = LL(n->right);
    return RR(n);
}

int get_balance_factor(const Node* n){
    return get_height(n->left) - get_height(n->right);
}

Node* adjust_balance_factor(Node* n){
    int balance_factor = get_balance_factor(n);
    if(balance_factor >= 2){
        balance_factor = get_balance_factor(n->left);
        if(balance_factor >= 0) n = LL(n);
        else n = LR(n);
    } else if(balance_factor <= -2){
        balance_factor = get_balance_factor(n->right);
        if(balance_factor <= 0) n = RR(n);
        else n = RL(n);
    }
    return n;
}

Node* get_max_node(Node* n){
    if(n == NULL) return NULL;
    while(n->right != NULL){
        n = n->right;
    }
    return n;
}

void release_memory(Node* n){
    if(n != NULL){
        release_memory(n->left);
        release_memory(n->right);
        delete n;
    }
}

void inorder_traversal(const Node* n){
    if(n != NULL){
        inorder_traversal(n->left);
        std::cout << n->data << ' ';
        inorder_traversal(n->right);
    }
}

void get_height_balance(const Node* n){
    if(n != NULL){
        get_height_balance(n->left);
        std::cout << "data: " << n->data << ", height: " << n->height << ", balance: " << get_balance_factor(n) << '\n';
        if(get_balance_factor(n) >= 2 | get_balance_factor(n) <= -2){
            std::string file_name = "error_report.txt";
            std::ofstream file_out;
            file_out.open(file_name, std::ios_base::app);
            file_out << n->data << ' ' << n->height << ' ' << get_balance_factor(n) << '\n';
            file_out.close();            
        }        
        get_height_balance(n->right);
    }
}

Node* insert_operation(Node* n, const int data){
    if(n == NULL) return get_new_node(data);
    else if(n->data > data) n->left = insert_operation(n->left, data);
    else if(n->data < data) n->right = insert_operation(n->right, data);
    else{ 
        // duplicated data is not allowed
    }
    // 높이 갱신
    n->height = adjust_height(n);
    n = adjust_balance_factor(n);
    return n;
}

Node* remove_operation(Node* n, const int data){
    if(n == NULL) return n;
    else if(n->data > data) n->left = remove_operation(n->left, data);
    else if(n->data < data) n->right = remove_operation(n->right, data);
    else{
        Node* ptr = n;
        if(n->left == NULL && n->right == NULL){
            delete n;
            n = NULL;
            count_removed_nodes++;
        } else if(n->left != NULL && n->right == NULL){
            n = n->left;
            delete ptr;
            count_removed_nodes++;
        } else if(n->right != NULL && n->left == NULL){
            n = n->right;
            delete ptr;
            count_removed_nodes++;
        } else{
            ptr = get_max_node(n->left);
            n->data = ptr->data;
            n->left = remove_operation(n->left, ptr->data);
        }
    } 
    if(n == NULL) return n;
    n->height = adjust_height(n);
    return adjust_balance_factor(n);
}

class AVL{
    private:
        Node* root;
    public:
        AVL(){
            root = NULL;
        }
        ~AVL(){
            release_memory(root);
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
            std::cout << "\n\n[data | height | balance factor]\n";
            get_height_balance(root);
        }
        // void show_height_balance() const{
        //     get_height_balance(root);
        // }
};

#endif // AVL_3_HPP