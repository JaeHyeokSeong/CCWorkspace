#include <iostream>
#define MAX 9

int get_parent(int* nodes_parents, int node){
    if(nodes_parents[node] == node) return node;
    return nodes_parents[node] = get_parent(nodes_parents, nodes_parents[node]);
}

void union_parent(int* nodes_parents, int node1, int node2){
    int node1_parent = get_parent(nodes_parents, node1);
    int node2_parent = get_parent(nodes_parents, node2);
    if(node1_parent > node2_parent)
        nodes_parents[node1_parent] = node2_parent;
    else    
        nodes_parents[node2_parent] = node1_parent;
}

bool union_find(int* nodes_parents, int node1, int node2){
    int node1_parent = get_parent(nodes_parents, node1);
    int node2_parent = get_parent(nodes_parents, node2);
    return (node1_parent == node2_parent) ? true : false;
}
int main(){
    int nodes_parents[MAX];
    for(int i = 1; i < MAX; i++){
        nodes_parents[i] = i;
    }    

    union_parent(nodes_parents, 1, 2);
    union_parent(nodes_parents, 2, 3);

    bool result = union_find(nodes_parents, 1, 4);

    if(result)
        std::cout << "connected\n";
    else    
        std::cout << "unconnected\n";
    return 0;
}