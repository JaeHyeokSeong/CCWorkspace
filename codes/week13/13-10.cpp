/*
swap함수를 template(generic)을 사용하여서 구현하기
*/

#include <iostream>
using std::cout;
using std::string;

template<typename T>
void swapWithReference(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}
template<typename T>
void swapWithPointer(T* a, T* b){
    T temp = *a;
    *a = *b;
    *b = temp;
}
int main(){
    int a = 10, b = 5;
    cout << "참조자 사용\n";
    cout << "[before] a: " << a << ", b: " << b << '\n';
    swapWithReference(a,b);
    cout << "[after] a: " << a << ", b: " << b << '\n';

    string x = "hello";
    string y = "world";
    cout << "\n포인터 사용\n";
    cout << "[before] a: " << x << ", b: " << y << '\n';
    swapWithPointer(&x,&y);
    cout << "[after] a: " << x << ", b: " << y << '\n';

    return 0;
}