#include <iostream>
#include <vector>
#include <list>
using std::vector;
using std::list;
using std::cout;

int main(){
    vector<int> v;
    list<int> l;

    for(int i = 0; i < 5; i++){
        v.push_back(i);
        l.push_back(i);
    }
    cout << "vector memory location\n";
    for(int i = 0; i < v.size(); i++){
        cout << &v[i] << '\n';
    }
    cout << "list memory location\n";
    for(int& i : l){
        cout << &i << '\n';
    }
    return 0;
}