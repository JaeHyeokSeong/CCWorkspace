#include <iostream>
#include <queue>

using std::cout;
using std::queue;

int main(){
    queue<int> q;
    q.push(7);
    q.push(5);
    q.push(4);
    q.pop();
    while(!q.empty()){
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
    return 0;
}