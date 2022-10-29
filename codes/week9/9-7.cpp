#include <iostream>
using std::cout;

int add(int a = 0,int b = 0); // 선언하는 곳에서만 defualt argument 값을 줘야한다, 그리고 값을 주는 시작부분 오른쪽도 다 줘야한다
int main(){
    cout << add() << '\n';
    cout << add(1) << '\n';
    cout << add(1,2) << '\n';
    return 0;
}
int add(int a, int b){ // 정의 하는 부분에서는 defualt parameter 값을 다시 설정해서는 안된다
    return a + b;
}