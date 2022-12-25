/*
참고자료: https://cafe.naver.com/honeyc/46342
*/
#ifndef BST_HPP
#define BST_HPP
#include <iostream>

typedef struct Node{
    int key;
    Node* left_node;
    Node* right_node;
}Node;

Node* get_new_node(int key){
    Node* new_node = new Node;
    new_node->key = key;
    new_node->left_node = NULL;
    new_node->right_node = NULL;
    return new_node;
}

class Bst{
    private:
        Node* root;
        void delete_memory_allocation(Node* node){
            if(node != NULL){
                delete_memory_allocation(node->left_node);
                Node* tmp_right_node = node->right_node;
                delete node;
                delete_memory_allocation(tmp_right_node);
            }
        }
        void inorder_traversal(Node* node){
            if(node != NULL){
                inorder_traversal(node->left_node);
                printf("%d ", node->key);
                inorder_traversal(node->right_node);
            }
            printf("\n");
        }
        Node* find_min_value(Node* node){
            if(node->left_node == NULL)
                return node;
            return find_min_value(node->left_node);
        }
    public:
        Bst(){
            root = NULL;
        }
        ~Bst(){
            delete_memory_allocation(root);
        }
        Node* get_root() const{
            return this->root;
        }
        Node* search(int key){
            Node* current_node = root;
            while(current_node != NULL){
                if(current_node->key == key)
                    return current_node;
                else if(current_node->key < key)
                    current_node = current_node->right_node;
                else if(current_node->key > key)
                    current_node = current_node->left_node;
            }
            return current_node;
        }
        void insert(int key){
            Node* new_node = get_new_node(key);
            // 아직 원소가 없는 경우
            if(root == NULL){
                root = new_node;
                return;
            }
            // 원소가 이미 있는 경우
            Node* tmp_current_node = root;
            Node* tmp_privous_node = NULL;

            while(tmp_current_node != NULL){
                if(tmp_current_node->key > new_node->key){
                    tmp_privous_node = tmp_current_node;
                    tmp_current_node = tmp_current_node->left_node;
                    if(tmp_current_node == NULL){
                        tmp_privous_node->left_node = new_node;
                    }
                }
                else if(tmp_current_node->key < new_node->key){
                    tmp_privous_node = tmp_current_node;
                    tmp_current_node = tmp_current_node->right_node;
                    if(tmp_current_node == NULL){
                        tmp_privous_node->right_node = new_node;
                    }
                }
            }
        }
        Node* remove(Node* node, int key){
            Node* tmp_node = NULL;
            // key 값이 들어오면 먼저 값이 존재하는지 부터 확인한다.
            // binary search tree 안이 empty가 아닌 경우
            if(node){
                if(node->key == key){
                    // [1] 삭제할 노드에 자식이 없는 경우
                    if(node->left_node == NULL && node->right_node == NULL){
                        // 원소가 하나만 있었는데 삭제하는 경우
                        if(root == node)
                            root = NULL;
                        delete node;
                        return NULL;
                    } else{
                        // [2] 자식이 하나인 경우
                        /* 원소가 2개만 있는 경우에서 root 값을 지우는 경우, 
                        자식 노드를 root 로 업데이트 시켜줘야 한다*/
                        // [2] - 1 오른쪽 자식만 있는 경우
                        if(node->left_node == NULL){
                            tmp_node = node->right_node;
                            if(node == root)
                                root = tmp_node;
                            delete node;
                            return tmp_node;
                        } 
                        // [2] - 2 왼쪽 자식만 있는 경우
                        if(node->right_node == NULL){
                            tmp_node = node->left_node;
                            if(node == root)
                                root = tmp_node;
                            delete node;
                            return tmp_node;
                        }

                        // 자식 노드가 두개인 경우
                        // 현재 노드의 오른쪽 노드들 중에서 가장 작은 값의 노드 주소를 가져온다
                        tmp_node = find_min_value(node->right_node);
                        // 오른쪽 노드들 중에서 가장 작은 값을 삭제할려는 노드 값에 대입
                        node->key = tmp_node->key; 
                        node->right_node = remove(node->right_node, tmp_node->key); 
                        }
                } else{
                    if(node->key > key){
                        node->left_node = remove(node->left_node, key);
                    } else{
                        node->right_node = remove(node->right_node, key);
                    }
                }
            }
            return node;
        }
        void display(){
            inorder_traversal(root);
        }
};
#endif // BST_HPP