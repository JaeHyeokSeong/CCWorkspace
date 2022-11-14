#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::vector;
using std::sort;
using std::pair;
using std::string;
using std::make_pair;

bool compare_descendingOrder(pair<pair<double, string>, string> p1, pair<pair<double, string>, string> p2){
    return p1 > p2;
}

int main(){
    // [1] initialise
    vector<pair<pair<double, string>, string> > v;

    // [2] input
    v.push_back(make_pair(make_pair(90, "1996-12-22"), "나동빈"));
    v.push_back(make_pair(make_pair(97, "1993-05-18"), "이태일"));
    v.push_back(make_pair(make_pair(95, "1993-02-03"), "박한울"));
    v.push_back(make_pair(make_pair(90, "1992-12-07"), "이상욱"));
    v.push_back(make_pair(make_pair(88, "1990-03-02"), "강종구"));

    // [3] process
    sort(v.begin(), v.end(), compare_descendingOrder);

    // [4] output
    for(int i = 0; i < v.size(); i++){
        cout << v[i].second << ' ' << v[i].first.first << ' ' << v[i].first.second << '\n';
    }
    return 0;
}