#include <iostream>
// 현재 정점의 갯수 6개
int number = 6;
int INF = 1000000000;

// 전체 그래프를 초기화 하기
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};
// 노드의 방문여부를 기록하는 배열
bool v[6] = {}; 
// 최단 거리를 저장할 배열
int d[6] = {};
// 가장 최소 거리를 가지는 정점을 반환하는 함수
int getSmallIndex(){
    int min = INF;
    int index = 0;
    for(int i = 0; i < number; i++){
        if(d[i] < min && !v[i]){
            min = d[i];
            index = i;
        }
    }
    return index;
}
// dijkstra 알고리즘
void dijkstra(int start){
    // 시작노드에서 각노드까지의 거리를 저장한다
    for(int i = 0; i < number; i++){
        d[i] = a[start][i];
    }
    // 시작노드는 방문되어졌으니까 방문처리를 해준다
    v[start] = 1;
    for(int i = 0; i < number - 1; i++){
        // 방문하지 않은 노드중에서 가장 비용이 적은 노드 선택
        int current = getSmallIndex();
        // 해당노드 방문처리 
        v[current] = 1;
        for(int j = 0; j < number; j++){
            if(!v[j]){
                if(d[current] + a[current][j] < d[j])
                    d[j] = d[current] + a[current][j];
            }
        }
    }
}
int main(){
    dijkstra(0);
    for(int i = 0; i < number; i++){
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}