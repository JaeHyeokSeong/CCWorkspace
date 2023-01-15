/*
2023/JAN/15

자료형 구조 : double linked list

Dll class
- 구현할 함수들 : add_node_front(), add_node_back(), get_node_at(), remove_node_at(),
insert_node_at_after(), display_nodes()

*/
#ifndef DLL_1_HPP
#define DLL_1_HPP
#include <iostream>

typedef struct Node{
    int data;
    Node* previous_node;
    Node* next_node;
}Node;

Node* create_new_node(const int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->previous_node = NULL;
    new_node->next_node = NULL;
    return new_node;
}

class Dll{
    private:
        Node* head;
        Node* tail;
        int count;
    public:
        Dll(){
            head = NULL;
            tail = NULL;
            count = 0;
        }
        ~Dll(){
            while(head != NULL){
                Node* tmp_node = head;
                head = head->next_node;
                delete tmp_node;
            }
        }
        // data 가 들어오면 node 를 생성한 후 기존에 존재하던 노드들 앞에 붙인다.
        void add_node_front(const int data){
            Node* new_node = create_new_node(data);
            // 기존에 node 가 없던 경우
            if(head == NULL && tail == NULL){
                head = new_node;
                tail = new_node;
            }
            // 기존에 node 가 있던 경우
            else{
                new_node->next_node = head;
                head->previous_node = new_node;
                head = new_node;
            }
            // count 1 증가
            count++;
        }
        // data 가 들어오면 node 를 생성한 후 기존에 존재하던 노드들 뒤에 붙인다.
        void add_node_back(const int data){
            Node* new_node = create_new_node(data);
            // 기존에 노드들이 없던 경우
            if(head == NULL && tail == NULL){
                head = new_node;
                tail = new_node;
            }
            // 기존에 노드들이 있던 경우
            else{
                tail->next_node = new_node;
                new_node->previous_node = tail;
                tail = new_node;
            }
            // count 1 증가
            count++;
        }
        // 범위 안의 index 를 입력하면, 그 index 에 해당하는 노드의 메모리 주소를 리턴.
        Node* get_node_at(const int index){
            // 유호 index 를 벗어나는 경우
            if(index < 0 || index >= count) return NULL;
            Node* target_node;
            Node* search_node = head;
            for(int i = 0; i <= index; i++){
                target_node = search_node;
                search_node = search_node->next_node;
            }
            return target_node;
        }
        // 삭제하고 싶은 node 의 index 를 입력한 후 노드가 성공적으로 삭제되면 1, 실패하면 0 을 리턴.
        int remove_node_at(const int index){
            Node* target_node = get_node_at(index);
            // node 삭제 실패한 경우 (index 유호 범위 때문)
            if(target_node == NULL) return 0;

            if(target_node->previous_node == NULL && target_node->next_node == NULL){
                head = NULL;
                tail = NULL;
            }else if(target_node->previous_node == NULL && target_node->next_node != NULL){
                head = target_node->next_node;
                head->previous_node = NULL;
            } else if(target_node->previous_node != NULL && target_node->next_node == NULL){
                tail = target_node->previous_node;
                tail->next_node = NULL;
            } else{
                target_node->previous_node->next_node = target_node->next_node;
                target_node->next_node->previous_node = target_node->previous_node;
            }
            delete target_node;
            count--;
            return 1;
        }
        // index 값이 들어오면 그에 해당하는 index 앞에 새로운 노드를 삽입한다. 성공 1 실패 0
        int insert_node_at_after(const int index, const int data){
            Node* target_node = get_node_at(index);
            // node 삽입에 실패한 경우 (index 유호 범위 때문)
            if(target_node == NULL) return 0;
            // 새로운 node 생성
            Node* new_node = create_new_node(data);
            // target_node 가 head 인 경우
            if(target_node->previous_node == NULL && target_node->next_node == NULL){
                target_node->next_node = new_node;
                new_node->previous_node = target_node;
                tail = new_node;
            }
            //  target_node 가 tail 인 경우
            else if(target_node->previous_node != NULL && target_node->next_node == NULL){
                target_node->next_node = new_node;
                new_node->previous_node = target_node;
                tail = new_node;                
            }  
            // target_node 가 두 노드들 사이인 경우
            else{
                new_node->next_node = target_node->next_node;
                target_node->next_node->previous_node = new_node;
                new_node->previous_node = target_node;
                target_node->next_node = new_node;
            }
            // count 1 증가
            count++;
            return 1;
        }
        // double linked list 에 존재하는 모든 nodes 출력
        void display_nodes() const{
            Node* tmp_node = head;
            while(tmp_node != NULL){
                std::cout << tmp_node->data;
                tmp_node = tmp_node->next_node;
                if(tmp_node != NULL) std::cout << " -> ";
            }
            std::cout << '\n';
        }
};
#endif // DLL-1_HPP