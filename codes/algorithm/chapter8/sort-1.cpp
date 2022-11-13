#include <iostream>
#include <algorithm>

using std::cout;
using std::sort;

void print(int* a, int length){
    for(int i = 0; i < length; i++){
        cout << a[i] << ' ';
    }
    cout << '\n';
}
/* 
어떻게 sort 함수 안에서 비교를
할 것인가를 정의 할 수 있다. 여기에서
알 수 있는점은 우리가 원하는 대로 sort 
함수의 정렬 기준을 설정 해줄수 있는 것이다
*/

bool compare(int a, int b){
    return a < b; // 오름 차순
}
bool compare_descendingOrder(int a, int b){
    return a > b;
}
int main(){
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a+10, compare_descendingOrder);
    print(a, 10);
    return 0;
}