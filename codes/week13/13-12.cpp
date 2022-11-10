// STL vector 실습
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(10);
    vector<int>::iterator iter = v.begin();
    cout << *iter << '\n';


    int& a = v.front();
    cout << "front element: " << a << '\n';
    // for(int i = 0; i < v.size(); i++){
    //     cout << v[i] << " ";
    // }
    cout << '\n';
    return 0;   
}