#include <iostream>
#include "rectangle.hpp"
#include "triangle.hpp"
int main(){
    Rectangle r1(10,10);
    Triangle t1(10,5);
    Shape* shapes[2] = {&r1, &t1};
    for(int i = 0; i < 2; i++) {
        std::cout << shapes[i]->area() << '\n';
    }
    return 0;
}