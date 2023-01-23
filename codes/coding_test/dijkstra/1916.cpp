/*
실행일: 2023/01/23
백준 문제 사이트: https://www.acmicpc.net/problem/1916
알고리즘: 다익스트라 알고리즘
*/
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

// N = 도시의 수, M = 버스의 수
int N, M;
// 도시들 사이의 간선정보를 담고있는 벡터
// index = start_node, pair.first = distance, pair.second = end_node
std::vector<std::pair<int, int> > a[1001];
// 최서거리를 저장하는 배열
int min_distance[1001];

void solution(int start_node){
    min_distance[start_node] = 0;
    // start_node 에서 pair.first = distance, pair.second = end_node
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
    pq.push(std::make_pair(0, start_node));

    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if(min_distance[current_node] < current_distance) continue;
        for(int i = 0; i < a[current_node].size(); i++){
            int next_node = a[current_node][i].first;
            int next_distance = current_distance + a[current_node][i].second;
            // 더 짧은 거리가 발견된 경우
            if(min_distance[next_node] > next_distance){
                min_distance[next_node] = next_distance;
                pq.push(std::make_pair(next_distance, next_node));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    // 도시의 수, 버스의 수 입력받기
    std::cin >> N >> M;
    std::fill(min_distance, min_distance + 1001, INF);
    // M의 수 만큼 도시들 사이의 간선 정보 초기화 하기
    // 순서: 출발도시 >> 도착도시 >> 그 사이 비용
    int start_node, end_node, distance;
    for(int i = 0; i < M; i++){
        std::cin >> start_node >> end_node >> distance;
        a[start_node].push_back(std::make_pair(end_node, distance));
    }

    // 출발도시, 도착도시 입력받기
    std::cin >> start_node >> end_node;
    // process
    solution(start_node);
    // output
    std::cout << min_distance[end_node];
    return 0;
}