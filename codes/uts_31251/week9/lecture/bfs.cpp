/*
구현 계획 : queue를 사용해서 bfs 구현
실행 계획  
	1. 큐에서 하나의 노드를 꺼냅니다.
	2. 꺼낸 노드에서 연결되어진 노드들 중에서 방문하지 않은 노드를 
	방문처리 한 후, 차례대로 큐에 삽입합니다.
*/
#include <iostream>
#include <vector>
#include <queue>
#define MAX 8

std::vector<int> nodes[MAX];
bool visited[MAX] = {};
std::queue<int> q;

void bfs(int node_num){
	q.push(node_num);
	visited[node_num] = true;
	while(!q.empty()){
		node_num = q.front();
		q.pop();
		std::cout << node_num << ' ';
		for(int i = 0; i < nodes[node_num].size(); i++){
			int tmp = nodes[node_num][i];
			if(!visited[tmp]){
				q.push(tmp);
				visited[tmp] = true;
			}
		}
	}
}
int main(){
	nodes[1].push_back(2);
	nodes[2].push_back(1);
	nodes[2].push_back(3);
	nodes[2].push_back(4);
	nodes[2].push_back(5);	
	nodes[3].push_back(1);
	nodes[3].push_back(2);
	nodes[3].push_back(6);
	nodes[3].push_back(7);
	nodes[4].push_back(2);
	nodes[4].push_back(5);
	nodes[5].push_back(2);
	nodes[5].push_back(4);
	nodes[6].push_back(3);
	nodes[6].push_back(7);
	nodes[7].push_back(3);
	nodes[7].push_back(7);

	bfs(1);
	return 0;
}
