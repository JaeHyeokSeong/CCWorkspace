#include <iostream>
#include <stdlib.h>
#include "bst.hpp"

int main(){
    Bst bst;
    int a = 0, key;

    while(1){
        printf("1 - insert, 2 - search, 3 - remove, 4 - display, 5 - clear, 6 - end\n값을 입력해주세요 => ");
        scanf("%d", &a);
        if(a == 1){
            printf("삽입할 값을 대입해주세요: ");
            scanf("%d", &key);
            bst.insert(key);
        } else if(a == 2){
            printf("검색할 값을 대입해주세요: ");
            scanf("%d", &key);
            Node* node = bst.search(key);
            if(node)
                printf("key [%d] 발견됨\n", key);
            else
                printf("key [%d] 발견안됨\n", key);
        } else if(a == 3){
            printf("지울값을 대입해주세요: ");
            scanf("%d", &key);
            bst.remove(bst.get_root(), key);
        } else if(a == 4){
            bst.display();
        } else if(a == 5){
            system("clear");
        } else if(a == 6){
            break;
        } 
        else{
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}