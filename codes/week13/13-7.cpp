#include <iostream>
using std::cout;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){
    int a = 10, b = 5;
    cout << "[before] a: " << a << ", b: " << b << '\n';
    swap(a,b);
    cout << "[after] a: " << a << ", b: " << b << '\n';
    return 0;
}