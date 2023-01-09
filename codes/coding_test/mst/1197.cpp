/*
문제 링크 : https://www.acmicpc.net/problem/1197
*/
#include <iostream>
#include <vector>
#include <algorithm>

class Edge{
    public:
        int nodes[2], distance;
        Edge(const int n1, const int n2, const int distance){
            nodes[0] = n1;
            nodes[1] = n2;
            this->distance = distance;
        }
        // 오름차순 정렬
        bool operator <(const Edge& edge) const{
            return this->distance < edge.distance;    
        }
};

void read_inputs(std::vector<Edge>* edges){
    int node_count, edge_count;
    std::cin >> node_count >> edge_count;
    for(int i = 0; i < edge_count; i++){
        int n1, n2, distance;
        std::cin >> n1 >> n2 >> distance;
        edges->push_back(Edge(n1, n2, distance));
    }
    std::sort(edges->begin(), edges->end());
}

int get_parent(int* node_parent, int node){
    if(node_parent[node] == node) return node;
    return node_parent[node] = get_parent(node_parent, node_parent[node]);
}

void union_parent(int* node_parent, int n1, int n2){
    int n1_parent = get_parent(node_parent, n1);
    int n2_parent = get_parent(node_parent, n2);
    if(n1_parent > n2_parent)
        node_parent[n1_parent] = n2_parent;
    else    
        node_parent[n2_parent] = n1_parent;
}

bool union_find(int* node_parent, int n1, int n2){
    int n1_parent = get_parent(node_parent, n1);
    int n2_parent = get_parent(node_parent, n2);
    return (n1_parent == n2_parent) ? true : false;
}

int main(){
    std::vector<Edge> edges;
    int node_parent[10001];
    for(int i = 1; i < 10001; i++){
        node_parent[i] = i;
    }
    read_inputs(&edges);
    int total_distance = 0;
    for(int i = 0; i < edges.size(); i++){
        if(!union_find(node_parent, edges[i].nodes[0], edges[i].nodes[1])){
            total_distance += edges[i].distance;
            union_parent(node_parent, edges[i].nodes[0], edges[i].nodes[1]);
        }
    }    
    std::cout << total_distance << '\n';
    return 0;
}