#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::queue;
#define MAX 32001
vector<int> connected_nodes[MAX];
int in_degrees[MAX];
int M, N;
void topology_sort(){
    int result[MAX] = {};
    queue<int> q;
    // 진입차수가 0인 노드들은 큐에다가 push 해준다.
    for(int i = 1; i <= N; i++){
        if(in_degrees[i] == 0)
            q.push(i);
    }

    // node 의 수 만큼 큐에 접근하여서 pop 해줘야 한다
    for(int i = 0; i < N; i++){
        if(q.empty())
            return;
        result[i] = q.front();
        q.pop();
        for(int j = 0; j < connected_nodes[result[i]].size(); j++){
            if(--in_degrees[connected_nodes[result[i]][j]] == 0)
                q.push(connected_nodes[result[i]][j]);
        }
    }

    for(int i = 0; i < N; i++){
        printf("%d ", result[i]);
    }
    printf("\n");
}
int main(){
    scanf("%d %d", &N, &M);
    int first_node, second_node;
    for(int i = 1; i <= M; i++){
        scanf("%d %d", &first_node, &second_node);
        connected_nodes[first_node].push_back(second_node);
        in_degrees[second_node]++;
    }
    topology_sort();
    return 0;
}