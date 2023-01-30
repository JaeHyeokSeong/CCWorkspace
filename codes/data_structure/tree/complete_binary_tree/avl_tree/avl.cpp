/*
실행일: 2023/01/29
자료형 구조: AVL Tree
참고사이트: 
    [1] https://srdeveloper.tistory.com/29 (구현)
    [2] https://srdeveloper.tistory.com/28 (개념)
    [3] https://www.youtube.com/watch?v=9BiHgy40NNE&t=302s (개념)
    [4] https://www.geeksforgeeks.org/deletion-in-an-avl-tree/
        (adjust_balance에서 범위 고칠때 사용)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "avl-2.hpp"

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
    int count = 100000;
    int range = 1000000;
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
}

int main(){
    test1();
    
    return 0;
}