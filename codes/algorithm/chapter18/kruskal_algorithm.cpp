/*
주제 : kruskal algorithm 
설명 : kruskal algorithm 은 모든 노드들을 최소한의 거리(비용)으로 모두
연결할려고 할때 사용되어지는 알고리즘 이다. 예를 들어서 각 도시(노드)들을 모두
연결하는 고속도로(간선)을 건설한다고 할때 최소한 비용으로 모든 노드들을 연결하는
방법을 찾을때 이 kruskal algorithm이 사용이 되어진다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include "edge.hpp"
using std::vector;
using std::sort;

int getParent(int* parent, int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = getParent(parent, parent[node]);
}
void union_nodes(int* parent, int n1, int n2){
    int n1_parent = getParent(parent, n1);
    int n2_parent = getParent(parent, n2);
    if(n1_parent > n2_parent){
        parent[n1] = n2_parent;
    } else{
        parent[n2] = n1_parent;
    }
}
int find_nodes_connection(int* parent, int n1, int n2){
    // 만약 부모 값이 두 노드다 같으면 두 노드들은 서로 연결 되어져 있다는 의미
    int n1_parent = getParent(parent, n1);
    int n2_parent = getParent(parent, n2);
    if(n1_parent == n2_parent){
        return 1;
    } else {
        return 0;
    }
}
int main(){
    // [1] initialise
    vector<Edge> edges;
    int total_distance_sum = 0;
    // node1
    edges.push_back(Edge(1,7,12));
    edges.push_back(Edge(1,4,28));
    edges.push_back(Edge(1,2,67));
    edges.push_back(Edge(1,5,17));
    // node2
    edges.push_back(Edge(2,4,24));
    edges.push_back(Edge(2,5,62));
    // node3
    edges.push_back(Edge(3,5,20));
    edges.push_back(Edge(3,6,37));
    // node4
    edges.push_back(Edge(4,7,13));
    // node5
    edges.push_back(Edge(5,6,45));
    edges.push_back(Edge(5,7,73));

    // parent node default setting
    int parent[8]; 
    for(int i = 1; i < 8; i++){
        parent[i] = i;
    }

    // [2] process
    // Edge들을 거리기준으로 오름차순으로 정렬을 한다
    sort(edges.begin(), edges.end());
    /*
    각 노드들을 연결시켜준다. 이때 이미 연결되어진 노드들은
    연결할려고 시도하면 사이클이 발생한다. 이를 방지하기 위해서
    union find 을 적용한다. 즉, 부모가 같으면 이미 연결된
    의미이다.
    */
    for(int i = 0; i < edges.size(); i++){
        if(!find_nodes_connection(parent, edges[i].getN1(), edges[i].getN2())){
            total_distance_sum += edges[i].getDistance();
            union_nodes(parent, edges[i].getN1(), edges[i].getN2());
        }
    }
    // [3] output
    printf("total distance : %d\n", total_distance_sum);

    // [4] test result
    // total distance : 123
    return 0;
}