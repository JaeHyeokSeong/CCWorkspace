/*
node 0 - 1, 5, 3
node 1 - 5, 2, 0
node 2 - 4, 3, 1
node 3 - 4, 2, 0
node 4 - 5, 3, 2
node 5 - 4, 1, 0

구현 계획 : stack을 사용해서 dfs 구현하기
실행 계획 
	1. 스택의 최상단 노드를 확인합니다.
	2. 최상단 노드에서 방문 되어지지 않은 인접한 노드가 있으면 스택에
	넣고 방문처리를 해준다. 방문하지 않은 인접한 노드가 없으면 최상단 
	노드를 뺀다.
*/
#include <iostream>
#include <vector>
#define MAX 6

// 인접 노드
std::vector<int> nodes[MAX];
// 방문 여부, false로 초기화
bool marked[MAX] = {};
// dfs
void dfs(int node_num){
	// 방문이 되어진 경우
	if(marked[node_num]) return;
	// 방문이 안되어진 경우, 방문 표시하기
	marked[node_num] = true;
	std::cout << node_num << ' ';
	for(int i = 0; i < nodes[node_num].size(); i++){
		dfs(nodes[node_num][i]);
	}
}
int main(){
	nodes[0].push_back(1);
	nodes[0].push_back(5);
	nodes[0].push_back(3);

	nodes[1].push_back(5);
	nodes[1].push_back(2);
	nodes[1].push_back(0);

	nodes[2].push_back(4);
	nodes[2].push_back(3);
	nodes[2].push_back(1);

	nodes[3].push_back(4);
	nodes[3].push_back(2);
	nodes[3].push_back(0);

	nodes[4].push_back(5);
	nodes[4].push_back(3);
	nodes[4].push_back(2);

	nodes[5].push_back(4);
	nodes[5].push_back(1);
	nodes[5].push_back(0);

	dfs(0);
	return 0;
}
