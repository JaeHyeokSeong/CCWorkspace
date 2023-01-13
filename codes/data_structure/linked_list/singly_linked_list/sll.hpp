#ifndef SLL_HPP
#define SLL_HPP
#include <iostream>

typedef struct Node{
    int data;
    Node* next_node;
}Node;

class SLL{
    private:
        Node* head;
    public:
        SLL(){
            head = NULL;
        }
        ~SLL(){
            //  메모리 할당 해제
            while(head != NULL){
                Node* tmp = head;
                head = head->next_node;
                delete tmp;
            }
        }
        void insert_front(int data){
            Node* new_node = new Node;
            new_node->data = data;
            new_node->next_node = NULL;
            
            // 아직 원소가 없는 경우 새로운 노드를 헤드로 해준다
            if(head == NULL)
                head = new_node;
            // 원소가 이미 있는 경우 새로운 노드의 next_node 를
            // head 주소로 가르키고, head의 주소를 새롭게 만든 노드로
            // 업데이트 해준다
            else{
                new_node->next_node = head;
                head = new_node;
            }
        }
        void remove(int data){
            if(head == NULL){
                std::cout << "삭제할 값이 없습니다.\n";
                return;
            }

            Node* current_node = head;
            Node* privous_node = NULL;

            while(current_node != NULL){
                // 값을 찾은 경우
                if(current_node->data == data){
                    // head 에서 값을 찾은 경우
                    if(privous_node == NULL)
                        head = current_node->next_node;
                    // head 가 아닌 다른 곳에서 찾은 경우
                    else
                        privous_node->next_node = current_node->next_node;
                    
                    std::cout << "값: " << data << "이 삭제 되었습니다.\n";
                    delete current_node;
                    return;
                } else{
                    privous_node = current_node;
                    current_node = current_node->next_node;
                }
            }
            std::cout << "값: " << data << "이 존재하지 않습니다.\n";
        }
        void display(){
            Node* current_node = head;
            while(current_node != NULL){
                std::cout << current_node->data << ' ';
                current_node = current_node->next_node;
            }
            std::cout << '\n';
        }
};


#endif // SLL_HPP