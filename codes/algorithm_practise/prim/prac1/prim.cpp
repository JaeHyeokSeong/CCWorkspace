#include "prim.hpp"
#include <queue>

int my_algorithm::prim(std::vector<std::pair<int,int> >* edges, int totalNodeNumber, int startNode) {

    int answer = 0;
    bool* visited = new bool[totalNodeNumber];

    // 내림찬순
    // pair.first = distance
    // pair.second = node;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int> >, std::greater<std::pair<int, int> > > pq;
    pq.push(std::make_pair(0, startNode));

    while(!pq.empty()) {
        int currentNode = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if(visited[currentNode]) continue;
        visited[currentNode] = true;
        answer += distance;

        for(int i = 0; i < edges[currentNode].size(); i++) {
            int nextNode = edges[currentNode][i].second;
            int nextDistance = edges[currentNode][i].first;

            if(visited[nextNode]) continue;
            pq.push(std::make_pair(nextDistance, nextNode));
        }
    }

    delete[] visited;
    return answer;
}