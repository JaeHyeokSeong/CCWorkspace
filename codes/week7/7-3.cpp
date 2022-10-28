#include <iostream>
using std::cout;

int a;
void show1();
int main(){
    int a = 10;
    cout << ::a << '\n';
    show1();
    return 0;
}
void show1(){
    cout << ++a << '\n';
}