#include <iostream>
#include "coordinate.hpp"
using std::cout;

int main(){
    Coordinate c1(10,10), c2(3,3), c3;
    c3 = c1 - c2;
    c1.view();
    c2.view();
    cout << "result: "; 
    c3.view();
    return 0;
}