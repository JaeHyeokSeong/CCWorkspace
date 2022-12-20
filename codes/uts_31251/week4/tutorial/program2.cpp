// Program 2 - map
#include <iostream>
#include <map>

int main(){
    std::map<int, int> m;
    m.insert(std::make_pair(1, 2));
    m.insert(std::make_pair(3, 4));

    m.erase(3);

    // key 5, value 6
    m[5] = 6;
    // key 7, value 8
    m[7] = 8;

    // updating
    m[1] = 9;

    std::map<int, int>::iterator it = m.find(1);
    if(it != m.end()){
        std::cout << "found => key: " << it->first << ", value: " << it->second << '\n';
    }
    return 0;
}