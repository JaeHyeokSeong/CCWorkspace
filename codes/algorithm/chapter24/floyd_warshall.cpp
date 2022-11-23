#include <iostream>
int INF = 10000000;
const int nodes_number = 4;

void floyd_warshall(int nodes[][nodes_number]){
    // nodes 간의 거리를 저장할 2차원 배열
    int d[nodes_number][nodes_number];
    
    // 각노드들 사이의 거리 초기값을 d 2차원 배열에다가 대입시켜줌
    for(int i = 0; i < nodes_number; i++){
        for(int j = 0; j < nodes_number; j++){
            d[i][j] = nodes[i][j];
        }
    }

    // k = 거쳐가는 노드
    // i = 출발노드
    // j = 도착노드
    for(int k = 0; k < nodes_number; k++){
        for(int i = 0; i < nodes_number; i++){
            if(k == i) continue; // 거쳐갈때 자기 자신을 거쳐서 갈필요는 없다
            for(int j = 0; j < nodes_number; j++){
                if(d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j]; // 더 적은 비용으로 갱신 시켜준다
            }
        }
    }

    for(int i = 0; i < nodes_number; i++){
        for(int j = 0; j < nodes_number; j++){
            nodes[i][j] = d[i][j];
        }
    }
} 
int main(){
    // [1] initialise
    int nodes[4][4] = {
        {0, 5, INF, 8},
        {7, 0, 9, INF},
        {2, INF, 0, 4},
        {INF, INF, 3, 0}
    };
    // process
    floyd_warshall(nodes);
    // output
    for(int i = 0; i < nodes_number; i++){
        for(int j = 0; j < nodes_number; j++){
            printf("%d ", nodes[i][j]);
        }
        printf("\n");
    }
    return 0;
}
