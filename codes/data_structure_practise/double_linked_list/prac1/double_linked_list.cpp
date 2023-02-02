#include "double_linked_list.hpp"

enum menu_type{
    PUSH_FRONT = 1,
    PUSH_BACK,
    REMOVE_AT,
    INSERT_AT_AFTER,
    SHOW,
    FINISH
};  

int read_input(const char* str){
    int input;
    std::cout << str;
    std::cin >> input;
    return input;
}

void menu(){
    std::cout << "[1] push_front, [2] push_back, [3] remove_at, [4] insert_at_after, [5] show, [6] finish\n";
}

void test(){
    Double_Linked_List dll;

    while(1){
        menu();
        int choice = read_input("enter number: ");

        switch(choice){
            case PUSH_FRONT:
                dll.push_front(read_input("enter data: "));
                break;
            case PUSH_BACK:
                dll.push_back(read_input("enter data: "));
                break;
            case REMOVE_AT:
                dll.remove_at(read_input("enter index: "));
                break;
            case INSERT_AT_AFTER:
                dll.insert_at_after(read_input("enter index: "), read_input("enter data: "));
                break;
            case SHOW:
                dll.show();
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