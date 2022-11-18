#include <iostream>

// 부모 노드를 찾는 함수
int getParent(int* parent_node, int node){
    if(parent_node[node] == node)
        return node;
    return parent_node[node] = getParent(parent_node, parent_node[node]);
}
// 두 부모 노드를 함치는 함수
void union_nodes(int* parent_node, int node1, int node2){
    int node1_parent = getParent(parent_node, node1);
    int node2_parent = getParent(parent_node, node2);
    // 작은 부모 노드로 대입해줘야 한다
    if(node1_parent > node2_parent){
        parent_node[node1] = node2_parent;
    } else{
        parent_node[node2] = node1_parent;
    }
} 
// 두 노드들이 연결되어있는 가를 확인하는 함수
int findParent(int* parent_node, int node1, int node2){
    int node1_parent = getParent(parent_node, node1);
    int node2_parent = getParent(parent_node, node2);
    if(node1_parent == node2_parent){
        return 1; // 두 개의 노드가 연결되어있음
    }
    return 0; // 두 개의 노드가 연결되어있지않음
}
int main(){
    // [1] initialise
    int parent_node[9];
    for(int i = 1; i < 9; i++){
        parent_node[i] = i;
    }
    // [2] process
    union_nodes(parent_node, 1, 2);
    union_nodes(parent_node, 2, 3);
    union_nodes(parent_node, 4, 5);
    union_nodes(parent_node, 1, 4);
    union_nodes(parent_node, 2, 6);
    // [3] output
    std::cout << "node 1 그리고 node 4 의 연결성 : " << findParent(parent_node, 1, 4) << '\n';
    std::cout << "node 3 그리고 node 4 의 연결성 : " << findParent(parent_node, 3, 4) << '\n';
    std::cout << "node 3 그리고 node 6 의 연결성 : " << findParent(parent_node, 3, 6) << '\n';
    std::cout << "node 2 그리고 node 6 의 연결성 : " << findParent(parent_node, 2, 6) << '\n';
    std::cout << "node 1 그리고 node 7 의 연결성 : " << findParent(parent_node, 1, 7) << '\n';
    std::cout << "node 2 그리고 node 5 의 연결성 : " << findParent(parent_node, 2, 5) << '\n';
    return 0;
}