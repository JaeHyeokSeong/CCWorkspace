#include <iostream>
#include "heap-1.hpp"

int read_input(std::string txt){
    int input;
    std::cout << txt;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "[0] show, [1] insert, [2] remove_min, [3] peek, [4] exit\n";
}

void test(){
    int input = 0;
    Min_Heap mh;
    do{
        menu();
        input = read_input("enter number: ");
        if(input == 0) mh.show();
        else if(input == 1) mh.insert(read_input("enter data: "));
        else if(input == 2) mh.remove_min();
        else if(input == 3) mh.peek();
        else if(input == 4) std::cout << "finished\n";
    }while(input != 4);
}

int main(){
    test();
    return 0;
}