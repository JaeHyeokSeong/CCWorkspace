#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>

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

int get_height(const Node* node){
    if(node == NULL) return -1;
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    return std::max(left_height, right_height) + 1;
}

int get_balance_factor(const Node* node){
    return get_height(node->left) - get_height(node->right);
}

void release_memory(Node* node){
    if(node != NULL){
        release_memory(node->left);
        release_memory(node->right);
        delete node;
    }
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
    int child_balance_factor = 0, balance_factor = get_balance_factor(node);
    if(balance_factor >= 2){
        child_balance_factor = get_balance_factor(node->left);
        if(child_balance_factor >= 1) node = LL(node);
        else node = LR(node);
    } else if(balance_factor <= -2){
        child_balance_factor = get_balance_factor(node->right);
        if(child_balance_factor <= -1) node = RR(node);
        else node = RL(node);
    }
    return node;
}

Node* get_max_node(Node* node){
    if(node == NULL) return NULL;
    while(node->right != NULL){
        node = node->right;
    }
    return node;
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
            ptr = get_max_node(node->left);
            node->data = ptr->data;
            node->left = remove_operation(node->left, ptr->data);
        }
    }
    return node;
}

void inorder_traversal(const Node* node){
    if(node != NULL){
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
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
        Node* get_root() const{
            return root;
        }
        void insert(const int data){
            Node* node = get_new_node(data);
            if(root == NULL) root = node;
            else{
                Node* ptr = root;
                Node* p_ptr = NULL;
                while(ptr != NULL){
                    p_ptr = ptr;
                    if(ptr->data > data) ptr = ptr->left;
                    else if(ptr->data < data) ptr = ptr->right;
                    else return; // 중복 값 허용 안됨
                }
                if(p_ptr->data > data) p_ptr->left = node;
                else p_ptr->right = node;
                // 균형도를 측정한다
                root = adjust_balance(root);
            }
        }
        void remove(const int data){
            root = remove_operation(root, data);
            root = adjust_balance(root);
        }
        bool search(const int data){
            Node* ptr = root;
            while(ptr != NULL){
                if(ptr->data == data) return true;
                if(ptr->data > data) ptr = ptr->left;
                else ptr = ptr->right;
            }
            return false;
        }
        void show(){
            inorder_traversal(root);
            printf("\n");
        }
};

// // test purpose
// void check_nodes_height_balance_factor(Node* node){
//     if(node != NULL){
//         check_nodes_height_balance_factor(node->left);
//         printf("data: %d, height: %d, balance factor: %d\n", node->data, get_height(node), get_balance_factor(node));
//         check_nodes_height_balance_factor(node->right);
//     }
// }

// // test purpose
// void test(){
//     AVL avl;
//     avl.insert(50);
//     avl.insert(17);
//     avl.insert(76);
//     avl.insert(9);
//     avl.insert(23);
//     avl.insert(14);
//     avl.insert(19);
//     avl.insert(12);
//     avl.insert(54);
//     avl.insert(72);
//     avl.insert(67);

//     printf("test data, height, balance factor for all nodes\n\n");
//     check_nodes_height_balance_factor(avl.get_root());

//     printf("inorder traversal\n");
//     avl.show();

//     // avl.remove(8);
//     // avl.remove(7);

//     // printf("\nafter removing\n");
//     // printf("test data, height, balance factor for all nodes\n\n");
//     // check_nodes_height_balance_factor(avl.get_root());

//     // printf("inorder traversal\n");
//     // avl.show();
// }
#endif // AVL_HPP