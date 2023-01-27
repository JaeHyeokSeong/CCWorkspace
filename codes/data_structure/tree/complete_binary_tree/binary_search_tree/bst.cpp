/*
실행일: 2023/01/27
자료형 구조: Binary Search Tree
참고 사이트: https://hazarddev.tistory.com/40
*/
#include <iostream>
#include <stdlib.h>
#include "bst.hpp"

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
    BST bst;
    int input = 0;
    do{ 
        menu();
        input = read_input("enter number: ");
        if(input == 0) bst.show();
        else if(input == 1) bst.add(read_input("enter data: "));
        else if(input == 2) bst.remove(read_input("enter data: "));
        else if(input == 3){
            if(bst.search(read_input("enter data: "))) std::cout << "found\n";
            else std::cout<< "not found\n";
        }
        else if(input == 4) system("clear");
        else if(input == -1) std::cout << "finished\n";
        else warning_message();
    }while(input != -1);
}

int main(){
    test();
    return 0;
}