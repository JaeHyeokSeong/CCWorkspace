#include <iostream>
#include "dll-2.hpp"
#define TYPE std::string

template <typename T>
T read_input(std::string txt){
    std::cout << txt;
    T input;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "[1] push_front(data), [2] push_back(data), [3] get_node_at(index), [4] insert_node_at(index, data), [5] remove_node_at(index), [9] display_iterator, [0] display(), [-1] exit\n";
}

void test(){
    Doubly_linked_list<TYPE> dll;
    int input = 0;
    do{
        menu();
        input = read_input<int>("enter: ");
        if(input == 1) dll.push_front(read_input<TYPE>("enter data: "));
        else if(input == 2) dll.push_back(read_input<TYPE>("enter data: "));
        else if(input == 3) {
            Node<TYPE>* node = dll.get_node_at(read_input<int>("enter index: "));
            if(node != NULL) std::cout << node->data << '\n';
        }
        else if(input == 4) dll.insert_node_at(read_input<int>("enter index: "), read_input<TYPE>("enter data: "));
        else if(input == 5) dll.remove_node_at(read_input<int>("enter index: "));
        else if(input == 9) {
            for(Doubly_linked_list<TYPE>::iterator iter = dll.begin(); iter != dll.end(); iter++){
                std::cout << *iter << ' ';
            }
            std::cout << '\n';
        }
        else if(input == 0) dll.display();
        else if(input == -1) std::cout << "finished\n";
        else std::cout << "invalid input\n";

    }while(input != -1);
}

int main(){
    test();
    return 0;
}