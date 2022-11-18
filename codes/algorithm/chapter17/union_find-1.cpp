#include <iostream>
using std::cout;

// 노드의 부모노드가 무엇인지 알아내는 함수
int getParent(int* nodes_parents, int node){
    if(nodes_parents[node] == node){
        return node;
    }
    return nodes_parents[node] = getParent(nodes_parents, nodes_parents[node]); 
}
// 2개의 노드들을 연결해준다
void union_nodes(int* nodes_parents, int node1, int node2){
    int node1_parent = getParent(nodes_parents, node1);
    int node2_parent = getParent(nodes_parents, node2);
    if(node1_parent > node2_parent){
        nodes_parents[node1] = node2_parent;
    } else{
        nodes_parents[node2] = node1_parent;
    }
}
// 2개의 노드들이 연결되어져 있는지 확인하는 함수
int compare_parent(int* nodes_parents, int node1, int node2){
    int node1_parent = getParent(nodes_parents, node1);
    int node2_parent = getParent(nodes_parents, node2);
    if(node1_parent == node2_parent){
        return 1; // 연결되어져 있음
    } else {
        return 0; // 연결되어져 있지 않음
    }
}
int main(){
    // [1] initialise
    int nodes_parents[10];
    for(int i = 1; i <=9; i++){
        nodes_parents[i] = i;
    }
    // [2] process
    union_nodes(nodes_parents, 1, 2);
    union_nodes(nodes_parents, 2, 3);
    // [3] output
    cout << "1 3 => " << compare_parent(nodes_parents, 1, 3) << '\n';
    cout << "1 4 => " << compare_parent(nodes_parents, 1, 4) << '\n';
    union_nodes(nodes_parents, 2, 4);
    cout << "3 4 => " << compare_parent(nodes_parents, 3, 4) << '\n';
    return 0;
}