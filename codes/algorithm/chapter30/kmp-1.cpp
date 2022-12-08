#include <iostream>
using std::string;
using std::cout;

int find_string(const string parent, const string pattern){
    int parent_size = parent.size(), pattern_size = pattern.size();
    bool found;
    for(int i = 0; i <= parent_size - pattern_size; i++){
        found = true;
        for(int j = 0; j < pattern_size; j++){
            if(parent[i+j] != pattern[j]){
                found = false;
                break;
            }
        }
        if(found)
            return i;
    }
    return -1;
}
int main(){
    string parent = "Hello World!", pattern = "llo";
    int found_index = find_string(parent, pattern);
    if(found_index == -1)
        cout << "not found\n";
    else    
        cout << "found at index " << found_index << '\n';
    return 0;
}