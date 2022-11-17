#include <iostream>
#include <vector>
#include <queue>
using std::cout;
using std::vector;
using std::queue;

int number = 7; // 다루는 원소의 갯수가 7개 이다
int c[8]; // 방문처리를 위한 c이라는 배열
vector<int> a[8]; // 각 노드를 1 부터 7로 보기위해서 사이즈를 8로 설정
// 각 인덱스에 vector<int> 타입의 default 객체가 생성됨

void bfs(int start){
	// 먼저 큐를 만들어 준다
	queue<int> q;
	// 맨 처음 노드를 queue에다가 push한다
	q.push(start);
	// queue에 push한 노드는 방문 처리를 해줘야 한다
	c[start] = true; // 방문했다는 의미로 1을 대입한다
	// queue 가 empty가 될때까지 반복수행을 해주면 된다
	while(!q.empty()){
		// 큐에서 하나의 노드를 꺼낸다
		int x = q.front();
		q.pop();
		cout << x << ' ';
		/*
		뽑은 노드에서 인접한 노드들을 방문한다
		*/
		for(int i = 0; i < a[x].size(); i++){
			int y = a[x][i];
			// 방문 하지 않은 노드이면 queue에 push 해준다
			if(!c[y]){
				q.push(y);
				// 방문 처리
				c[y] = true;
			}
		}
	}	
	cout << '\n';
}
int main(){
	// node 1 기준
	a[1].push_back(2);
	a[1].push_back(3);

	// node 2 기준
	a[2].push_back(1);
	a[2].push_back(3);
	a[2].push_back(4);
	a[2].push_back(5);

	// node 3 기준
	a[3].push_back(1);
	a[3].push_back(2);
	a[3].push_back(6);
	a[3].push_back(7);

	// node 4 기준 
	a[4].push_back(2);
	a[4].push_back(5);

	// node 5 기준 
	a[5].push_back(4);
	a[6].push_back(2);

	// node 6 기준
	a[6].push_back(3);
	a[6].push_back(7);

	// node 7 기준 
	a[7].push_back(6);
	a[7].push_back(3);

	bfs(1);
	return 0;
}
