/*
수행일 : 2023/1/19 
백준 문제 사이트 : https://www.acmicpc.net/problem/2150
사용된 알고리즘 : 코사라주 알고리즘
참고 사이트 : 
- https://ip99202.github.io/posts/SCC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/
- https://www.youtube.com/watch?v=iKNkpiQhsE0
*/

#include<iostream>
#include <stack>
#include <vector>
#include <algorithm>

// 전체 노드의, 간선, scc 의 수
int v, e, cnt;
bool visited[10001];
std::stack<int> s;
// graph : 원래 그래프
// transpose_graph : 역방향 그래프
std::vector<std::vector<int> > graph, transpose_graph;
// result
std::vector<std::vector<int> > SCC;

void dfs1(int node){
	visited[node] = true;
	// 인접노드 탐색
	int next_node;
	for(int i = 0; i < graph[node].size(); i++){
		next_node = graph[node][i];
		if(!visited[next_node]) dfs1(next_node);
	}
	// 더이상 방문할 노드가 없을경우 스택에 push
	s.push(node);
}

void dfs2(int node, int index){
	visited[node] = true;
	SCC[index].push_back(node);
	// next node
	int next_node;
	for(int i = 0; i < transpose_graph[node].size(); i++){
		next_node = transpose_graph[node][i];
		if(!visited[next_node]) dfs2(next_node, index);
	}
}

bool compare(const std::vector<int>& a, const std::vector<int>& b){
	return a[0] < b[0];
}

int main(){
	std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
	std::cin >> v >> e;
	graph.resize(v + 1);
	transpose_graph.resize(v + 1);
	// edge 만큼의 입력을 받는다
	for(int i = 0; i < e; i++){
		// a to b
		int a, b;
		std::cin >> a >> b;
		// 정방향
		graph[a].push_back(b);
		// 역방향
		transpose_graph[b].push_back(a);
	}
	// 첫번째 dfs을 수행한다
	for(int i = 1; i <= v; i++){
		if(!visited[i]) dfs1(i);
	}
	// 두 번째 dfs을 수행하기 이전에 방문배열을 다시 false로 초기화 해줘야 한다
	std::fill(visited, visited + 10001, false);
	// stack이 비기 전까지 계속 진행한다
	while(!s.empty()){
		int n = s.top();
		s.pop();
		if(visited[n]) continue;
		SCC.resize(++cnt);
		dfs2(n, cnt - 1);
	}
	// sort ascending order
	for(int i = 0; i < cnt; i++){
		std::sort(SCC[i].begin(), SCC[i].end());
	}
	std::sort(SCC.begin(), SCC.end(), compare);
	// output
	std::cout << cnt << '\n';
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < SCC[i].size(); j++){
			std::cout << SCC[i][j] << ' ';
		}
		std::cout << "-1\n";
	}
	return 0;	
}