#include <iostream>
#include <cmath>
using std::string;
using std::pow;

void find_string(string parent, string pattern){
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int parent_hash = 0, pattern_hash = 0;
    int const power = 2;
    for(int i = 0; i <= parent_size - pattern_size; i++){
        if(i == 0){
            for(int j = 0; j < pattern_size; j++){
                parent_hash += parent[pattern_size - 1 - j] * (int)pow(power, j);
                pattern_hash += pattern[pattern_size - 1 - j] * (int)pow(power, j);
            }
        }
        if(parent_hash != pattern_hash){
            // parent_hash 의 값의 바꿔줘야 한다
            // 공식 : parent_hash = 2 * (parent_hash - parent[가장 앞에있는 수]) + 새롭게 들어온 무자의 수치
            parent_hash = 2 * (parent_hash - parent[i] * (int)pow(power, pattern_size - 1)) + parent[i + pattern_size];
        } else{
            // hash 의 값이 일치하는 경우 하나씩 비교해보면서 한번더 확인 한다
            bool found = true;
            for(int j = 0; j < pattern_size; j++){
                if(parent[i+j] != pattern[j]){
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
    string parent = "ababacabacaabacaaba", pattern = "bac";
    find_string(parent, pattern);
    return 0;
}