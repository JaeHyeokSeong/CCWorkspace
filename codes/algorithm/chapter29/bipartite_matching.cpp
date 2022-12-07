#include <iostream>
#include <vector>
#define MAX 101
#define HUMAN_NUMBER 3  
using std::vector;
using std::fill;

vector<int> human[MAX];
int human_result[MAX];
bool computer[MAX];
bool dfs(int start_node){
    // 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
    for(int i = 0; i < human[start_node].size(); i++){
        int t = human[start_node][i];
        if(computer[t]) continue;
        computer[t] = true;
        // 비어 있거나 또는 점유 노드에 더 들어갈 공간이 있는 경우
        if(human_result[t] == 0 || dfs(human_result[t])){
            human_result[t] = start_node;
            return true;
        }
    }
    return false;
}
int main(){
    // [1] initialise
    // human1
    human[1].push_back(1);
    human[1].push_back(2);
    human[1].push_back(3);
    // human2
    human[2].push_back(1);
    // human3
    human[3].push_back(2);

    // [2] process
    for(int i = 1; i <= HUMAN_NUMBER; i++){
        fill(computer, computer + MAX, false);
        dfs(i);    
    }
    // [3] output
    for(int i = 1; i <= HUMAN_NUMBER; i++){
        printf("human: %d => computer: %d\n", human_result[i], i);
    }
    return 0;
}