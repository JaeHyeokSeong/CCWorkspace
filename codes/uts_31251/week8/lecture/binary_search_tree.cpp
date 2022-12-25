#include <iostream>
#include "bst.hpp"

int main(){
    Bst bst;
    bst.insert(50);
    bst.insert(15);
    bst.insert(62);
    bst.insert(80);
    bst.insert(7);
    bst.insert(54);
    bst.insert(11);
    bst.display();

    std::pair<Node*, Node*> node = bst.search(54);
    std::cout << "parent key: " << node.first->key << '\n';
    std::cout << "current key: " << node.second->key << '\n';

    node = bst.search(15);
    std::cout << "parent key: " << node.first->key << '\n';
    std::cout << "current key: " << node.second->key << '\n';

    // node = bst.search(100);
    // if(node.second == NULL){
    //     std::cout << "not found\n";
    //     return -1;
    // }
    // std::cout << "parent key: " << node.first->key << '\n';
    // std::cout << "current key: " << node.second->key << '\n';

    bst.insert(20);
    node = bst.search(20);
    std::cout << "parent key: " << node.first->key << '\n';
    std::cout << "current key: " << node.second->key << '\n';
    return 0;
}