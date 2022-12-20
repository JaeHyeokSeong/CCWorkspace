/*
2022/12/20

목표: linked list를 사용해서 hash table 에서 나올 수 있는 인덱스 중복 문제인
collision을 chaining 기법을 사용해서 해결할려고 함.

정리: hash_function을 이용해서 입력 받아진 키 값을 이용해서 hash_table의 인덱스
값을 구한다. 그 값을 통해서 hash_table에서 어떠한 인덱스를 사용해야 하는지 알 수 있다.

참고자료: https://www.youtube.com/watch?v=IWpJsoX_UmU
*/
#include <iostream>

class Node{
    public:
        // key 값을 저장하는 변수
        int key;
        // value 값을 저장하는 변수
        int value;
        // 다음 노드의 주소를 저장하는 변수 
        Node* next;
        // constructor
        Node(int key = 0, int value = 0, Node* next = NULL){
            this->key = key; this->value = value; this->next = next;
        }
        ~Node(){}
};  
class Bucket{
    public:
        // bucket 안에서 맨 처음노드를 가르키는 head 변수
        Node* head;
        // bucket 안에서 노드의 수를 알려주는 count 변수
        int count;
        Bucket(Node* head = NULL, int count = 0){
            this->head = head; this->count = count;
        }
        ~Bucket(){
            // dynamic allocation 으로 할당한 Node의 메모리를 해제시켜 주는 작업
            while(head != NULL){
                Node* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
};

Bucket* hash_table = NULL;
// hash_table 안에 bucket 이 몇개 있는가를 결정하는 사이즈 변수
int SIZE = 10; 

// hash_table 에 있는 기본적인 함수들 
// create_node, hash_function, insert, remove, search, display

// create_node 구현
Node* create_node(const int key, const int value){
    return new Node(key, value);
}

/*
hash_function 구현
key 값을 알려주면 hash_table의 사이즈를 사용해서 모듈러 연산을 실행해준다.
이후에 나머지를 사용해서 어떠한 인덱스를 사용하도록 할 것인지 정해준다.
*/
int hash_function(const int key){
    return key % SIZE;
}

// insert 구현
void insert(const int key, const int value){
    int hash_index = hash_function(key);
    Node* new_node = create_node(key, value);

    // hash_index 에 node 값이 없는 경우
    if(hash_table[hash_index].head == NULL){
        hash_table[hash_index].head = new_node;
        hash_table[hash_index].count++;
    }
    // hash_index 에 node 값이 있는 경우
    else{
        Node* tmp = hash_table[hash_index].head;
        new_node->next = tmp;
        hash_table[hash_index].head = new_node;
        hash_table[hash_index].count++;
    }
}

// remove 구현
void remove(const int key){
    int hash_index = hash_function(key);
    Node* node = hash_table[hash_index].head;
    // 현재 singly linked list를 사용하기 때문에 이전 노드를 알 방법이 없다.
    // 따라서 trace 변수에다가 이전 노드의 주소를 저장해두자.
    Node* trace = NULL;

    if(node == NULL){
        std::cout << "\nno key found\n";
        return;
    }
    
    while(node != NULL){
        if(node->key == key){
            // node를 찾았는데 그 노드가 head에 있는 경우
            if(node == hash_table[hash_index].head){
                hash_table[hash_index].head = node->next;
                node->next = NULL;    
            }
            else{
                trace->next = node->next;
                node->next = NULL;
            }
            hash_table[hash_index].count--;
            delete node; 
            return;
        }
        else{
            trace = node;
            node = node->next;
        }
    }

    std::cout << "\nnot key found\n";
}

// search 구현
// 찾으면 찾은 key, value 출력, 못찾으면 error message 출력
void search(int key){
    int hash_index = hash_function(key);
    Node* node = hash_table[hash_index].head;

    if(node ==  NULL){
        std::cout << "\nno key found\n";
        return;
    }

    while(node != NULL){
        if(node->key == key){
            std::cout << "\nkey found => key: " << node->key << ", value: " << node->value << '\n';
            return;
        }
        node = node->next;
    }    
    // hash_index 에 들어가서 찾아 봤는데 원하던 key 값은 존재하지 않은 경우
    std::cout << "not key found\n";
}

void display(){
    for(int i = 0; i < SIZE; i++){
        Node* node = hash_table[i].head;
        if(node == NULL){
            std::cout << "hash_index: " << i << " => empty\n";
            continue;
        }
        std::cout << "hash_index: " << i << " =>";
        while(node != NULL){
            std::cout << " [key: " << node->key << ", value: " << node->value << ']';
            node = node->next;
        }
        std::cout << '\n';
    } 
    std::cout << "\n\n";
}
int main(){
    hash_table = new Bucket[SIZE];

    insert(0, 1);
    insert(1, 10);
    insert(11, 90);
    insert(21, 64);
    insert(31, 23);
    insert(6, 25);
    insert(97, 4);

    display();

    remove(31);
    remove(11);

    display();

    search(6);
    search(100);
    delete[] hash_table;
    return 0;
}