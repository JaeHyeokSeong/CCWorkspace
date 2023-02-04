#ifndef AVL_HPP
#define AVL_HPP
#include "node.hpp"

class Avl{
    private:
        Node *root;
    public:
        Avl();
        // node들의 주소들을 heap memory 로 부터 delete 해준다.
        ~Avl();
        void insert(const int data);
        void remove(const int data);
        bool search(const int data);
        void show_inorder() const;
        void show_height_balance_factor() const;
};

namespace avl{
    // 노드의 값을 출력 해준다.
    void print_node_data(const Node* node);
    // 노드의 값, 높이, 균형도를 출력한다.
    void print_node_data_height_balanceFactor(const Node* node);
    // 새로운 줄을 출력한다.
    void print_new_line();
    // node 주소를 입력하면, 그 노드 주소에서 시작하여 가장 큰 값을 가지고 있는 노드의 주소를 반환한다.
    Node* get_max_node(Node* node);
    void inorder(const Node *node, void (*ptr_f)(const Node*));
    void postorder(const Node *node, void (*ptr_f)(const Node*));
    int get_height(const Node* node);
    // node 주소의 주소를 보내주면 현재 상태에 따라서 높이를 조정해준다. 이때 NULL 값의 주소를 보내면 안된다.
    void adjust_height(Node** node);
    int get_balance_factor(const Node* node);
    Node* LL(Node* node);
    Node* RR(Node* node);
    Node* LR(Node* node);
    Node* RL(Node* node);
    // node 를 입력하면 균형도를 계산하여서 적절한 회전을 수행한다.
    Node* adjust_balance_factor(Node* node); 
    /* 
    삽입이 시작되어질 노드의 주소를 입력하고, 삽입되어질 노드의 값 또한 입력을 해준다.
    만약 삽입 도중에 균형도가 절대값 2이상을 넘어서 회전이 발생하게 되면 그에 따른 적절한 
    부모 노드가 반환 되어진다.
    */ 
    Node* insert_operation(Node* node, const int data);
    /*
    삭제를 시작할 노드의 주소를 입력하고 그리고 삭제하고 싶은 데이터를 입력한다.
    삭제가 시행되어진 후 알맞은 부모노드가 반환되어진다.
    */
    Node* remove_operation(Node* node, const int data);
}

#endif // AVL_HPP
