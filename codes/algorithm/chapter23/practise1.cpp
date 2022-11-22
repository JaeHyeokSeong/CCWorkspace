#include <iostream>
int nodes = 6;
int INF = 1000;
// 방문 여부를 저장하는 배열
bool v[6];
// 노드 사이의 거리를 저장하는 배열
int d[6];
// 노드 거리 초기화
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0}
};
// 방문이 안되어진 노드들 중에서 거리가 가장 짧은 노드를 리턴해준다
int getSmallIndex(){
    int min = INF;
    int index = 0;
    for(int i = 0; i < nodes; i++){
        if(!v[i] && d[i] < min){
            min = d[i];
            index = i;
        }
    }
    return index;
}
void dijkstra(int start){
    // 시작하는 곳을 받으면 그 시작노드부터 다른 노드까지의 거리를 초기화 해준다
    for(int i = 0; i < nodes; i++){
        d[i] = a[start][i];
    }
    // 방문되어진 노드는 방문처리를 해준다
    v[start] = true;
    /*
    방문되어지지 않은 노드들중에서 가장 비용이 적은 노드를 선택하고
    그 노드를 이용해서 다른 노드를 갈때 더 적은 비용이 발생되어지만
    값을 업데이트 해준다
    */
    for(int i = 0; i < nodes - 1; i++){
        int small_index = getSmallIndex();
        v[small_index] = true;
        for(int j = 0; j < nodes; j++){
            if(!v[j]){
                if(d[small_index] + a[small_index][j] < d[j])
                    d[j] = d[small_index] + a[small_index][j];
            }
        }
    }
}
int main(){
    dijkstra(0);
    for(int i = 0; i < nodes; i++){
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}