#include <iostream>
using namespace std;
#define sum3(i,j,k) (i+j+k) // 함수같은 매크로 즉 코드상에서 sum3이라는 이름과 parameter를 3개 가진것이 나오면 이 arguments의 값들을 다 더해주는 것이다.


int main(){
    cout << sum3(1,1,2) << '\n'; // 4
    int x = 10, y = 3;
    cout << x/(double)y << '\n';
    int numbers[] = {1,2,3,4,5};
    cout << sizeof(numbers)/sizeof(int) << '\n';
    return 0;
}