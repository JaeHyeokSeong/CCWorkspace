/*
8th Dec 2022 
Knuth-Morris-Pratt (문자열 매칭 알고리즘)
*/
#include <iostream>
using std::string;
using std::cout;

int find_string(const string parent, const string pattern){
    int parent_size = parent.size(), pattern_size = pattern.size();
    for(int i = 0; i <= parent_size - pattern_size; i++){
        bool finded = true;
        for(int j = 0; j < pattern_size; j++){
            if(parent[i+j] != pattern[j]){
                finded = false;
                break;
            }
        }
        if(finded){
            return i;
        }
    }
    return -1;
}
int main(){
    string parent = "hello world", pattern = "word";
    int finded_index = find_string(parent, pattern);
    if(finded_index == -1)
        cout << "찾을 수 없습니다.\n";
    else    
        cout << "index " << finded_index << " 에서 찾았습니다.\n";
    return 0;
}