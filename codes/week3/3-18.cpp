#include <iostream>
using namespace std;

void test();

int main(){
    test();
    test();
    test();
    test();
    return 0;
}
void test(){
    int a = 10;
    static int b = 10;
    cout << "a: " << a << ", b: " << b << '\n';
    a++;
    b++;
}