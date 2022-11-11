#include <iostream>
#include "a.hpp"
#include "b.hpp"
using std::cout;
int main(){
    A a(10);
    B b(2);
    int sum = b.add(a);
    cout << sum << '\n';
    return 0;
}