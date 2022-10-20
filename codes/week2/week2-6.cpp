#include <iostream>
using namespace std;

int main(){
    bool isMan = true;
    if(isMan){
        cout << "남자입니다.\n";
    } else{
        cout << "여자입니다.\n";
    }
    cout << sizeof(int) << '\n';
    cout << 1 + 'A'; // 66 왜냐하면 A의 ASCII code의 값이 65이기 때문이다.
    return 0;
}