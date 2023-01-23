#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000

// 각 노드들의 간선들 저장
// index = 시작 노드, pair.first = 거리(비용), pair.second = 도착 노드
std::vector<std::pair<int, int> > a[7];
// 시작 노드에서 도착노드까지의 최소거리를 저장해두는 배열
int min_distance[7];

void dijkstra(int start_node){
    // pair.fisrt = distance, pair.second = end_node
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int,int> > > pq;
    pq.push(std::make_pair(0, start_node));
    // 시작노드에서 시작노드까지의 거리는 0이다
    min_distance[start_node] = 0;

    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();
        // min_distance[current_node] 보다 current_distance 이 큰 경우 continue
        if(min_distance[current_node] < current_distance) continue;
        // currnet_node 에서 방문할 수 있는 노드들을 확인한다
        for(int i = 0; i < a[current_node].size(); i++){
            int next_node = a[current_node][i].second;
            int next_distance = a[current_node][i].first;
            // current_distance + next_distacne 는 start_node에서 next_node 까지의 거리를 의미하는 것이다
            // 더 작은 거리가 발견된 경우
            if(min_distance[next_node] > current_distance + next_distance){
                min_distance[next_node] = current_distance + next_distance;
                pq.push(std::make_pair(min_distance[next_node], next_node));
            }
        }
    }
}

int main(){
    // start node
    int start_node = 1;
    // min_distance INF로 초기화
    std::fill(min_distance, min_distance + 7, INF);
    // 간선 정보 초기화
    a[1].push_back(std::make_pair(2, 2));
    a[1].push_back(std::make_pair(1, 4));
    a[1].push_back(std::make_pair(5, 3));

    a[2].push_back(std::make_pair(2, 1));
    a[2].push_back(std::make_pair(2, 4));
    a[2].push_back(std::make_pair(3, 3));

    a[3].push_back(std::make_pair(5, 1));
    a[3].push_back(std::make_pair(3, 2));
    a[3].push_back(std::make_pair(3, 4));
    a[3].push_back(std::make_pair(1, 5));
    a[3].push_back(std::make_pair(5, 6));

    a[4].push_back(std::make_pair(1, 1));
    a[4].push_back(std::make_pair(3, 3));
    a[4].push_back(std::make_pair(1, 5));

    a[5].push_back(std::make_pair(1, 4));
    a[5].push_back(std::make_pair(1, 3));
    a[5].push_back(std::make_pair(2, 6));

    a[6].push_back(std::make_pair(2, 5));
    a[6].push_back(std::make_pair(5, 3));

    // process
    dijkstra(start_node);

    // output
    for(int i = 1; i <= 6; i++){
        std::cout << start_node << " => " << min_distance[i] << '\n';
    }
    return 0;
}