#include <iostream>
#include <vector>
using std::vector;
using std::string;

vector<int> make_table(const string pattern){
    int pattern_size = pattern.size();
    vector<int> table(pattern_size, 0);
    int j = 0;
    for(int i = 1; i < pattern_size; i++){
        while(j > 0 && pattern[j] != pattern[i]){
            j--;
        }
        if(pattern[j] == pattern[i]){
            table[i] = j + 1;
            j++;
        } else if(pattern[j] != pattern[i]){
            table[i] = 0;
        }
    }
    return table;
}
void kmp(const string parent, const string pattern){
    vector<int> table = make_table(pattern);
    int parent_size = parent.size(), pattern_size = pattern.size();
    int j = 0;
    for(int i = 0; i < parent_size; i++){
        while(j > 0 && parent[i] != pattern[j]){
            j = table[j - 1];
        }
        if(parent[i] == pattern[j]){
            if(j == pattern_size - 1){
                printf("found at index %d\n", i - pattern_size + 1);
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