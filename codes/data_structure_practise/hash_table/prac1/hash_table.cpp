#include "hash_table.hpp"

bucket::bucket(){
    head = NULL;
    count = 0;
}

Hash_table::Hash_table(const int size){
    hash_table = new bucket[size];
    hash_table_size = size;
}

Hash_table::~Hash_table(){
    for(int i = 0; i < hash_table_size; i++){
        node* ptr_n = hash_table[i].head;
        while(ptr_n != NULL){
            node* ptr = ptr_n;
            ptr_n = ptr_n->next;
            delete ptr;
        }
    }
    delete[] hash_table;
}

node* Hash_table::create_node(const int key, const int value){
    node* ptr_n = new node;
    ptr_n->key = key;
    ptr_n->value = value;
    ptr_n->next = NULL;
    return ptr_n;
}

int Hash_table::hash_function(const int key){
    return key % hash_table_size;
}

void Hash_table::insert(const int key, const int value){
    int hash_index = hash_function(key);
    node* n = create_node(key, value);

    // 내가 넣고자 하는 bucket에 이미 값이 있는 경우랑 없는 경우 총 2가지 상황이 있다
    // case 1 값이 없는 경우
    if(hash_table[hash_index].head == NULL){
        hash_table[hash_index].head = n;
    }
    // case 2 값이 이미 있는 경우 
    else{
        n->next = hash_table[hash_index].head;
        hash_table[hash_index].head = n;
    }
    hash_table[hash_index].count++;
}

void Hash_table::remove(const int key){
    int hash_index = hash_function(key);
    node* ptr_n = hash_table[hash_index].head;

    // 접근할려는 hash_index에 있는 head가 NULL인 경우
    if(ptr_n == NULL){
        std::cout << "key: " << key << " has not founded\n";
        return;
    }

    // key 값을 지움 여부를 결정하는 변수
    bool is_removed = false;
    // 이전 노드를 기록하기 위한 변수
    node* p_n = NULL;
    // 접근할려는 hash_index에 있는 head가 NULL아닌 경우
    // 노드들 중에서 key값이랑 일치하는 값이 있는지 찾는다
    while(ptr_n != NULL){
        // 찾은 경우
        if(ptr_n->key == key){
            // head 위치에서 key 값을 찾은 경우
            if(ptr_n == hash_table[hash_index].head){
                hash_table[hash_index].head = ptr_n->next;
                delete ptr_n;
            }
            // head 위치말고 다른 곳에서 key 값을 찾은 경우 
            else{
                p_n->next = ptr_n->next;
                delete ptr_n;
            }
            is_removed = true;
            hash_table[hash_index].count--;
            break;
        }
        // 못찾은 경우 다음 노드로 넘어간다
        p_n = ptr_n;
        ptr_n = ptr_n->next;
    }

    if(is_removed) std::cout << "key: " << key << " has removed\n";
    else std::cout << "key: " << key << " has not founded\n";
}

void Hash_table::search(const int key){
    int hash_index = hash_function(key);
    node* ptr_n = hash_table[hash_index].head;

    if(ptr_n == NULL){
        std::cout << "key: " << key << " has not founded\n";
        return;
    }

    bool is_founded = false;
    while(ptr_n != NULL){
        if(ptr_n->key == key){
            is_founded = true;
            std::cout << "[key founded] key: " << key << ", value: " << ptr_n->value << '\n';
            break;
        }
        ptr_n = ptr_n->next;
    }

    if(!is_founded) std::cout << "key: " << key << " has not founded\n";
}