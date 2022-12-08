/*
8th Dec 2022
Rabin-Karp (라빈 카프)
*/
#include <iostream>
#include <cmath>
using std::string;
using std::pow;

void find_string(string parent, string pattern){
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int parent_hash = 0, pattern_hash = 0, power = 2; // 여기서 power 는 제곱수 의미
    for(int i = 0; i <= parent_size - pattern_size; i++){
        if(i == 0){
            for(int j = 0; j < pattern_size; j++){
                parent_hash += parent[pattern_size - 1 - j] * (int)pow(power, j);
                pattern_hash += pattern[pattern_size - 1 - j] * (int)pow(power, j);
            }
        } else{
            parent_hash = 2 * (parent_hash - parent[i - 1] * (int)pow(power, pattern_size - 1)) + 
            parent[pattern_size - 1 + i];
        }
        if(parent_hash == pattern_hash){
            bool found = true;
            for(int j = 0; j < pattern_size; j++){
                if(parent[i + j] != pattern[j]){
                    found = false;
                    break;
                }
            }
            if(found){
                printf("found at index %d\n", i);
            }
        }
    }
}
int main(){
    string parent = "ababacabacaabacaaba", pattern = "abacaaba";
    find_string(parent, pattern);
    return 0;
}