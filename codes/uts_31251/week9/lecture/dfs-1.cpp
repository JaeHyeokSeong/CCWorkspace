#include <iostream>
#include <vector>
#define MAX 8

std::vector<int> nodes[MAX];
bool marked[MAX];

void dfs(int start_node){
    if(marked[start_node]) return;
    marked[start_node] = true;
    std::cout << start_node << ' ';
    for(int i = 0; i < nodes[start_node].size(); i++){
        dfs(nodes[start_node][i]);
    }
}
int main(){
    nodes[1].push_back(2);
    nodes[1].push_back(3);

    nodes[2].push_back(1);
    nodes[2].push_back(3);
    nodes[2].push_back(4);
    nodes[2].push_back(5);

    nodes[3].push_back(1);
    nodes[3].push_back(2);
    nodes[3].push_back(6);
    nodes[3].push_back(7);

    nodes[4].push_back(2);
    nodes[4].push_back(5);

    nodes[5].push_back(2);
    nodes[5].push_back(5);

    nodes[6].push_back(3);
    nodes[6].push_back(7);

    nodes[7].push_back(3);
    nodes[7].push_back(6);

    dfs(1);
    return 0;
}