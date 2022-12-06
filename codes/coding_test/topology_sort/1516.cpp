#include <iostream>
#include <vector>
#include <queue>
#define MAX_BUILDING_NUMBER 501
using std::vector;
using std::queue;
using std::max;

vector<int> connected_nodes[MAX_BUILDING_NUMBER];
int construction_time[MAX_BUILDING_NUMBER], in_degrees[MAX_BUILDING_NUMBER], result[MAX_BUILDING_NUMBER];
void game_topology_sort(const int& building_number){
    queue<int> q;
    for(int i = 1; i <= building_number; i++){
        if(in_degrees[i] == 0){
            result[i] = construction_time[i];
            q.push(i);
        }
    }
    // node 의 수만큼 큐에 접근하여서 pop 해줘야한다
    for(int i = 0; i < building_number; i++){
        // 사이클이 발새하는 경우
        if(q.empty())
            return;
        int tmp_node = q.front();
        q.pop();
        for(int j = 0; j < connected_nodes[tmp_node].size(); j++){
            int node = connected_nodes[tmp_node][j];
            result[node] = max(result[node], result[tmp_node] + construction_time[node]);
            if(--in_degrees[node] == 0){
                q.push(node);
            }
        }
    }
}
int main(){
    // [1] initialise
    int building_number, required_building;
    // [2] input
    // 첫번째 줄에는 건설할 건물의 수를 입력한다
    scanf("%d", &building_number);
    for(int i = 1; i <= building_number; i++){
        // 건물을 건설할때 걸리는 시간을 입력을 받는다
        scanf("%d", &construction_time[i]);
        // -1 이 나올때 까지 입력을 받는다
        while(1){
            scanf("%d", &required_building);
            if(required_building == -1)
                break;
            connected_nodes[required_building].push_back(i);
            in_degrees[i]++;
        }
    }
    // [3] process
    game_topology_sort(building_number);
    // [4] output
    for(int i = 1; i <= building_number; i++){
        printf("%d\n", result[i]);
    }
    return 0;
}