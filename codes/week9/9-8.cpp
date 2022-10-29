#include <iostream>
#include "calculator.hpp"
using std::cout;

int main(){
    Calculator c;
    cout << "result: " << c.add(0) << '\n';
    cout << "result: " << c.add(10) << '\n';
    cout << "result: " << c.add(10, 20) << '\n';
    return 0;
}