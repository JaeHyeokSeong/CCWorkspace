#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

int n, m;
std::vector<std::vector<std::pair<int, int> > > a;
int* min_distance;

void dijkstra(int start_node){
    min_distance[start_node] = 0;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
    pq.push(std::make_pair(0, start_node));

    while(!pq.empty()){
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if(min_distance[current_node] < current_distance) continue;

        for(int i = 0; i < a[current_node].size(); i++){
            int next_node = a[current_node][i].second;
            int next_distance = a[current_node][i].first;
            if(min_distance[next_node] > current_distance + next_distance){
                min_distance[next_node] = current_distance + next_distance;
                pq.push(std::make_pair(min_distance[next_node], next_node));
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL); std::cout.tie(NULL);
    std::cin >> n >> m;
    a.resize(n + 1);
    min_distance = new int[n + 1];
    std::fill(min_distance, min_distance + n + 1, INF);

    int start_node, end_node, distance;
    for(int i = 0; i < m; i++){
        std::cin >> start_node >> end_node >> distance;
        a[start_node].push_back(std::make_pair(distance, end_node));
    }

    std::cin >> start_node >> end_node;
    dijkstra(start_node);
    std::cout << min_distance[end_node] << '\n';
    delete[] min_distance;

    return 0;
}