/*
pointer 실습
*/
#include <iostream>
using std::cout;

int main(){
    int x = 10, y;
    int* px = &x;
    y = *px;
    
    cout << "x value: " << x << " x 변수의 주소 값: " << &x << '\n';
    cout << "px 포인터 변수가 가지고 있는 값: " << px << '\n'; 
    cout << "y 변수의 주소: " << &y << '\n';
    cout << sizeof(&x) << '\n';

    double* pd;
    char a = 'J';
    char* pc = &a;
    cout << "double 형의 포인텨 변수의 사이즈: " << sizeof(pd) << '\n';
    cout << "char 형의 포인텨 변수의 사이즈: " << sizeof(pc) << '\n';
    return 0;
}