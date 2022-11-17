#include <iostream>
#include <stack>
#include <vector>

using std::cout;
using std::vector;
using std::stack;

/*
각 노드들 마다 인접한 노드들을
벡터 안에다가 기록함
*/
vector<int> adjacent_nodes[8];

void dfs(int start_node){
	/* 
	방문되어진 노드들 기록하는 배열
	1 - 방문됨
	0 - 방문안됨
	*/
	int visited_nodes[8] = {};
	stack<int> s;
	s.push(start_node);
	visited_nodes[start_node] = 1;
	cout << start_node << ' ';

	while(!s.empty()){
		int node = s.top();
		/*
		인접한 노드들 중에서 방문되어지지 않은 노드들이 있으면 
		unvisited_node 변수에 1을 대입해준다.
		*/
		int unvisited_node = 0;
		for(int i = 0; i < adjacent_nodes[node].size(); i++){
			int ad_node = adjacent_nodes[node][i];
			if(!visited_nodes[ad_node]){
				s.push(ad_node);
				visited_nodes[ad_node] = 1;
				unvisited_node = 1;
				cout << ad_node << ' ';
			}
		}
		if(!unvisited_node){
			/*
			인접한 노드들 중에서 방문이 안된 노드들이 없기
			때문에 스택에서 최상단에 있는 값을 pop 해준다
			*/
			s.pop();
		}
	}
	cout << '\n';
}
int main(){
	// node 1
	adjacent_nodes[1].push_back(2);
	adjacent_nodes[1].push_back(3);

	// node 2
	adjacent_nodes[2].push_back(1);
	adjacent_nodes[2].push_back(3);
	adjacent_nodes[2].push_back(4);
	adjacent_nodes[2].push_back(5);

	// node 3
	adjacent_nodes[3].push_back(1);
	adjacent_nodes[3].push_back(2);
	adjacent_nodes[3].push_back(6);
	adjacent_nodes[3].push_back(7);

	// node 4
	adjacent_nodes[4].push_back(2);
	adjacent_nodes[4].push_back(5);

	// node 5
	adjacent_nodes[5].push_back(2);
	adjacent_nodes[5].push_back(4);

	// node 6
	adjacent_nodes[6].push_back(3);
	adjacent_nodes[6].push_back(7);

	// node 7
	adjacent_nodes[7].push_back(3);
	adjacent_nodes[7].push_back(6);

	dfs(1);
	return 0;
}
