#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001
int v, e, sccCount, visited[MAX];
std::vector<std::vector<int> > scc;
std::vector<std::vector<int> > graph, reversedGraph;
std::stack<int> s;

void dfs(int node) {
	visited[node] = 1;
	for(int i = 0; i < graph[node].size(); i++) {
		if(!visited[graph[node][i]]) dfs(graph[node][i]);
	}
	s.push(node);
}

void dfs(int node, int sccIndex) {
	visited[node] = 1;
	for(int i = 0; i < reversedGraph[node].size(); i++) {
		if(!visited[reversedGraph[node][i]]) dfs(reversedGraph[node][i], sccIndex);
	}
	scc[sccIndex].push_back(node);
}

bool compare(const std::vector<int>& a, const std::vector<int>& b) {
	return a[0] < b[0];
}

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	// read vector and edge number
	std::cin >> v >> e;
	graph.resize(v + 1);
	reversedGraph.resize(v + 1);

	for(int i  = 0; i < e; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a].push_back(b); // original graph
		reversedGraph[b].push_back(a); // reversed graph
	}

	for(int i = 1; i <= v; i++) {
		if(!visited[i]) dfs(i);
	}

	std::fill(visited, visited + MAX, 0);

	while(!s.empty()) {
		int node = s.top();
		s.pop();
		if(!visited[node]) {
			scc.resize(++sccCount);
			dfs(node, sccCount - 1);
		}
	}

	// sort
	for(int i = 0; i < sccCount; i++) {
		std::sort(scc[i].begin(), scc[i].end());
	}
	std::sort(scc.begin(), scc.end(), compare);

	// output
	std::cout << sccCount << '\n'; 
	for(int i = 0; i < sccCount; i++) {
		for(int j = 0; j < scc[i].size(); j++) {
			std::cout << scc[i][j] << ' ';
		}
		std::cout << "-1\n";
	}
 
	return 0;
}
