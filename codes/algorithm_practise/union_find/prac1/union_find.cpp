#include "union_find.hpp"

int my_algorithm::getParent(int* parents, int node){
    if(parents[node] == node) return node;
    return parents[node] = my_algorithm::getParent(parents, parents[node]);
}

void my_algorithm::unionParent(int* parents, int node1, int node2){
    int node1_parent = getParent(parents, node1);
    int node2_parent = getParent(parents, node2);
    if(node1_parent < node2_parent) parents[node2] = node1_parent;
    else parents[node1] = node2_parent; 
}

bool my_algorithm::unionFind(int* parents, int node1, int node2){
    if(getParent(parents, node1) == getParent(parents, node2)) return true;
    return false;
}