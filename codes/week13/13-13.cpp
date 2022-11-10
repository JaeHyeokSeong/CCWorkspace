#include <iostream>
#include "a.hpp"

int test(A& a){
    return a.x;
}
int main(){
    A a;
    a.setX(10);
    int result = test(a);
    std::cout << result << '\n';
    return 0;
}