#include "max_heap.hpp"

void test(){
    Max_Heap mh;

    // insert
    mh.insert(10);
    mh.insert(20);
    mh.insert(12);
    mh.insert(23);
    mh.insert(5);
    mh.insert(1);
    mh.insert(3);
    mh.insert(60);
    mh.insert(30);
    mh.insert(100);

    // peek
    mh.peek(); // 100
    
    // remove
    mh.remove_max(); // 100 removed

    // peek
    mh.peek(); // 60

    // remove
    mh.remove_max(); // 60 removed

    // peek
    mh.peek(); // 30

    mh.insert(200);

    // peek
    mh.peek(); // 200
}

int main(){
    test();
    return 0;
}