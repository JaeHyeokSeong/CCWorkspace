#include <iostream>
#include <vector>
#include <queue>
using std::vector;
using std::priority_queue;
using std::pair;
using std::make_pair;
int INF = 10000;
// 노드의 수
int number = 6;
// 간성정보를 저장하는 vector
vector<pair<int, int> > a[7];
// 최소비용을 저장하는 배열
int d[7] = {};
void dijkstra(int start){
    // 시작 노드를 입력받으니까 최소비용을 저장하는 d배열에다가 시작노드 부터 시작노드까지의 거리는 0 이므로 0을 대입해준다
    d[start] = 0;
    // 첫번째 int는 노드번호, 두번째 int는 시작노드부터 첫번째에 있는 노드번호까지의 거리
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(start, 0));
    while(!pq.empty()){
        int current = pq.top().first;
        int distance = pq.top().second;
        pq.pop();
        if(d[current] < distance){
            // printf("current: %d, d[current]: %d distance: %d\n", current, d[current], distance);
            continue;
        }
        for(int i = 0; i < a[current].size(); i++){
            int next = a[current][i].first;
            int next_distance = distance + a[current][i].second;
            if(d[next] > next_distance){
                d[next] = next_distance;
                pq.push(make_pair(next, next_distance));
            }
        }
    }
}
int main(){
    // [1] initialise
    /*
    처음에는 어떠한 시작노드를 모르니까 시작노드에서 어디까지의 노드의 거리(비용)을
    모른다. 따라서 이때는 각 노드의 거리에다가 무한한 값을 대입시켜 주는 것이다. 
    */
    for(int i = 1; i <= number; i++){
        d[i] = INF;
    }

    a[1].push_back(make_pair(2, 2));
    a[1].push_back(make_pair(3, 5));
    a[1].push_back(make_pair(4, 1));

    a[2].push_back(make_pair(1, 2));
    a[2].push_back(make_pair(3, 3));
    a[2].push_back(make_pair(4, 2));

    a[3].push_back(make_pair(1, 5));
    a[3].push_back(make_pair(2, 3));
    a[3].push_back(make_pair(4, 3));
    a[3].push_back(make_pair(5, 1));
    a[3].push_back(make_pair(6, 5));

    a[4].push_back(make_pair(1, 1));
    a[4].push_back(make_pair(2, 2));
    a[4].push_back(make_pair(3, 3));
    a[4].push_back(make_pair(5, 1));

    a[5].push_back(make_pair(3, 1));
    a[5].push_back(make_pair(4, 1));
    a[5].push_back(make_pair(6, 2));

    a[6].push_back(make_pair(3, 5));
    a[6].push_back(make_pair(5, 2));

    dijkstra(1);
    for(int i = 1; i <= number; i++){
        printf("%d ", d[i]);
    }
    printf("\n");
    return 0;
}