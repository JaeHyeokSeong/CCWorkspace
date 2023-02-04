#include "avl.hpp"

Avl::Avl(){
    root = NULL;
}
Avl::~Avl(){
    avl::postorder(root, nde::delete_node);
}
void Avl::insert(const int data){
    root = avl::insert_operation(root, data);
}
void Avl::remove(const int data){
    root = avl::remove_operation(root, data);
}
bool Avl::search(const int data){
    Node* ptr = root;
    while(ptr != NULL){
        if(ptr->data == data) return true;
        else if(ptr->data > data) ptr = ptr->left;
        else ptr = ptr->right;
    }
    return false;
}
void Avl::show_inorder() const{
    avl::inorder(root, avl::print_node_data);
    avl::print_new_line();
}
void Avl::show_height_balance_factor() const{
    avl::inorder(root, avl::print_node_data_height_balanceFactor);
    avl::print_new_line();
}

void avl::print_node_data(const Node* node){
    std::cout << node->data << ' ';
}
void avl::print_node_data_height_balanceFactor(const Node* node){
    std::cout << "data: " << node->data << ", height: " << get_height(node) << ", balance factor: " << get_balance_factor(node) << '\n';
}
void avl::print_new_line(){
    std::cout << '\n';
}
Node* avl::get_max_node(Node* node){
    if(node == NULL) return node;
    Node* ptr = node;
    while(ptr->right != NULL){
        ptr = ptr->right;
    }
    return ptr;
}
void avl::inorder(const Node *node, void (*ptr_f)(const Node*)){
    if(node != NULL){
        inorder(node->left, ptr_f);
        ptr_f(node);
        inorder(node->right, ptr_f);
    }
}
void avl::postorder(const Node* node, void (*ptr_f)(const Node*)){
    if(node != NULL) {
        postorder(node->left, ptr_f);
        postorder(node->right, ptr_f);
        ptr_f(node);
    }
}
int avl::get_height(const Node* node){
    if(node == NULL) return 0;
    return node->height;
}
void avl::adjust_height(Node** node){
    (*node)->height = std::max(get_height((*node)->left), get_height((*node)->right)) + 1;
}
int avl::get_balance_factor(const Node* node){
    return get_height(node->left) - get_height(node->right);
}
Node* avl::LL(Node* node){
    Node* child_node = node->left;
    node->left = child_node->right;
    child_node->right = node;
    // update node and child_node height
    adjust_height(&node);
    adjust_height(&child_node);
    return child_node;
}
Node* avl::RR(Node* node){
    Node* child_node = node->right;
    node->right = child_node->left;
    child_node->left = node;
    // update node and child_node height
    adjust_height(&node);
    adjust_height(&child_node);
    return child_node;
}
Node* avl::LR(Node* node){
    node->left = RR(node->left);
    return LL(node);
}
Node* avl::RL(Node* node){
    node->right = LL(node->right);
    return RR(node);
}
Node* avl::adjust_balance_factor(Node* node){
    int balance_factor = get_balance_factor(node);
    // LL or LR
    if(balance_factor >= 2){
        balance_factor = get_balance_factor(node->left);
        if(balance_factor >= 0) node = LL(node);
        else node = LR(node);
    } 
    // RR or RL
    else if(balance_factor <= -2){
        balance_factor = get_balance_factor(node->right);
        if(balance_factor <= 0) node = RR(node);
        else node = RL(node);
    }
    return node;
}
Node* avl::insert_operation(Node* node, const int data){
    if(node == NULL) return nde::new_node(data);
    else if(node->data > data) node->left = insert_operation(node->left, data);
    else if(node->data < data) node->right = insert_operation(node->right, data);
    else{
        // 중복값은 허용되어지지 않는다
    }
    // 새로운 노드가 삽입되어진 다음에는 노드의 높이를 다시 계산해주고 
    // 균형도가 절대값 2이상인지 확인을 해준다.
    adjust_height(&node);
    node = adjust_balance_factor(node);
    return node;
}
Node* avl::remove_operation(Node* node, const int data){
    if(node == NULL) return node;
    else if(node->data > data) node->left = remove_operation(node->left, data);
    else if(node->data < data) node->right = remove_operation(node->right, data);
    else{
        Node* ptr = node;
        // 값을 찾은 경우 4가지 상황들을 고려해야 한다.
        // 자식이 왼쪽, 오른쪽 둘다 없는 경우
        if(node->left == NULL && node->right == NULL){
            nde::delete_node(node);
            node = NULL;
        }
        // 왼쪽 자식은 있고 오른쪽 자식은 없는 경우
        else if(node->left != NULL && node->right == NULL){
            node = node->left;
            nde::delete_node(ptr);
        }
        // 오른쪽 자식은 있고 왼쪽 자식은 없는 경우
        else if(node->right != NULL && node->left == NULL){
            node = node->right;
            nde::delete_node(ptr);
        }
        // 왼쪽 오른쪽 둘다 자식이 있는 경우
        else{
            // 삭제 할려는 노드의 왼쪽 sub-tree에서 가장 큰 값을 가지고 있는 노드를 찾는다
            ptr = get_max_node(node->left);
            node->data = ptr->data;
            node->left = remove_operation(node->left, ptr->data);
        }
    }

    // node가 NULL이 아니면 높이 그리고 균형도를 재조정 해야한다
    if(node != NULL){
        adjust_height(&node);
        node = adjust_balance_factor(node);
    }
    return node;
}