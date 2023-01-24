#ifndef DLL_2_HPP
#define DLL_2_HPP

/* 
실행일 : 2023/01/25
자료형 구조 : doubly linked list
구현 할 함수들 :
    push_front(int data) - finished
    push_back(int data) - finished
    get_node_at(int index) - finished
    insert_node_at(int index, int data) - finished
    remove_node_at(int index) - continue
    begin() - finished
    end() - finished
    display() - finished
*/
#include <iostream>

template <class T>
class Node{
    public:
        T data;
        Node* privous_node;
        Node* next_node;
        Node(T data){
            this->data = data;
            privous_node = NULL;
            next_node = NULL;
        }
};

template <class T>
class MyIterator{
    private:
        Node<T>* current_node;
    public:
        MyIterator(Node<T>* current_node = NULL){
            this->current_node = current_node;
        }
        T& operator *() const{
            return current_node->data;
        }
        MyIterator& operator ++(){
            current_node = current_node->next_node;
            return *this;
        }
        MyIterator& operator ++(int){
            current_node = current_node->next_node;
            return *this;
        }
        bool operator ==(const MyIterator& ref) const{
            return current_node == ref.current_node;
        }
        bool operator !=(const MyIterator& ref) const{
            return current_node != ref.current_node;
        }
};

template <class T>
class Doubly_linked_list{
    private:
        Node<T>* head;
        Node<T>* tail;
        // 현재 element의 수
        int count;
        // 새로운 노드를 만든 후 리턴
        Node<T>* get_new_node(const T data){
            return new Node<T>(data);
        }
    public:
        Doubly_linked_list(){
            head = NULL;
            tail = NULL;
            count = 0;
        }
        ~Doubly_linked_list(){
            while(head != NULL){
                Node<T>* tmp = head;
                head = head->next_node;
                delete tmp;
            }
        }
        void push_front(const T data){
            Node<T>* new_node = get_new_node(data);
            // 노드가 없는 경우
            if(head == NULL && tail == NULL){
                head = new_node;
                tail = new_node;
            }
            // 노드가 이미 있었던 경우
            else{
                new_node->next_node = head;
                head->privous_node = new_node;
                head = new_node;
            }
            count++;
        }
        void push_back(const T data){
            Node<T>* new_node = get_new_node(data);
            // 노드가 없는 경우
            if(head == NULL && tail == NULL){
                head = new_node;
                tail = new_node;
            }
            // 노드가 이미 있었던 경우
            else{
                tail->next_node = new_node;
                new_node->privous_node = tail;
                tail = new_node;
            }
            count++;
        }
        Node<T>* get_node_at(const int index) const{
            if(index < 0 || index >= count) return NULL;
            Node<T>* node_at = NULL;
            Node<T>* tmp_node = head;
            for(int i = 0; i <= index; i++){
                node_at = tmp_node;
                tmp_node = tmp_node->next_node;
            }
            return node_at;
        }
        // 입력된 index 뒤에 새로운 노드가 insert
        void insert_node_at(const int index, const T data){
            Node<T>* node_at = get_node_at(index);
            if(node_at == NULL) return;
            Node<T>* new_node = get_new_node(data);
            // 3가지 경우가 있음
            // head 노드만 있을 경우 head 뒤에 insert 하는 경우 
            if(node_at->privous_node == NULL && node_at->next_node == NULL){
                node_at->next_node = new_node;
                new_node->privous_node = head;
                tail = new_node;
            }
            // tail 뒤에 insert 경우
            else if(node_at->privous_node != NULL && node_at->next_node == NULL){
                node_at->next_node = new_node;
                new_node->privous_node = tail;
                tail = new_node;
            } 
            // 두 노드들 사이에 insert 경우
            else{
                new_node->privous_node = node_at;
                new_node->next_node = node_at->next_node;
                node_at->next_node = new_node;
                new_node->next_node->privous_node = new_node;
            }
        }
        void remove_node_at(const int index){
            Node<T>* node_at = get_node_at(index);
            if(node_at == NULL) return;
            // node_at이 head인 경우
            if(node_at->privous_node == NULL && node_at->next_node == NULL){
                head = NULL;
                tail = NULL;
            } else if(node_at->privous_node == NULL && node_at->next_node != NULL){
                head = node_at->next_node;
                head->privous_node = NULL;
            } else if(node_at->privous_node != NULL && node_at->next_node == NULL){
                tail = node_at->privous_node;
                tail->next_node = NULL;
            } else{
                node_at->privous_node->next_node = node_at->next_node;
                node_at->next_node->privous_node = node_at->privous_node;
            }
            delete node_at;
            count--;
        }
        typedef MyIterator<T> iterator;
        iterator begin(){
            return iterator(head);
        }
        iterator end(){
            return iterator(NULL);
        }
        void display() const{
            Node<T>* tmp = head;
            while(tmp != NULL){
                std::cout << tmp->data << ' ';
                tmp = tmp->next_node;
            }
            std::cout << '\n';
        }
};

#endif // DLL_2_HPP