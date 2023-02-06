#include "hash_table.hpp"

int main(){
    Hash_table ht(10);

    ht.insert(1, 5);
    ht.insert(21, 10);
    ht.insert(31, 55);
    ht.insert(5, 20);

    ht.search(21); // founded
    ht.search(5); // founded
    ht.search(100); // not founded

    ht.remove(21); // removed
    ht.remove(200); // not removed

    ht.search(21); // not founded
    ht.search(31); // founded
    return 0;
}