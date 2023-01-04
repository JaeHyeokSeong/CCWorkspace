#include <iostream>
#include <vector>
#include <queue>
#define MAX 8

std::vector<int> nodes[MAX];
bool marked[MAX];
std::queue<int> q;

void bfs(int start_nodes){
    q.push(start_nodes);
    marked[start_nodes] = true;

    while(!q.empty()){
        int a = q.front();
        q.pop();
        std::cout << a << ' ';
        for(int i = 0; i < nodes[a].size(); i++){
            int b = nodes[a][i];
            if(!marked[b]){
                q.push(b);
                marked[b] = true;
            }
        }
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
    nodes[5].push_back(4);

    nodes[6].push_back(3);
    nodes[6].push_back(7);

    nodes[7].push_back(3);
    nodes[7].push_back(6);

    bfs(1);
    return 0;
}