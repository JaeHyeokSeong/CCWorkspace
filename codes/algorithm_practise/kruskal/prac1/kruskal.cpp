#include "kruskal.hpp"

int my_algorithm::getParent(int* parents, int node) {
    if(parents[node] == node) return node;
    return parents[node] = my_algorithm::getParent(parents, parents[node]);
}

void my_algorithm::unionParent(int* parents, int node_1, int node_2) {
    int node_1_parent = getParent(parents, node_1);
    int node_2_parent = getParent(parents, node_2);
    if(node_1_parent > node_2_parent) parents[node_1] = node_2_parent;
    else parents[node_2] = node_1_parent;
}

bool my_algorithm::unionFind(int* parents, int node_1, int node_2) {
    if(my_algorithm::getParent(parents, node_1) == getParent(parents, node_2)) return true;
    return false;
}

my_algorithm::Edge::Edge(const int& node_1, const int& node_2, const int& cost) {
    this->node_1 = node_1;
    this->node_2 = node_2;
    this->cost = cost;
}

bool my_algorithm::Edge::operator< (const Edge& _edge) const {
    return this->cost < _edge.cost;
}

int my_algorithm::kruskal(std::vector<my_algorithm::Edge>& _edges, const int& node_number) {
    // _edges 를 오름차순으로 정렬합니다.
    std::sort(_edges.begin(), _edges.end());
    // 초기 노드의 부모값을 설정합니다.
    int parents[node_number + 1];
    for(int i = 1; i <= node_number; i++) {
        parents[i] = i;
    }
    // algorithm process
    int total_cost = 0;
    for(int i = 0; i < _edges.size(); i++) {
        if(!my_algorithm::unionFind(parents, _edges[i].node_1, _edges[i].node_2)) {
            total_cost += _edges[i].cost;
            my_algorithm::unionParent(parents, _edges[i].node_1, _edges[i].node_2);
        }
    }
    return total_cost;
}