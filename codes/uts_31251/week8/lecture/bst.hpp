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
        std::pair<Node*, Node*> search(int key){
            Node* current_node = root;
            Node* privous_node = NULL;
            while(current_node != NULL){
                if(current_node->key == key)
                    break;
                else if(current_node->key < key){
                    privous_node = current_node;
                    current_node = current_node->right_node;
                }
                else if(current_node->key > key){
                    privous_node = current_node;
                    current_node = current_node->left_node;
                }
            }
            // first - parent node address
            // second - child node address
            // if current_node is NULL, then the key is not found
            return std::make_pair(privous_node, current_node);
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
        void remove(int key){
            // 먼저 값이 존재 하는지 search 함수를 통해서 찾아본다
            // first - parent node address
            // second - key 값이 발견되어진 노드의 주소
            // 만약 second 노드가 NULL 이면 key 값이 발견안된 의미
            // std::pair<Node*, Node*> node = search(key);
            // if(node.second == NULL){
            //     printf("remove fail => key [%d] is not exist\n", key);
            //     return;
            // }
            // // 1 삭제할 노드가 leaf node 인 경우 (그냥 삭제하면 된다)
            // if(node.second->left_node == NULL && node.second->right_node == NULL){
            //     // 원소가 한개만 있는 경우 (root 노드 1개만 있는 경우)
            //     if(node.first == NULL){
            //         delete node.second;
            //         return;
            //     } else {
            //         // 삭제 되는 것이 부모노드에서 왼쪽인지 오른쪽인지 알아야함
            //         // 왼쪽 노드를 삭제하는 경우
            //         if(node.first->key > key)
            //             node.first->left_node = NULL;
            //         else if(node.first->key < key)
            //             node.first->right_node = NULL;
            //         delete node.second;
            //     }
            // }
            
            // 3 삭제할 노드에 자식이 둘 있는 경우
            // if(node.second->left_node != NULL && node.second->right_node != NULL){
            //     // Node* successor_node = find_min_value(node.second->right_node);
            //     // int tmp_key = node.second->key;
            //     // node.second->key = successor_node->key;
            //     // successor_node->key = tmp_key;

            //     // Node* tmp_node = search() 
            // }

            // 2 삭제할 노드에 자식이 하나만 있는 경우)
            // if(node.second->left_node != NULL || node.second->right_node != NULL){
            //     // 삭제할 노드의 자식 노드를 잠시 보관해둔다
            //     Node* tmp_node = node.second->left_node;
            //     if(node.second->left_node == NULL)
            //         tmp_node = node.second->right_node;

            //     if(node.first->key > key){
            //         node.first->left_node = tmp_node;
            //     } else{
            //         node.first->right_node = tmp_node;
            //     }
            //     delete node.second;
            // }
        }
        void display(){
            inorder_traversal(root);
        }
};
#endif // BST_HPP