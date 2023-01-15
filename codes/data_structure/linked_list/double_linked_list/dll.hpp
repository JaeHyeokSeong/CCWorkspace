#ifndef DLL_HPP
#define DLL_HPP
#include <iostream>

typedef struct Node{
    int data;
    Node* privous_node;
    Node* next_node;
}Node;

Node* create_new_node(const int data){
    // new node 생성
    Node* new_node = new Node;
    // new node 초기화
    new_node->data = data;
    new_node->privous_node = NULL;
    new_node->next_node = NULL;
    // 초기화 되어진 new node return
    return new_node;
}

class Dll{
    private:
        // double linked list 에서의 시작 노드를 알려주는 head
        Node* head;
        // double linked list 에서의 마지막 노드를 알려주는 tail
        Node* tail;
        // double linked list 에서의 총 노드의 수
        int count;
    public:
        Dll(){
            // Dll class 의 지역 변수들 초기화 
            head = NULL;
            tail = NULL;
            count = 0;
        }
        // ~Dll 에서 메모리에 할당된 노드들 delete 해주기
        ~Dll(){
            // head 변수가 NULL 이 아니면 메모리가 할당 되어진 것
            while(head != NULL){
                Node* tmp_node = head;
                head = head->next_node;
                delete tmp_node;
            }
        }
        // 원하는 index 를 입력하면 그 자리에 해당하는 Node의 주소를 리턴
        Node* get_node_at(const int index){
            /*
            ex) index 2 의 노드의 위치를 가져올려면 먼저 count 변수의 값이
            3 이상이여지만 한다. 만약 3보다 작은 값이라면 index 2 의 값은 없는 것이다
            */
            if(index >= count || index < 0) return NULL;
            Node* target_node;
            Node* search_node = head;
            for(int i = 0; i <= index; i++){
                target_node = search_node;
                search_node = search_node->next_node;
            }
            return target_node;
        }
        // double linked list 의 노드의 총 수를 가져오는 함수
        int get_count() const{
            return count;
        }
        // double linked list 에서 가장 앞에 노드를 추가하는 함수
        void add_node_front(const int data){
            Node* created_node = create_new_node(data);
            // 메모리에 노드할당을 성공한 경우
            // 아직 원소가 없는 경우, 즉 count 변수가 0을 가질때에는 원소를 만든후 head 와 tail을
            // 업데이트 해줘야한다.
            if(count == 0) tail = head = created_node;
            // 이미 원소가 있던 경우에는 head 변수만 업데이트 해준다
            else{
                head->privous_node = created_node;
                created_node->next_node = head;
                head = created_node;
            }
            // count 변수 1 증가
            count++;
        }
        // double linked list 에서 가장 뒤에 노드를 추가하는 함수
        void add_node_back(const int data){
            Node* created_node = create_new_node(data);
            // 메모리에 노드할당을 성공한 경우
            // 아직 원소가 없는 경우, 즉 count 변수가 0을 가질때에는 원소를 만든후 head 와 tail을
            // 업데이트 해줘야한다.
            if(count == 0) tail = head = created_node;
            // 이미 원소가 있던 경우에는 tail 변수만 업데이트 해준다
            else{
                tail->next_node = created_node;
                created_node->privous_node = tail;
                tail = created_node;
            }
            // count 변수 1 증가
            count++;
        }
        // index 앞에 새로운 노드를 추가해준다
        void insert_node_at_after(const int data, const int index){
            Node* current_node = get_node_at(index);
            if(current_node == NULL) return;

            Node* created_node = create_new_node(data);
            // index 가 head 인 경우
            if(current_node->privous_node == NULL && current_node->next_node == NULL){
                current_node->next_node = created_node;
                created_node->privous_node = current_node;
                tail = created_node;
            }
            // index 가 tail 인 경우
            else if(current_node->privous_node != NULL && current_node->next_node == NULL){
                current_node->next_node = created_node;
                created_node->privous_node = current_node;
                tail = created_node;
            }
            // 두 노드 사이에 새로운 노드를 추가하는 경우
            else{
                Node* tmp = current_node->next_node;
                current_node->next_node = created_node;
                created_node->privous_node = current_node;
                created_node->next_node = tmp;
                tmp->privous_node = created_node;
            }
            // count 1 증가
            count++;
        }
        // node 를 삭제해주는 함수
        void remove_node_at(const int index){
            Node* remove_node = get_node_at(index);
            if(remove_node == NULL) return;

            // 원소가 하나인 경우, head == remove_node && tail == remove_node
            if(head == remove_node && tail == remove_node){
                head = NULL;
                tail = NULL;
            }
            // head 를 삭제하는 경우
            else if(head == remove_node){
                head = remove_node->next_node;
                head->privous_node = NULL;
            }
            // tail 를 삭제하는 경우
            else if(tail == remove_node){
                tail = tail->privous_node;
                tail->next_node = NULL;
            }
            // 노드들 중간에 있는 노드를 삭제하는 경우
            else{
                remove_node->privous_node->next_node = remove_node->next_node;
                remove_node->next_node->privous_node = remove_node->privous_node;
            }
            delete remove_node;
            count--;
        }
        // double linked list 에 있는 모든 노드들을 보여준다
        void display(){
            Node* tmp = head;
            while(tmp != NULL){
                std::cout << tmp->data;
                tmp = tmp->next_node;
                if(tmp != NULL) std::cout << " -> ";
            }
            std::cout << '\n';
        }
};
#endif // DLL_HPP