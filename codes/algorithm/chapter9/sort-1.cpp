#include <iostream>
#include <algorithm>
#include <vector>

using std::pair;
using std::vector;
using std::cout;
using std::string;
using std::make_pair;

bool compare(pair<int, string> p1, pair<int, string> p2){
    return p1 > p2;
}
int main(){
    vector<pair<int, string> > v;
    v.push_back(make_pair<int, string>(100, "손흥민"));
    v.push_back(make_pair<int, string>(86, "김민재"));
    v.push_back(make_pair<int, string>(81, "이강인"));
    v.push_back(make_pair<int, string>(84, "황의찬"));
    v.push_back(make_pair<int, string>(78, "정우영"));
    
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++){
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}