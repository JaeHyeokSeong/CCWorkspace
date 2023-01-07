#include <iostream>
#include <stdlib.h>
#define MAX 9

// 부모 노드의 값을 저장하는 배열
int parent_nodes[MAX];
// 해당하는 노드이 부모 노드의 값을 가져오는 함수
int get_parent(int* parent_nodes, int node){
    if(parent_nodes[node] == node) return node;
    return parent_nodes[node] = get_parent(parent_nodes, parent_nodes[node]);
}
// 각 부모 노드를 합쳐주는 함수
void union_parent(int* parent_nodes, int n1, int n2){
    int n1_parent_node = get_parent(parent_nodes, n1);
    int n2_parent_node = get_parent(parent_nodes, n2);
    // 각 부모 노드를 합칠때 보통 더 작은 부모 노드의 값으로 합친다 
    if(n1_parent_node > n2_parent_node)
        parent_nodes[n1_parent_node] = n2_parent_node;
    else
        parent_nodes[n2_parent_node] = n1_parent_node;
}
// 두 노드가 서로 연결되어져 있는지 확인 하는 함수
int union_find(int* parent_nodes, int n1, int n2){
    int n1_parent_node = get_parent(parent_nodes, n1);
    int n2_parent_node = get_parent(parent_nodes, n2);
    return (n1_parent_node == n2_parent_node) ? 1 : 0;
}
int display_menu(){
    int choice;
    std::cout << "1 - union, 2 - union_find, 3 - clear, 4 - exit\n";
    std::cin >> choice;
    return choice;
}
int main(){
    // 초기에는 서로 연결이 안되어 있기때문에 부모노드에는 자기자신을 가르키고 있다
    for(int i = 1; i < MAX; i++){
        parent_nodes[i] = i;
    }
    int choice;
    do{
        choice = display_menu();
        if(choice == 1){
            int n1, n2;
            std::cout << "n1 숫자를 입력해 주세요: ";
            std::cin >> n1;
            std::cout << "n2 숫자를 입력해 주세요: ";
            std::cin >> n2;
            union_parent(parent_nodes, n1, n2);
        }
        else if(choice == 2){
            int n1, n2;
            std::cout << "n1 숫자를 입력해 주세요: ";
            std::cin >> n1;
            std::cout << "n2 숫자를 입력해 주세요: ";
            std::cin >> n2;
            int result = union_find(parent_nodes, n1, n2);
            if(result) std::cout << "connected\n";
            else std::cout << "unconnected\n";
        } else if(choice == 3){
            system("clear");
        } else if(choice == 4){
            std::cout << "finished\n";
        }
    }while(choice != 4);
    return 0;
}