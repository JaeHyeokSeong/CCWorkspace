#include <iostream>
#include "prim.hpp"
#define MAX 6

int main() {
	std::vector<std::pair<int, int> > edges[MAX];
	edges[0].push_back(std::make_pair(16, 1));
    edges[0].push_back(std::make_pair(21, 2));
    edges[0].push_back(std::make_pair(19, 4));
    edges[1].push_back(std::make_pair(16, 0));
    edges[1].push_back(std::make_pair(5, 3));
    edges[1].push_back(std::make_pair(11, 2));
    edges[1].push_back(std::make_pair(6, 5));
    edges[2].push_back(std::make_pair(21, 0));
    edges[2].push_back(std::make_pair(11, 1));
    edges[2].push_back(std::make_pair(33, 4));
    edges[2].push_back(std::make_pair(14, 5));
    edges[3].push_back(std::make_pair(5, 1));
    edges[3].push_back(std::make_pair(10, 5));
    edges[4].push_back(std::make_pair(19, 0));
    edges[4].push_back(std::make_pair(18, 5));
    edges[4].push_back(std::make_pair(33, 2));
    edges[5].push_back(std::make_pair(6, 1));
    edges[5].push_back(std::make_pair(14, 2));
    edges[5].push_back(std::make_pair(10, 3));
    edges[5].push_back(std::make_pair(18, 4));

	int answer = my_algorithm::prim(edges, MAX, 3);
	std::cout << answer << '\n';
	return 0;
}
