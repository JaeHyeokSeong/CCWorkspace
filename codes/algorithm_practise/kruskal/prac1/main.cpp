#include <iostream>
#include "kruskal.hpp"

int main(){
    std::vector<my_algorithm::Edge> _edges;
    _edges.push_back(my_algorithm::Edge(1, 7, 12));
    _edges.push_back(my_algorithm::Edge(1, 4, 28));
    _edges.push_back(my_algorithm::Edge(1, 2, 67));
    _edges.push_back(my_algorithm::Edge(1, 5, 17));
    _edges.push_back(my_algorithm::Edge(2, 4, 24));
    _edges.push_back(my_algorithm::Edge(2, 5, 62));
    _edges.push_back(my_algorithm::Edge(3, 5, 20));
    _edges.push_back(my_algorithm::Edge(3, 6, 37));
    _edges.push_back(my_algorithm::Edge(4, 7, 13));
    _edges.push_back(my_algorithm::Edge(5, 6, 45));
    _edges.push_back(my_algorithm::Edge(5, 7, 73));

    int node_number = 7;
    int total_cost = my_algorithm::kruskal(_edges, node_number);
    std::cout << total_cost << '\n';
    
    return 0;
}