#include <iostream>

void find_string(std::string parent, std::string pattern){
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int parent_hash = 0, pattern_hash = 0, power = 1;

    for(int i = 0; i <= parent_size - pattern_size; i++){
        if(i == 0){
            for(int j = 0; j < pattern_size; j++){
                parent_hash = parent_hash + parent[pattern_size - 1 - j] * power;
                pattern_hash = pattern_hash + pattern[pattern_size - 1 - j] * power;
                if(j < pattern_size - 1) power *= 2;
            }
        } else{
            parent_hash = 2 * (parent_hash - parent[i - 1] * power) + parent[pattern_size - 1 + i];
        }

        if(parent_hash == pattern_hash){
            bool finded = true;
            for(int j = 0; j < pattern_size; j++){
                if(parent[i + j] != pattern[j]){
                    finded = false;
                    break;
                }
            }

            if(finded){
                std::cout << "found at index: " << i << '\n';
            }
        }
    }
}

int main(){
    std::string parrent = "hello world";
    std::string pattern = "world";

    find_string(parrent, pattern);
    return 0;
}