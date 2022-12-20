#include <iostream>
#include <vector>
#include <set>

int main(){
    std::set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);

    std::set<int>::iterator it = s.find(4);
    if(it != s.end())
        std::cout << "found: " << *it << '\n';

    for(it = s.begin(); it != s.end(); it++){
        std::cout << *it << '\n';
    }

    std::vector<int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);

    int i = std::find(v.begin(), v.end(), 2) - v.begin();
    std::cout << "found at index: " << i << '\n';

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }
}