#include <iostream>
#include <vector>
#include <stack>
#define MAX 100

int parents[MAX];
bool finished[MAX];
std::vector<int> edges[MAX];
std::vector<std::vector<int> > SCC;
std::stack<int> s;

int dfs(int node) {
	parents[node] = node;
	s.push(node);
	int parent = parents[node];

	for(int i = 0; i < edges[node].size(); i++) {
		int nextNode = edges[node][i];
		if(parents[nextNode] == 0) parent = std::min(parent, dfs(nextNode));
		else if(!finished[nextNode]) parent = std::min(parent, parents[nextNode]);
	}

	if(parent == parents[node]) {
		std::vector<int> scc;
		while(1) {
			int a = s.top();
			s.pop();
			finished[a] = true;
			scc.push_back(a);
			if(a == node) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main() {

	int nodes = 11;
	edges[1].push_back(2);
	edges[2].push_back(3);
	edges[3].push_back(1);
	edges[4].push_back(2);
	edges[4].push_back(5);
	edges[5].push_back(7);
	edges[6].push_back(5);
	edges[7].push_back(6);
	edges[8].push_back(5);
	edges[8].push_back(9);
	edges[9].push_back(10);
	edges[10].push_back(11);
	edges[11].push_back(8);
	edges[11].push_back(3);

	for(int i = 1; i <= nodes; i++) {
		if(parents[i] == 0) dfs(i);
	}

	std::cout << SCC.size() << '\n';

	for(int i = 0; i < SCC.size(); i++) {
		for(int j = 0; j < SCC[i].size(); j++) {
			std::cout << SCC[i][j] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
