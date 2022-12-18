#include <iostream>
#include <vector>
#include <list>

int main(){
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }
    std::cout << "vector\n";
    std::vector<int>::iterator it = v.begin();
    std::cout << *(it + 2) << '\n';

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);

    std::cout << "list\n";
    for(std::list<int>::iterator it = lst.begin(); it != lst.end(); it++){
        std::cout << *it << '\n';
    }
    // 1 2 3 4 

    std::list<int>::iterator it1 = lst.begin();
    std::advance(it1, 2);
    std::cout << *it1 << '\n'; // 3
    return 0;
}