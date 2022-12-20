// Program 4 - insertion method
#include <iostream>
#include <map>

int main(){
    std::map<int, std::string> m;
    m.insert(std::make_pair(1, "str1"));
    m.insert(std::make_pair(2, "str2"));
    m.insert(std::make_pair(3, "str3"));

    m[4] = "str4";

    for(std::map<int, std::string>::iterator it = m.begin(); it != m.end(); it++){
        std::cout << it->first << ' ' << it->second << '\n';
    }
    return 0;
}