#include <iostream>

// pre-condition
// a - nonnegative integer (나누어지는 대상)
// d - positive integer (divisor)
void division(int a, int d){
    // 나머지를 저장하는 변수
    int r = a;
    // 몫을 저장하는 변수
    int q = 0;

    // 나머지가 divisor 보다 크다는 의미이는
    // 더 나누어 질 수 있다는 의미이다.
    while(r >= d){
        r -= d;
        q++;
    }

    // 출력
    printf("몫 : %d, 나머지: %d\n", q, r);
}
int main(){
    division(7, 3);
    return 0;
}