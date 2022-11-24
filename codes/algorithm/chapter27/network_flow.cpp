#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
using std::fill;
using std::min;
const int n = 6;
vector<int> node_connections[n+1]; // 각 노드들 마다 열결되어진 노드들 기록
int capacity[n+1][n+1]; // 용량 기록
int flow[n+1][n+1]; // 유량 기록
int visited[n+1]; // 방문 여부 기록

int maxFlow(int start, int end){
    int result = 0;
    const int INF = 10000000;
    while(1){
        fill(visited, visited + n + 1, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i < node_connections[node].size(); i++){
                int connected_node = node_connections[node][i];
                if(visited[connected_node] == -1 && capacity[node][connected_node] - flow[node][connected_node] > 0){
                    q.push(connected_node);
                    visited[connected_node] = node;
                    if(connected_node == end)
                        break;
                }
            }
        }
        if(visited[end] == -1)
            break;
        int f = INF;
        for(int i = end; i != start; i = visited[i]){
            f = min(f, capacity[visited[i]][i] - flow[visited[i]][i]);
        }
        for(int i = end; i != start; i = visited[i]){
            flow[visited[i]][i] += f;
            flow[i][visited[i]] -= f; // 음의 영억
        }
        result += f;
    }
    return result;
}
int main(){
    // [1] initialise
    node_connections[1].push_back(2);
    node_connections[2].push_back(1);
    capacity[1][2] = 12;

    node_connections[1].push_back(4);
    node_connections[4].push_back(1);
    capacity[1][4] = 11;

    node_connections[2].push_back(4);
    node_connections[4].push_back(2);
    capacity[2][4] = 3;

    node_connections[2].push_back(5);
    node_connections[5].push_back(2);
    capacity[2][5] = 5;

    node_connections[2].push_back(3);
    node_connections[3].push_back(2);
    capacity[2][3] = 6;

    node_connections[2].push_back(6);
    node_connections[6].push_back(2);
    capacity[2][6] = 9;

    node_connections[3].push_back(5);
    node_connections[5].push_back(3);
    capacity[5][3] = 3;

    node_connections[3].push_back(6);
    node_connections[6].push_back(3);
    capacity[3][6] = 8;

    node_connections[4].push_back(5);
    node_connections[5].push_back(4);
    capacity[4][5] = 9;

    node_connections[5].push_back(6);
    node_connections[6].push_back(5);
    capacity[5][6] = 4;

    printf("max flow : %d\n" ,maxFlow(1,6));
    return 0;
}