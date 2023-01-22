/*
수행일 : 2023/01/22(일)
알고리즘 : 다익스트라 (Dijkstra)

알고리즘 설명 : 다익스트라 알고리즘은 다이나믹 프로그래밍을 활용한 대표적인 최단 경로 탐색 알고리즘입니다. 흔히 GPS
소프트웨어 등에서 가장 많이 사용됩니다. 다익스트라 알고리즘은 특정한 하나의 정점에서 다른 모든 정점으로 가는 최단
경로를 알려줍니다. 다만 이때 음의 간선을 포함할 수 없습니다. 물론 현실 세계에서는 음의 간선이 존재하지 않기 때문에
다익스트라는 현실 세계에서 사용하기에 매우 적합한 알고리즘 중 하나라고 할 수 있습니다. 

구현 방법 : 
    1. 출발 노들르 설정합니다.
    2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장합니다.
    3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택합니다.
    4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신합니다.
    5. 위 과정에서 3번 ~ 4번을 반복합니다.

참고사이트 : 
    1. https://blog.naver.com/ndb796/221234424646
*/

#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000

// 총 노드의 수
const int number = 6;
// index = 시작노드, pair.firt = 도착노드, pair.second = 두 노드사이의 거리
std::vector<std::pair<int, int> > a[7];
// 최소 거리를 저장하는 배열
int min_distance[number + 1];

void dijkstra(int start){
    min_distance[start] = 0;
    // min heap 구조를 사용해서 부모 노드가 자식 노드들 보다 항상 값이 작도록 하여서 top을 사용할시 항상 작은 값이 먼저나오도록 한다
    // pair.first = distance, pair.second = 도착 노드
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
    pq.push(std::make_pair(0, start));

    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        for(int i = 0; i < a[current_node].size(); i++){
            int next_node = a[current_node][i].first;
            int next_distance = a[current_node][i].second;
            // 더 작은 경로가 발견된 경우
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
    // 기본적으로 초기에는 각 노드사이의 최소러기를 INF로 설정해둔다
    for(int i = 1; i <= number; i++){
        min_distance[i] = INF;
    }

    // 노드 사이의 거리 정보 초기화
    a[1].push_back(std::make_pair(2, 2));
    a[1].push_back(std::make_pair(3, 5));
    a[1].push_back(std::make_pair(4, 1));
    
    a[2].push_back(std::make_pair(1, 2));
    a[2].push_back(std::make_pair(3, 3));
    a[2].push_back(std::make_pair(4, 2));

    a[3].push_back(std::make_pair(1, 5));
    a[3].push_back(std::make_pair(2, 3));
    a[3].push_back(std::make_pair(4, 3));
    a[3].push_back(std::make_pair(5, 1));
    a[3].push_back(std::make_pair(6, 5));

    a[4].push_back(std::make_pair(1, 1));
    a[4].push_back(std::make_pair(2, 2));
    a[4].push_back(std::make_pair(3, 3));
    a[4].push_back(std::make_pair(5, 1));

    a[5].push_back(std::make_pair(3, 1));
    a[5].push_back(std::make_pair(4, 1));
    a[5].push_back(std::make_pair(6, 2));

    a[6].push_back(std::make_pair(3, 5));
    a[6].push_back(std::make_pair(5, 2));
    
    // process
    dijkstra(start_node);

    // output
    for(int i = 1; i <= number; i++){
        std::cout << start_node << " => " << i << ", cost: " << min_distance[i] << '\n';
    }
    return 0;
}