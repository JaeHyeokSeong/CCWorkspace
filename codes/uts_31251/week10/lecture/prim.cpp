/*
prim 알고리즘
참고자료 : https://ongveloper.tistory.com/376
*/
#include <iostream>
#include <queue>
#define MAX 6

// pair.first = 가중치 (비용)
// 정점 a, b로 이루어진 간선
// edge의 인덱스 = a
// pair.second = b
std::vector<std::pair<int, int> > edges[MAX];

// 연결된 정점인지 저장
bool visited[MAX];

// mst 의 간선비용을 저장
int min_cost = 0;

void prim(){
    // pd.first = 가중치 (비용)
    // pd.second = 정점
    // 가장 작은 값부터 출력하는 방법
    // 자료형이 int형인 경우
    // priority_queue<int, vector<int>, greater<int>> pq;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int> >, std::greater<std::pair<int, int> > > pd;   

    // 임의의 정점에서 시작
    pd.push(std::make_pair(0, 0));

    while(!pd.empty()){

        // pd의 top은 현재 연결된 정점들의 집합에서 갈 수 있는 정점 중 가장 가중치가 작은 정점
        int current_node = pd.top().second;
        int current_distance = pd.top().first;
        pd.pop();
        
        // 정점이 방문이 안되어진 경우만 방문한고, 이미 방문되어진 경우 스킵한다
        if(visited[current_node]) continue;
        visited[current_node] = true;
        min_cost += current_distance;

        // 현재 정점 기준에서 갈 수 있는 정점들을 pd에 push한다.
        for(int i = 0; i < edges[current_node].size(); i++){
            int next_node = edges[current_node][i].second;
            int next_node_distance = edges[current_node][i].first;

            // 이미 방문되어진 경우 pd에 push 할 필요가 없다
            if(visited[next_node]) continue;
            pd.push(std::make_pair(next_node_distance, next_node));
        }        
    }
}
int main(){
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

    prim();
    std::cout << "최소 비용: " << min_cost << '\n'; // 56
    return 0;
}