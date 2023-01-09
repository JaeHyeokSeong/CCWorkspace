/*
알고리즘 : Kruskal Algorithm

내용 : 최소한의 비용으로 모든 노드들의 연결하자, 이때 최소비용으로 연결해야하므로
사이클이 발생되어지면 안된다. 사이클이 발생하는지 아는 방법은 union find을
통해서 알 수 있다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 7

class Edge{
    public:
        int nodes[2];
        double distance;
        Edge(const int n1, const int n2, const double distance){
            nodes[0] = n1;
            nodes[1] = n2;
            this->distance = distance;
        }
        // 오름차순으로 정렬
        bool operator <(const Edge& edge) const{
            return this->distance < edge.distance;
        }
};

int get_parent(int* nodes_parent, int node){
    if(nodes_parent[node] == node) return node;
    return nodes_parent[node] = get_parent(nodes_parent, nodes_parent[node]);
}

void union_parent(int* nodes_parent, int node1, int node2){
    int node1_parent = get_parent(nodes_parent, node1);
    int node2_parent = get_parent(nodes_parent, node2);
    if(node1_parent > node2_parent)
        nodes_parent[node1_parent] = node2_parent;
    else    
        nodes_parent[node2_parent] = node1_parent;
}

bool find_parent(int* nodes_parent, int node1, int node2){
    int node1_parent = get_parent(nodes_parent, node1);
    int node2_parent = get_parent(nodes_parent, node2);
    return (node1_parent == node2_parent) ? true : false;
}

int main(){
    std::vector<Edge> edges;
    edges.push_back(Edge(0, 1, 2));
    edges.push_back(Edge(0, 5, 5));
    edges.push_back(Edge(0, 3, 4));
    edges.push_back(Edge(1, 2, 3.5));
    edges.push_back(Edge(2, 3, 3));
    edges.push_back(Edge(3, 4, 6));
    edges.push_back(Edge(4, 6, 1));
    edges.push_back(Edge(4, 5, 2.5));
    edges.push_back(Edge(5, 6, 1.5));

    // 오름차순으로 정렬
    sort(edges.begin(), edges.end());

    int nodes_parent[MAX];
    for(int i = 0; i < MAX; i++){
        nodes_parent[i] = i;
    }

    double total_distance = 0.0;
    for(int i = 0; i < edges.size(); i++){
        // 두 노드가 서로 연결되어 있지 않은경우만 서로 연결한다.
        if(!find_parent(nodes_parent, edges[i].nodes[0], edges[i].nodes[1])){
            union_parent(nodes_parent, edges[i].nodes[0], edges[i].nodes[1]);
            total_distance += edges[i].distance;
        }
    }

    printf("total distance : %f\n", total_distance);
    return 0;
}