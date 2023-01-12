/*
문제 : https://www.acmicpc.net/problem/1197
사용된 알고리즘 : 프림 (prim)
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001

class Edge{
	public:
		int node, distance;
		Edge(int node, int distance){
			this->node = node;
			this->distance = distance;
		}
		// priority queue에서 거리가 작은 것이 가장 top에 오도록 하기
		bool operator <(const Edge& edge) const{
			return distance > edge.distance;
		}
};

// total distance 를 리턴 한다
int prim(std::vector<Edge>* edges, bool* visited, int start_node){
	// priority queue 선언
	std::priority_queue<Edge> pd;

	// total distance 를 저장하는 변수
	int total_distance = 0;

	// 임의의 정점에서 시작
	pd.push(Edge(start_node, 0));

	while(!pd.empty()){
		int current_node = pd.top().node;
		int distance = pd.top().distance;
		pd.pop();

		if(visited[current_node]) continue;
		visited[current_node] = true;
		total_distance += distance;

		// current_node 에서 도달할 수 있는 노드들을 탐색한다
		for(int i = 0; i < edges[current_node].size(); i++){
			int next_node = edges[current_node][i].node;
			int next_distance = edges[current_node][i].distance;

			if(visited[next_node]) continue;
			pd.push(Edge(next_node, next_distance));
		}
	}

	return total_distance;
}

// 초기값을 입력을 받는다, 그리고 임의의 정점에서 시작해야 하는데 그 정점을 
// 반환해준다.
int read_input(std::vector<Edge>* edges){
	int number_of_node, number_of_edge;
	std::cin >> number_of_node >> number_of_edge;

	int node1, node2, distance;
	for(int i = 1; i <= number_of_edge; i++){
		std::cin >> node1 >> node2 >> distance;
		edges[node1].push_back(Edge(node2, distance));
		edges[node2].push_back(Edge(node1, distance));
	}

	return node1;
}

void test_inputed_values(const std::vector<Edge>* edges){
	std::cout << "test inputed values\n";
	for(int i = 1; i <= 3; i++){
		for(int j = 0; j < edges[i].size(); j++){
			std::cout << i << " 노드랑 연결되어진 노드들\n";
			std::cout << edges[i][j].node << ", " << edges[i][j].distance << '\n';
		}
	}
}
int main(){
	// 정점의 수 : 1 <= 정점의 수 <= 10,000
	// 저장되어진 형태
	// 1. index는 간선에서 첫번째 노드를 말한다
	// 2. Edge 객체에서 node 변수에 연결되어진 노드를 입력한다
	// 3. Edge 객체에서 distance 변수에 두 노드 사이의 간격을 기록한다
	std::vector<Edge> edges[MAX];
	
	// 노드의 방문 여부를 기록하는 배열
	bool visited[MAX] = {false, };

	// 초기값 입력
	int start_node = read_input(edges);
	
	// prim function 호출
	int total_distance = prim(edges, visited, start_node);

	// output
	std::cout << total_distance << '\n';
	return 0;
}
