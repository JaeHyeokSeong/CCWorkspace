#include <iostream>
#include "point.hpp"
using std::cout;

int main(){
    Point point1(1,1), point2(2,5);
    // point1++;
    point1.view();
    point2.view();
    Point point3 = point1 + point2;
    point3.view();
    return 0;
}
