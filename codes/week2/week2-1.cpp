#include <iostream>
using namespace std;
int main(){
    int a = 0, b = 0;
    string str = "";
    cout << "숫자 두개를 입력해주세요 (공백으로 구별): ";
    cin >> a >> b >> str;
    cout << a << " + " << b << " = " << a+b << "\n";
    cout << "오늘 날짜: " << str << "\n";
    return 0;
}