#include <iostream>
#include <queue>
#include <vector>
using std::vector;
using std::queue;
#define MAX 10

int nodes_numbers;
vector<int> node_connections[MAX];
int in_degrees[MAX] = {};
int result[MAX] = {};

void topology_sort(){
    // 진입 차수가 0인 노드들을 저장하기위한 queue
    queue<int> q;
    for(int i = 1; i <= nodes_numbers; i++){
        if(in_degrees[i] == 0)
            q.push(i);
    }

    for(int i = 0; i < nodes_numbers; i++){
        // queue 안에서 노드의 수만큼 방문을 해야하는데 그전에 비여있으면 사이클이 존재한다는 의미
        if(q.empty()){
            printf("사이클 존재\n");
            return;
        }
        // queue에서 값을 하나 가져온다
        result[i] = q.front();
        q.pop();
        // 가져온 노드랑 연결되어진 간선들을 삭제시켜준다
        for(int j = 0; j < node_connections[result[i]].size(); j++){
            int connected_node = node_connections[result[i]][j];
            // 만약 진입차수가 0 이면 queue에 push 해준다
            if(--in_degrees[connected_node] == 0)
                q.push(connected_node);
        }
    }
}
int main(){
    // [1] initialise
    nodes_numbers = 7;
    // node 1 - node 2
    in_degrees[1] = 0;
    node_connections[1].push_back(2);
    in_degrees[2]++;
    // node 1 - node 5
    node_connections[1].push_back(5);
    in_degrees[5]++;
    // node 2 - node 3
    node_connections[2].push_back(3);
    in_degrees[3]++;
    // node 3 - node 4
    node_connections[3].push_back(4);
    in_degrees[4]++;
    // node 4 - node 6
    node_connections[4].push_back(6);
    in_degrees[6]++;
    // node 5 - node 6
    node_connections[5].push_back(6);
    in_degrees[6]++;
    // node 6 - node 7
    node_connections[6].push_back(7);
    in_degrees[7]++;

    // [2] process
    topology_sort();
    // [3] output
    for(int i = 0; i < nodes_numbers; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}