// Program 2 - stack (the pair container)
#include <iostream>
#include <stack>

int main(){
    std::stack<std::pair<int, int> > s;
    s.push(std::make_pair(1,1));
    s.push(std::make_pair(2,2));
    s.pop(); // remove std::make_pare(2,2) object
    s.push(std::make_pair(3,3));
    s.push(std::make_pair(4,4));
    s.pop(); // remove std::make_pair(4,4) object
    s.push(std::make_pair(5,5));

    while(!s.empty()){
        std::cout << "first: " << s.top().first << ", second: " << s.top().second << '\n';
        s.pop();
    }
    return 0;
}