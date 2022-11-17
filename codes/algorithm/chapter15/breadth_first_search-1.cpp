#include <iostream>
#include <vector>
#include <queue>

using std::cout;
using std::vector;
using std::queue;

/*
vector 배열을 생성해 줌으로써 각 노드마다
인접한 노드들을 저장할 수 있도록 해준다. 예를
들어서 노드 1은 인덱스 1을 사용하게 된다. 그리고 
인덱스 1에 접근하면 vector<int> 의 객체가 있는데
이 객체에다가 인접한 노드들을 push_back 해주면 된다.
*/
vector<int> adjacent_node[8];

void bfs(int start_node){
    /*
    사이즈를 8로 해준 이유는 노드의 값이 1 부터 7까지 있는데
    이때 노드 1 은 인덱스 1을 사용하고, 노드 7은 인덱스 7을
    사용하기 위해서 아래의 배열의 사이즈를 8로 설정하였습니다.
    */
    int visited_node[8] = {}; // 0으로 초기화
    // queue 초기화
    queue<int> q;
    // 시작 노드 큐에 대입
    q.push(start_node);
    // 방문되어진 노드들은 방문됨으로 표시하기, 여기에서는 1로 명시함
    visited_node[start_node] = 1;
    // queue 에 값이 없을때 까지 반복을 함
    while(!q.empty()){
        int node = q.front();
        cout << node << ' ';
        q.pop();
        /*
        queue 에서 노드의 값을 가져오면 그 노드와 인접한
        노드들이 있는지 확인을 해줘야 한다.
        */
        for(int i = 0; i < adjacent_node[node].size(); i++){
            int ad_node = adjacent_node[node][i];
            // ad_node 가 방문되어졌는지 확인하기
            if(!visited_node[ad_node]){
                q.push(ad_node);
                // 방문되어진 노드은 방문되어짐으로 표시하기
                visited_node[ad_node] = 1;
            }
        }
    }
    cout << '\n';
}
int main(){
    // node 1
    adjacent_node[1].push_back(2);
    adjacent_node[1].push_back(3);

    // node 2
    adjacent_node[2].push_back(1);
    adjacent_node[2].push_back(3);
    adjacent_node[2].push_back(4);
    adjacent_node[2].push_back(5);

    // node 3
    adjacent_node[3].push_back(1);
    adjacent_node[3].push_back(2);
    adjacent_node[3].push_back(6);
    adjacent_node[3].push_back(7);

    // node 4
    adjacent_node[4].push_back(2);
    adjacent_node[4].push_back(5);

    // node 5
    adjacent_node[5].push_back(2);
    adjacent_node[5].push_back(4);

    // node 6
    adjacent_node[6].push_back(3);
    adjacent_node[6].push_back(7);

    // node 7
    adjacent_node[7].push_back(3);
    adjacent_node[7].push_back(6);

    bfs(1);
    return 0;
}