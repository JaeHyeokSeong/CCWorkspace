/*
수행 날짜 : 2023/01/19
알고리즘 : 위상 정렬 (Toplogy Sort)
참고 사이트 : https://blog.naver.com/ndb796/221236874984

구현 방법 : 큐를 사용하여서 Toplogy Sort 구현하기. 
step1 : 진입차수가 0인 정점을 큐에 삽입합니다.
step2 : 큐에서 원소를 꺼내 연결된 모든 간선을 제거합니다.
step3 : 간선 제거 이후에 진입차수가 0이 된 정점을 큐에 삽입합니다.
step4 : 큐가 빌 때까지 2번 ~ 번 과정을 반복합니다. 모든 원소를 방문하기 이전에 큐가 빈다면 사이클이 
존재하는 것이고, 모든 원소를 방문했다면 큐에서 꺼낸 순서가 위상 정렬의 결과입니다.

*/
#include <iostream>
#include <vector>
#include <queue>

/*
[parameter]
int node_cout : 총 노드의 수
std::vector<int>* edges : 각 노드의 간선정보를 담고 있는 배열
int* in_degree : 각 노드의 진입차수를 담고 있는 배열

[return]
없음
*/
void topology_sort(int node_count, std::vector<int>* edges, int* in_degree){
    // in_degree 가 0인 노드들을 큐에 삽입
    std::queue<int> q;
    // 진입차수가 0인 노드들 큐에 삽입
    for(int i = 1; i <= node_count; i++){
        if(in_degree[i] == 0) q.push(i);
    }

    // 모든 원소를 방문하기 이전에 큐가 비여있다면 사이클이 발생한다는 의미
    // 즉 큐에서 총 노드의 수 만큼 pop 해야한다.
    for(int i = 1; i <= node_count; i++){
        if(q.empty()) return;
        int node = q.front();
        std::cout << node << ' ';
        q.pop();
        // node 에 연결된 모든 간선들 재거하기
        for(int i = 0; i < edges[node].size(); i++){
            int connected_node = edges[node][i];
            if(--in_degree[connected_node] == 0) q.push(connected_node);
        }
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> edges[8];
    edges[1].push_back(2);
    edges[1].push_back(5);
    edges[2].push_back(3);
    edges[5].push_back(6);
    edges[3].push_back(4);
    edges[4].push_back(6);
    edges[6].push_back(7);

    int in_degree[8];
    in_degree[1] = 0;
    in_degree[2] = 1;
    in_degree[3] = 1;
    in_degree[4] = 1;
    in_degree[5] = 1;
    in_degree[6] = 2;
    in_degree[7] = 1;

    topology_sort(7, edges, in_degree);
    
    return 0;
}