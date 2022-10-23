#include <iostream>
#include "aa.h"
#include "bb.h"
using std::cout;

int main(){
    int a = AA::add(2,8);
    cout << a << '\n';
    int b = BB::add(10,10);
    cout << b << '\n';
    return 0;
}