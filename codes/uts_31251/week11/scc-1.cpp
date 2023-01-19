#include <iostream>
#include <vector>
#include <stack>
#define MAX 12

// 진행 여부를 알수있는 배열
bool finished[MAX];
// 현재 노드의 부모를 저장하는 배열
int node_parent[MAX];
// 각 노드의 간선들의 정하는 벡터 배열
std::vector<int> edges[MAX];
// scc에서 사용되어지는 stack
std::stack<int> s;
// 각각의 scc를 저장하는 SCC 벡터
std::vector<std::vector<int> > SCC;

int scc(int node){
    // 초기에 각 노드의 부모는 자기 자신이다
    node_parent[node] = node;
    // node를 stack에 push 해준다
    s.push(node);
    // parent 변수에 현재 노드의 부모 값을 저장해둔다
    int parent = node_parent[node];

    // 현재 노드에서 인접한 노드들을 찾는다
    for(int i = 0; i < edges[node].size(); i++){
        int connected_node = edges[node][i];
        // 인접 노드가 아직 방문 되어지지 않은 경우
        if(node_parent[connected_node] == 0) parent = std::min(parent, scc(connected_node));
        // 이미 방문되어진 노드인 경우, 현재 연결되어진 노드가 아직 진행중인 노드인지 확인한다
        else if(!finished[connected_node]) parent = std::min(parent, node_parent[connected_node]);
    }

    // 현재 노드랑 그 노드의 부모 노드 값이랑 값이 같으면 SCC가 발견된것이다.
    if(parent == node){
        std::vector<int> scc;
        // stack에서 현재 노드가 나올때 까지 계속 pop한다
        while(1){
            int x = s.top();
            s.pop();
            scc.push_back(x);
            // scc에 포함된 노드들은 진행이 끝난것 이기에 true를 대입
            finished[x] = true;
            // stack에서 top한 값이 현재 노드의 값이 일치하는 경우
            if(x == node) break;
        }
        SCC.push_back(scc);
    }    
    
    // 현재 노드의 부모를 리턴
    return parent;
}

int main(){
    // [1] input
    edges[1].push_back(2);
    edges[2].push_back(3);
    edges[3].push_back(1);
    edges[4].push_back(2);
    edges[4].push_back(5);
    edges[5].push_back(7);
    edges[6].push_back(5);
    edges[7].push_back(6);
    edges[8].push_back(5);
    edges[8].push_back(9);
    edges[9].push_back(10);
    edges[10].push_back(11);
    edges[11].push_back(8);
    edges[11].push_back(3);

    // [2] process
    for(int i = 1; i < MAX; i++){
        if(node_parent[i] == 0) scc(i);
    }

    // [3] output
    std::cout << "totla SCC : " << SCC.size() << '\n';
    for(int i = 0; i < SCC.size(); i++){
        std::cout << i + 1 << " 번째 scc : ";
        for(int j = 0; j < SCC[i].size(); j++){
            std::cout << SCC[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}