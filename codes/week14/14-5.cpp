#include <iostream>
#include <iomanip>
using std::cout;

int main(){
    // cout << std::hex << std::showbase << std::uppercase << std::setw(10) << 50 << std::endl;
    // cout << 10 << std::endl;
    // cout << std::dec << 10 << '\n'; // 다시 기본 출력형태로 돌림
    // cout << std::hex << std::nouppercase << 50 << '\n';

    int num = 100;
    cout << std::setw(10) << num << std::endl;
    cout << std::hex << std::showbase << num << std::endl;
    cout << std::oct << std::showbase << num << std::endl;
    return 0;
}