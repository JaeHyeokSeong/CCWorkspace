#ifndef AVL_4_HPP
#define AVL_4_HPP
#include <iostream>

// node 구조체
typedef struct Node{
    int data, height;
    Node* left, *right;
}Node;

// 새로운 노드를 heap memory에서 생산한 후, 메모리 주소를 리턴한다
Node* get_new_node(const int data){
    Node* n = new Node;
    n->data = data;
    n->height = 1;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// 입력된 노드의 주소를 메모리상에서 delete 해준다
void delete_node(Node* n){
    delete n;
}

// 입력된 노드에서 출발하여 가장 큰 값을 가진 노드를 찾은 후 그 노드의 주소를 리턴한다
Node* get_max_node(Node* n){
    if(n == NULL) return n;
    while(n->right != NULL){
        n = n->right;
    }
    return n;
}

// 노드가 입력되면 그 노드의 높이를 반환
int get_height(const Node* n){
    if(n == NULL) return 0;
    return n->height;
}

// 노드가 입력되면 노드의 높이를 재조정 한 값을 리턴 한다 (주의: NULL 값이 들어와서는 안된다)
int adjust_height(const Node* n){
    return std::max(get_height(n->left), get_height(n->right)) + 1;
}

// 노드의 균형도를 계산한 후 리턴한다 (주의: NULL 값이 들어와서는 안된다)
int get_balance_factor(const Node* n){
    return get_height(n->left) - get_height(n->right);
}

// LL 기준
Node* LL(Node* n){
    Node* c_n = n->left;
    n->left = c_n->right;
    c_n->right = n;
    n->height = adjust_height(n);
    c_n->height = adjust_height(c_n);
    return c_n;
}

// RR 기준
Node* RR(Node* n){
    Node* c_n = n->right;
    n->right = c_n->left;
    c_n->left = n;
    n->height = adjust_height(n);
    c_n->height = adjust_height(c_n);
    return c_n;
}

// LR 기준
Node* LR(Node* n){
    n->left = RR(n->left);
    return LL(n);
}

// RL 기준
Node* RL(Node* n){
    n->right = LL(n->right);
    return RR(n);
}

// 노드의 균형도를 재조정한 후, 그에 상응하는 노드를 리턴한다
Node* adjust_balance_factor(Node* n){
    if(n == NULL) return n;
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

void inorder_traversal(Node* n, void (*func)(Node*)){
    if(n != NULL){
        inorder_traversal(n->left, func);
        func(n);
        inorder_traversal(n->right, func);
    }
}

void postorder_traversal(Node* n, void (*func)(Node*)){
    if(n != NULL){
        postorder_traversal(n->left, func);
        postorder_traversal(n->right, func);
        func(n);
    }
}

// 입력된 노드의 메모리 주소에서 data 값을 출력한다
void print_node_data(Node* n){
    std::cout << n->data << ' ';
}

// 입력된 노드의 data, height, balance factor을 출력한다
void print_node_info(Node* n){
    std::cout << "data: " << n->data << ", height: " << n->height << ", balance factor: " << get_balance_factor(n) << '\n';
}

// 그 다음 줄로 내려간다
void print_new_line(){
    std::cout << '\n';
}

Node* insert_operation(Node* n, const int data){
    if(n == NULL) return get_new_node(data);
    
    if(n->data > data) n->left = insert_operation(n->left, data);
    else if(n->data < data) n->right = insert_operation(n->right, data);
    else {
        // 중복 허용 안됨
    }
    n->height = adjust_height(n);
    n = adjust_balance_factor(n);
    return n;
}

Node* remove_operation(Node* n, const int data){
    if(n == NULL) return n;

    if(n->data > data) n->left = remove_operation(n->left, data);
    else if(n->data < data) n->right = remove_operation(n->right, data);
    else{
        Node* ptr = n;
        if(n->left == NULL && n->right == NULL){
            delete_node(n);
            n = NULL;
        } else if(n->left != NULL && n->right == NULL){
            n = n->left;
            delete_node(ptr);
        } else if(n->right != NULL && n->left == NULL){
            n = n->right;
            delete_node(ptr);
        } else{
            ptr = get_max_node(n->left);
            n->data = ptr->data;
            n->left = remove_operation(n->left, ptr->data);
        }
    }
    if(n != NULL){
        n->height = adjust_height(n);
        n = adjust_balance_factor(n);
    }
    return n;
}

class AVL{
    private:
        Node* root;
    public:
        AVL(){
            root = NULL;
        }
        ~AVL(){
            postorder_traversal(root, delete_node);
        }
        void insert(const int data){
            root = insert_operation(root, data);
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
        void show_inorder() const{
            inorder_traversal(root, print_node_data);
            print_new_line();
        }
        void show_postorder() const{
            postorder_traversal(root, print_node_data);
            print_new_line();
        }
        void show_height_balance_factor(){
            inorder_traversal(root, print_node_info);
            print_new_line();
        }
};

#endif // AVL_4_HPP