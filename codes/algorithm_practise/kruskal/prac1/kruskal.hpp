#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP
#include <vector>

namespace my_algorithm {
    // 특정 노드의 부모를 리턴합니다.
    int getParent(int* parents, int node);
    // 두 노드를 연결시켜 줍니다. (부모 값을 업데이트)
    void unionParent(int* parents, int node_1, int node_2);
    // 두 노드가 연결되어있으면 true, 거짓이면 false를 리턴합니다.
    bool unionFind(int* parents, int node_1, int node_2);
    // class Edge
    class Edge {
        public:
            int node_1, node_2, cost;
            Edge(const int& node_1, const int& node_2, const int& cost);
            // 오름차순으로 정렬 합니다.
            bool operator< (const Edge& _edge) const;
    };
    // kruskal algorithm 
    // 모든 노드들을 연결할때 가장 적은 비용으로 연결할 수 있는 값을 리턴 합니다.
    int kruskal(std::vector<my_algorithm::Edge>& _edges, const int& node_number);
}

#endif // KRUSKAL_HPP