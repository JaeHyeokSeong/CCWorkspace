#include <iostream>
using namespace std;

void readNumber(){
    int number = 0;
    cout << "1부터 3사이의 숫자를 입력해 주세요\n";
    cin >> number;
    switch(number){
        case 1:
            cout << "1 입력됨";
            break;
        case 2:
            cout << "2 입력됨";
            break;
        case 3:
            cout << "3 입력됨";
            break;
        default:
            cout << "나머지 수 입력됨";
    }
    cout << '\n';
}
void calculator(){
    double n1, n2;
    char op;
    double result;
    cout << "계산할 식을 적어주세요 (각문자마다 공백을 추가해주세요)\n";
    cin >> n1 >> op >> n2;
    switch(op){
        case '+':
            result = n1 + n2;
            break;
        case '-':
            result = n1 - n2;
            break;
        case '*':
            result = n1 * n2;
            break;
        case '/':
            result = n1 / n2;
            break;
        default:
            result = 0;
            cout << "+ - * / 연산자만 가능 합니다.\n";
    }
    cout << "결과: " << result << '\n';
}
int main(){
    // readNumber();
    calculator();
    return 0;
}