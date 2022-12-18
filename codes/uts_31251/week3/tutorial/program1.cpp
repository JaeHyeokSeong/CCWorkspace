// Program 1 - queue (simple type)
#include <iostream>
#include <queue>

int main(){
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.pop(); // 1 remove
    q.push(3);
    q.push(4);
    q.pop(); // 2 remove
    q.push(5);

    while(!q.empty()){
        std::cout << q.front() << '\n';
        q.pop();
    }
    // 3 4 5
    return 0;
}