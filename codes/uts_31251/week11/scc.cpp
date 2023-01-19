/*
수행 일 : 2023/01/19
알고리즘 : 강한 결합 요소 (Strongly Connected Component)
참고 자료 : https://blog.naver.com/ndb796/221236952158

구현 방법 : SCC 를 구하는 대표적인 알고리즘은 2가지가 있다 (코사라주 알고리즘, 타잔 알고리즘). 이 코드에서는
타잔 알고리즘을 통하여서 SCC 를 추출해보도록 하겠습니다. 
*/

#include <iostream>
#include <vector>
#include <stack>

// SCC result
std::vector<std::vector<int> > SCC;

/*
[parameter]
int node : 시작 노드
std::vector<int>* edges : 간선 정보 배열
int* node_parent : 각 노드의 부모를 저장하는 배열
std::stack<int>* s : 모든 노드들을 방문하기 위해서 stack 필요
bool* finished : 노드가 종료 여부를 위한 배열
[return]
int : 각 노드의 부모 노드를 리턴 
*/
int dfs(int node, std::vector<int>* edges, int* node_parent, std::stack<int>* s, bool* finished){
    node_parent[node] = node;
    s->push(node);

    int parent = node_parent[node];
    for(int i = 0; i < edges[node].size(); i++){
        int connected_node = edges[node][i];
        // 방문하지 않은 이웃 노드
        if(node_parent[connected_node] == 0) parent = std::min(parent, dfs(connected_node, edges, node_parent, s, finished));
        // 처리중이 이웃
        else if(!finished[connected_node]) parent = std::min(parent, node_parent[connected_node]);
    }

    // 부모노드가 자기 자신인 경우
    if(parent == node_parent[node]){
        std::vector<int> scc;
        while(1){
            int x = s->top();
            s->pop();
            scc.push_back(x);
            finished[x] = true;
            if(x == node) break;
        }
        SCC.push_back(scc);
    }    

    return parent;
}

int main(){
    // 간선 정보
    std::vector<int> edges[12];
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

    // 각 노드의 부모노드
    int node_parent[12] = {}; // 0 으로 초기화
    // stack 
    std::stack<int> s;
    // node finished
    bool finished[12] = {false, };

    for(int i = 1; i <= 11; i++){
        if(node_parent[i] == 0) dfs(i, edges, node_parent, &s, finished);
    }

    std::cout << "total scc : " << SCC.size() << '\n';

    for(int i = 0; i < SCC.size(); i++) {
        std::cout << i + 1 << " 번째 scc : ";
        for(int j = 0; j < SCC[i].size(); j++){
            std::cout << SCC[i][j] << ' ';
        }
        std::cout << '\n';
    }
    return 0;
}