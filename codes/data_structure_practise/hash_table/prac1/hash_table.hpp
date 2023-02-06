#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP
#include <iostream>

typedef struct node{
    int key, value;
    node* next;
}node;

typedef struct bucket{
    node* head;
    int count;
    bucket();
}bucket;

class Hash_table{
    private:
        bucket* hash_table;
        int hash_table_size;
    public:
        Hash_table(const int size);
        ~Hash_table();
        node* create_node(const int key, const int value);
        int hash_function(const int key);     
        void insert(const int key, const int value);   
        void remove(const int key);
        void search(const int key);
};

#endif // HASH_TABLE_HPP