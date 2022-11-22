#include <iostream>
#include <queue>
using std::priority_queue;
using std::pair;
using std::make_pair;

int main(){
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(1, -1));
    pq.push(make_pair(2, -2));
    printf("%d\n", pq.top().first);
    return 0;
}