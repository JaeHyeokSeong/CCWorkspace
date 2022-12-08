#include <iostream>
#include <vector>
using std::vector;
using std::string;

/*
찾고자 하는 문자열에서 접두사 그리고 접미사가 일치하는 최대길이를 찾는다
최대길이 만큼 jump 할 수 있다
*/
vector<int> make_table(const string pattern){
    int parrent_size = pattern.size();
    vector<int> table(parrent_size, 0);
    int j = 0;
    for(int i = 1; i < parrent_size; i++){
        while(j > 0 && pattern[j] != pattern[i]){
            j--;
        }
        if(pattern[j] == pattern[i]){
            table[i] = j + 1;
            j++;
        }
        else if(pattern[j] != pattern[i]){
            table[i] = 0;
        }
    }
    return table;
}
void kmp(const string parent, const string pattern){
    vector<int> table = make_table(pattern);
    int parent_size = parent.size();
    int pattern_size = pattern.size();
    int j = 0;
    for(int i = 0; i < parent_size; i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j-1];
        }
        if(parent[i] == pattern[j]){
            if(j == pattern_size - 1){
                printf("index %d 번째에서 찾았습니다.\n", i - pattern_size + 1);
                j = table[j];
            } else{
                j++;
            }
        }
    }
}
int main(){
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    kmp(parent, pattern);
    return 0;
}