/*
수행 날 : 2023/01/20
알고리즘 : 코사라주 알고리즘 (Kosaraju's Algorithm)
알고리즘 설명 : DFS 탐색을 두번하여서 SCC를 구하는 알고리즘이다

구현 방법
    step1 - original graph, transpose graph 준비
    step2 - DFS 탐색을 시작하며 탐색이 끝난 순서로 스택에 삽입
    step3 - transpose graph에서 스택에서 하나씩 꺼낸값으로 SCC 구하기
*/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

// 정점, 간선, 총 scc 수
int v, e, cnt;
// 정방향, 역방향 그래프
std::vector<std::vector<int> > graph, transpose_graph;
// 각 정점의 방문여부를 기록하는 배열
bool visited[10001];
// stack 
std::stack<int> s;
// result
std::vector<std::vector<int> > SCC;

bool compare(const std::vector<int>& a, const std::vector<int> &b){
    return a[0] < b [0];
}

void dfs1(int node){
    visited[node] = true;
    // 다음 노드들 탐색
    for(int i = 0; i < graph[node].size(); i++){
        int next = graph[node][i];
        if(!visited[next]) dfs1(next);
    }
    s.push(node);
}

void dfs2(int node, int index){
    visited[node] = true;
    SCC[index].push_back(node);
    // 다음 노드들 탐색
    for(int i = 0; i < transpose_graph[node].size(); i++){
        int next = transpose_graph[node][i];
        if(!visited[next]) dfs2(next, index); 
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    // 정점, 간선의 수를 입력받는다
    std::cin >> v >> e;
    // 그래프의 정보를 담을 벡터 사이즈 재설정
    graph.resize(v + 1); 
    transpose_graph.resize(v + 1);
    // 간선의 수만큼 간서의 수를 입력 받는다
    for(int i = 0; i < e; i++){
        // a to b
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        transpose_graph[b].push_back(a);
    }

    // 첫번째 dfs1 실행
    for(int i = 1; i <= v; i++){
        if(!visited[i]) dfs1(i);
    }

    // 두번째 dfs2 실행 이전에 방문 여부를 기록하는 배열 다시 false로 초기화
    std::fill(visited, visited + 10001, false);
    // 두번째 dfs2 실행
    while(!s.empty()){
        int n = s.top();
        s.pop();
        if(visited[n]) continue;
        SCC.resize(++cnt);
        dfs2(n, cnt - 1);
    }

    // 오름차순으로 정렬
    for(int i = 0; i < cnt; i++){
        std::sort(SCC[i].begin(), SCC[i].end());
    }
    std::sort(SCC.begin(), SCC.end(), compare);

    // output
    std::cout << cnt << '\n';
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < SCC[i].size(); j++){
            std::cout << SCC[i][j] << ' ';
        }
        std::cout << "-1\n";
    }
    return 0;
}