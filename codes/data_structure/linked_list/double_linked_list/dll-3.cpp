#include <iostream>
#include "dll-3.hpp"
#define TYPE std::string

template <typename T>
T read_input(std::string txt){
    std::cout << txt;
    T input;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "[1] push_front(data), [2] push_back(data), [3] get_node_at(index), [4] insert_node_at(index, data), [5] remove_node_at(index), [6] get_count(), [0] display(), [-1] exit\n";
}

void test(){
    DLL<TYPE> dll;
    int input = 0;
    do{
        menu();
        input = read_input<int>("enter: ");
        if(input == 1) dll.push_front(read_input<TYPE>("enter data: "));
        else if(input == 2) dll.push_back(read_input<TYPE>("enter data: "));
        else if(input == 3) {
            Node<TYPE>* node = get_node_at(dll.get_head() ,read_input<int>("enter index: "), dll.get_count());
            if(node != NULL) std::cout << node->data << '\n';
        }
        else if(input == 4) dll.insert_node_at_after(read_input<int>("enter index: "), read_input<TYPE>("enter data: "));
        else if(input == 5) dll.remove_node_at(read_input<int>("enter index: "));
        else if(input == 6) std::cout << dll.get_count() << '\n';
        else if(input == 0) dll.display();
        else if(input == -1) std::cout << "finished\n";
        else std::cout << "invalid input\n";

    }while(input != -1);
}

int main(){
    test();
    return 0;
}