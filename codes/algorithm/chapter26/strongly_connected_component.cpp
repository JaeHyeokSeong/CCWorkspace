#include <iostream>
#include <vector>
#include <stack>
#define MAX 1000
using std::vector;
using std::stack;
using std::min;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int> > SCC;
stack<int> s;

int dfs(int x){
    d[x] = ++id;
    s.push(x); // 스택에 현재 들어온 노드 push 하기
    int parent = d[x];

    for(int i = 0; i < a[x].size(); i++){
        int connected_node = a[x][i];
        // d[connected_node] == 0 이라면 아직 connected_node가 stack에 없다는 의미이다
        if(d[connected_node] == 0)
            parent = min(parent, dfs(connected_node));
        else if(!finished[connected_node])
            parent = min(parent, d[connected_node]);
    }

    if(parent == d[x]){
        vector<int> scc;
        int t;
        do{
            t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
        } while(t != x);
        SCC.push_back(scc);
    }
    return parent;
}
int main(){
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);

    for(int i = 1; i <= 11; i++){
        if(d[i] == 0)
            dfs(i);
    }
    printf("scc number : %lu\n", SCC.size());
    for(int i = 0; i < SCC.size(); i++){
        printf("scc %d => ", i+1);
        for(int j = 0; j < SCC[i].size(); j++){
            printf("%d ", SCC[i][j]);
        }
        printf("\n");
    }
    return 0;
}