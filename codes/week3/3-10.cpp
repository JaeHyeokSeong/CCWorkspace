#include <iostream>
using namespace std;

string vending(int item); // vending 이라는 함수가 메인 함수 뒤에 선언되어 있으니까 이를 알려줘야한다.

int main() {
    string item = vending(2);
    // compare() 함수는 값이 같으면 0을 리턴, 값이 서로 다르면 1을 리턴합니다.
    if(item.compare("")){
        cout << item << "가 선택되었습니다.\n";
    } else {
        cout << "목록에 없는것이 선택되었습니다.\n";
    }
}
string vending(int item){
    switch(item){
        case 1:
            return "커피";
        case 2:
            return "유자차";
        default:
            return "";
    }
}