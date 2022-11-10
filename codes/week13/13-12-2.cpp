#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using std::cout;
using std::vector;
using std::sort;
using std::greater;

int main(){
    vector<int> v(5); // 5개의 element들이 있고 모두다 0으로 초기화 되어진다
    cout << "size: " << v.size() << ", capacity: " << v.capacity() << '\n';

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " "; // 0 0 0 0 0
    }
    cout << '\n';

    // 1에서 5까지의 수로 vector 초기화 해주기
    for(int i = 0; i < v.size(); i++){
        v[i] = (i+1);
    }

    // 다시 모든 벡터안에있는 요소들 출력하기
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';

    // vector 맨 뒤부터 10 9 8 7 6 으로 요소들을 추가해주기
    for(int i = 0; i < 5; i++){
        v.push_back((10-i));
    }

    // 다시 모든 벡터안에있는 요소들 출력하기
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << '\n';

    // cout << *v.end() << '\n';
    // iterator 는 컨테이너 요소들의 메모리 주소를 가지고 노는 포인터 같은 것이다
    vector<int>::iterator i;

    for(i = v.begin(); i < v.end(); i++){
        cout << *i << ' ';
    }
    cout << '\n';

    sort(v.begin(), v.end());
    for(i = v.begin(); i < v.end(); i++){
        cout << *i << ' ';
    }
    cout << '\n';

    sort(v.begin(), v.end(), greater<int>()); // 냄림차순 (큰거에서 작은걸로)

    for(i = v.begin(); i < v.end(); i++){
        cout << *i << ' ';
    } 
    cout << '\n';

    return 0;
}