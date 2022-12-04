#include <iostream>
#include <vector>
#include <queue>
#define N 32001
std::vector<int> result;
void topology_sort(int n, int in_degrees[], std::vector<int> connected_node[]){
    std::queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in_degrees[i] == 0)
            q.push(i);
    }

    for(int i = 0; i < n; i++){
        if(q.empty())
            return;
        result.push_back(q.front());
        q.pop();

        for(int j = 0; j < connected_node[result[i]].size(); j++){
            int n = connected_node[result[i]][j];
            if(--in_degrees[n] == 0)
                q.push(n);
        }
    }
}
int main(){
    // [1] initialise
    // n 학생 수, m 비교 횟수
    int n, m, x, y, in_degrees[N] = {};
    std::vector<int> connected_node[N];
    // [2] input
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        connected_node[x].push_back(y);
        in_degrees[y]++;
    }
    // [3] process
    topology_sort(n, in_degrees, connected_node);
    // [4] output
    for(int i = 0; i < result.size(); i++){
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}