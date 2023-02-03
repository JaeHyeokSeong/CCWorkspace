#include "stdlib.h"
#include "binary_search_tree.hpp"

enum menu_type{
    INSERT = 1,
    REMOVE,
    SHOW,
    CLEAR,
    FINISH
};  

int read_input(const char* str){
    int input;
    std::cout << str;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "[1] INSERT, [2] REMOVE, [3] SHOW, [4] clear, [5] FINISH\n";
}

void test(){
    Binary_Search_Tree bst;

    while(1){
        menu();
        int choice = read_input("enter number: ");

        switch(choice){
            case INSERT:
                bst.insert(read_input("enter data: "));
                break;
            case REMOVE:
                bst.remove(read_input("enter data: "));
                break;
            case SHOW:
                bst.show();
                break;
            case CLEAR:
                system("clear");
                break;
            case FINISH:
                std::cout << "finished\n";
                return;
            default:
                std::cout << "[warning]: invalid input\n";
                break;
        };
    }
}

int main(){
    test();
    return 0;
}