// Program 3 - set vs map
#include <iostream>
#include <set>

int main(){
    std::set<std::pair<int, int> > s;
    s.insert(std::make_pair(1, 2)); 
    s.insert(std::make_pair(1, 3));
    auto result = s.insert(std::make_pair(1,3));
    if(result.second == false){
        std::cout << "insert method failed\n";
    }
    for(std::set<std::pair<int, int> >::iterator it = s.begin(); it != s.end(); it++){
        std::cout << it->first << ' ' << it->second << '\n';
    }
    return 0;
}