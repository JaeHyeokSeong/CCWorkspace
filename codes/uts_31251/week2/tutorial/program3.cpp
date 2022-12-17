#include <iostream>
#include <vector>

int main(){
    std::vector<int> v;
    // for(int i = 0; i < 30; i++){
    //     std::cout << v[i] << '\n'; // segmentation fault
    // }

    for(int i : v){
        std::cout << i <<  '\n';
    }
    return 0;
}