#include <iostream>
#include "min_heap.hpp"

int read_input(const char* txt){
    int input;
    std::cout << txt;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "1: input, 2: remove_mine, 3: peek, 4: display all, -1: eixt\n";
}

void test(){
    Min_Heap mh;
    int input = 0;
    do{ 
        menu();
        input = read_input("enter number: ");
        if(input == 1) mh.insert(read_input("enter data: "));
        else if(input == 2) mh.remove_min();
        else if(input == 3) mh.peek();
        else if(input == 4) mh.display_all();
        else if(input == -1) std::cout << "finished\n";
        else std::cout << "invalid input\n";
    }while(input != -1);
    
}

int main(){
    test();
    return 0;
}