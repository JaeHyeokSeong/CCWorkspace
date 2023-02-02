#ifndef Double_Linked_List_HPP
#define Double_Linked_List_HPP
#include <iostream>

// node structure
typedef struct Node{
    int data;
    Node *left, *right;
}Node;

// create a new node and return it
Node* create_new_node(const int data){
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// remove a node in heap memory
void remove_node_memory(const Node* node){
    delete node;
}

// double linked list class part
class Double_Linked_List{
    private:
        Node *head, *tail;
        int size;
    public:
        Double_Linked_List(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ~Double_Linked_List(){
            while(head != NULL){
                Node* ptr = head;
                head = head->right;
                remove_node_memory(ptr);
            }
        }

        void push_front(const int data){
            Node* node = create_new_node(data);
            // if empty
            if(head == NULL && tail == NULL){
                head = node;
                tail = node;
            }
            // if head value is already exist
            else if(head != NULL){
                node->right = head;
                head->left = node;
                // update head
                head = node;
            }
            // increase size
            size++;
        }

        void push_back(const int data){
            Node* node = create_new_node(data);
            // if empty
            if(head == NULL && tail == NULL){
                head = node;
                tail = node;
            }
            // if tail value is already exist
            else if(tail != NULL){
                tail->right = node;
                node->left = tail;
                tail = node;
            }
            // increase size
            size++;
        }

        // return a node memory address based on index (if index is invalid return NULL)
        Node* get_node_at(const int index){
            // invalid index value
            if(index < 0 || index >= size) return NULL;

            // valid index value
            Node* target_index_node = NULL, *ptr = head;
            for(int i = 0; i <= index; i++){
                target_index_node = ptr;
                ptr = ptr->right;
            }
            return target_index_node;
        }

        // remove a node at inputed index value
        void remove_at(const int index){
            Node* node = get_node_at(index);
            // invalid index outcome
            if(node == NULL) return;

            // valid index outcome
            // 4 cases
            if(node->left == NULL && node->right == NULL){
                remove_node_memory(node);
                head = NULL;
                tail = NULL;
            } else if(node->left == NULL && node->right != NULL){
                head = node->right;
                head->left = NULL;
                remove_node_memory(node);
            } else if(node->left != NULL && node->right == NULL){
                tail = node->left;
                tail->right = NULL;
                remove_node_memory(node);
            } else{
                node->left->right = node->right;
                node->right->left = node->left;
                remove_node_memory(node);
            }
            // update size
            size--;
        }

        // insert a new node after inputed index
        void insert_at_after(const int index, const int data){
            Node* node = get_node_at(index);
            
            // invalid inex 
            if(node == NULL) return;
            // valid index
            // create a new node
            Node* new_node = create_new_node(data);
            // 3 cases
            if(node->left == NULL && node->right == NULL){
                node->right = new_node;
                new_node->left = node;
                tail = new_node;
            } else if(node->left != NULL && node->right == NULL){
                node->right = new_node;
                new_node->left = node;
                tail = new_node;
            } else{
                new_node->right = node->right;
                new_node->left = node->right->left;
                node->right->left = new_node;
                node->right = new_node;
            }
            // update size
            size++;
        }

        // display all nodes
        void show() const{  
            Node* ptr = head;
            while(ptr != NULL){
                std::cout << ptr->data << ' ';
                ptr = ptr->right;
            }
            std::cout << '\n';
        }
};

#endif // Double_Linked_List_HPP