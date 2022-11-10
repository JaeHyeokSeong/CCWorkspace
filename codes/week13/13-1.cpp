#include <iostream>
using std::cout;

template<typename T>
T max(T a, T b){
    return (a>b) ? a : b;
}
template<typename T1, typename T2>
void sayHello(T1 a, T2 b){
    cout << a << '\n';
    cout << b << '\n';
}
int main(){
    cout << max(2.0, 4.2) << '\n';
    sayHello(12345, "hello world");
    return 0;
}