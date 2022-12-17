// Program 4 - avoid overfill a vector
#include <iostream>
#include <vector>

int main(){
    std::vector<int> v;
    for(int i = 0; i < 30; i++){
        v.push_back(i);
    }
    for(int i = 0; i < v.size(); i++){
        std::cout << v[i] << '\n';
    }
    return 0;
}