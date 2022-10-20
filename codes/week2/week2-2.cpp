#include <iostream>
using namespace std;
/*
나이를 키보드로 입력 받아 모니터로 출력해보자
*/
int main(){
    int age = 0;
    cout << "나이를 입력해주세요: ";
    cin >> age;
    cout << "나이: (만)" << age << "세 입니다.\n";
    return 0;
}