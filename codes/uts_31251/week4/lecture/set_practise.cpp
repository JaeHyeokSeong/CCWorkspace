#include <iostream>
#include <set>

int main(){
    std::set<int> my_set;
    std::pair<std::set<int>::iterator, bool> result = my_set.insert(1);
    std::cout << result.second << '\n';
    result = my_set.insert(1);
    std::cout << result.second << '\n';
    my_set.insert(2);
    my_set.insert(-1);
    for(std::set<int>::iterator it = my_set.begin(); it != my_set.end(); it++){
        std::cout << *it << '\n';
    }
    return 0;
}