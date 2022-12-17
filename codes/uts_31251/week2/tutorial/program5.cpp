// Program 5 - try vector another way
#include <iostream>
#include <vector>
using std::cout;
using std::vector;

int main(){
    vector<int> v;
    cout << v.size() << '\n'; // 0
    v.resize(30); // vector의 사이즈를 30으로 다시 정의한다.
    cout << v.size() << '\n'; // 30

    for(int i = 0; i < 30; i++){
        v[i] = i;
    }
    for(int i : v){
        cout << i << '\n';
    }
    return 0;
}