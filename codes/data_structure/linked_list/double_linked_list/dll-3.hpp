#ifndef DLL_3_HPP
#define DLL_3_HPP
#include <iostream>

template <typename T>
class Node{
    public:
        T data;
        Node<T>* prev;
        Node<T>* next;
};

template <typename T>
Node<T>* get_new_node(const T data, int* count){
    Node<T>* node = new Node<T>;
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    (*count)++;
    return node;
}

template <typename T>
void delete_node(Node<T>* node, int* count){
    delete node;
    (*count)--;
}

template <typename T>
Node<T>* get_node_at(Node<T>* node, const int index, const int count){
    Node<T>* founded_node = NULL;
    if(0 <= index && index < count){
        Node<T>* ptr = node;
        for(int i = 0; i < index; i++){
            ptr = ptr->next;
        }
        founded_node = ptr;
    }
    return founded_node;
}

template <typename T>
void realse_memory(Node<T>* node){
    while(node != NULL){
        Node<T>* ptr = node;
        node = node->next;
        delete ptr;
    }
}

template <typename T>
class DLL{
    private:
        Node<T>* head;
        Node<T>* tail;
        int count;
    public:
        DLL(){
            head = NULL;
            tail = NULL;
            count = 0;
        }
        ~DLL(){
            realse_memory<T>(head);
        }
        Node<T>* get_head() const{
            return head;
        }
        int get_count() const{
            return count;
        }
        void push_front(const T data){
            Node<T>* node = get_new_node<T>(data, &count);
            if(head == NULL && tail == NULL){
                head = node;
                tail = node;
            } else{
                node->next = head;
                head->prev = node;
                head = node;
            }
        }
        void push_back(const T data){
            Node<T>* node = get_new_node<T>(data, &count);
            if(head == NULL && tail == NULL){
                head = node;
                tail = node;
            } else{
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        // index 뒤에 노드가 추가됨
        void insert_node_at_after(const int index, const T data){
            Node<T>* node = get_node_at(head, index, count);
            if(node != NULL){
                Node<T>* new_node = get_new_node(data, &count);
                // 하나의 노드만 있는 경우
                if(node->prev == NULL && node->next == NULL){
                    node->next = new_node;
                    new_node->prev = node;
                    tail = new_node;
                } else if(node->prev != NULL && node->next == NULL){
                    node->next = new_node;
                    new_node->prev = node;
                    tail = new_node;
                } else{
                    new_node->prev = node;
                    new_node->next = node->next;
                    node->next->prev = new_node;
                    node->next = new_node;
                }
            }
        }
        void remove_node_at(const int index){
            Node<T>* node = get_node_at<T>(head, index, count);
            if(node != NULL){
                if(node->prev == NULL && node->next == NULL){
                    delete_node(node, &count);
                    head = NULL;
                    tail = NULL;
                } else if(node->prev == NULL && node->next != NULL){
                    head = node->next;
                    head->prev = NULL;
                    delete_node(node, &count);
                } else if(node->next == NULL && node->prev != NULL){
                    tail = node->prev;
                    tail->next = NULL;
                    delete_node(node, &count);
                } else{
                    node->prev->next = node->next;
                    node->next->prev = node->prev;
                    delete_node(node, &count);
                }
            }
        }
        void display() const{
            Node<T>* ptr = head;
            while(ptr != NULL){
                std::cout << ptr->data;
                ptr = ptr->next;
                if(ptr != NULL) std::cout << " -> ";
            }
            std::cout << '\n';
        }
};  

#endif // DLL_3_HPP