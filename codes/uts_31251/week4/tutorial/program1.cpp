// Program 1 - set
// set은 값이 중복이 안된다. 또한 오름차순으로 자동적으로 정렬이된다.
#include <iostream>
#include <set>

int main(){
    std::set<int> s;
    s.insert(1);
    s.insert(2);

    s.erase(1);
    
    s.insert(3);
    s.insert(4);

    std::cout << s.count(4) << '\n'; // 1
    std::cout << s.count(1) << '\n'; // 0
}