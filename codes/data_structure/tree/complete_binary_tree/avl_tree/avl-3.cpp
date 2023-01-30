#include <iostream>
#include <cstdlib>
#include <ctime>
#include "avl-3.hpp"

int read_input(std::string txt){
    int input;
    std::cout << txt;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "[0] show, [1] add, [2] remove, [3] search, [4] clear, [-1] finish\n";
}

void warning_message(){
    std::cout << "invalid input\n";
}

void test(){
    AVL avl;
    int input = 0;
    do{ 
        menu();
        input = read_input("enter number: ");
        if(input == 0) avl.show();
        else if(input == 1) avl.insert(read_input("enter data: "));
        else if(input == 2) avl.remove(read_input("enter data: "));
        else if(input == 3){
            if(avl.search(read_input("enter data: "))) std::cout << "found\n";
            else std::cout<< "not found\n";
        }
        else if(input == 4) system("clear");
        else if(input == -1) std::cout << "finished\n";
        else warning_message();
    }while(input != -1);
}

void test1(){
    AVL avl;
    std::srand((unsigned int)time(NULL));
    int count = 50000000;
    int range = 50000000;

    std::cout << "after inserting\n";
    for(int i = 0; i < count; i++){
        avl.insert(rand() % range);
    }
    avl.show();

    std::cout << "\nafter removing\n";
    for(int i = 0; i < count; i++){
        avl.remove(rand() % range);
    }
    avl.show();
    std::cout << "total removed node numbers: " << count_removed_nodes << '\n';
}

int main(){
    test1();
    return 0;
}