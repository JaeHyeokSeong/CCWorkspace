#include <iostream>
#include "Cat.hpp"
using std::cout;

int main(){
    Cat cats[3] = {Cat(2, 3.2, "cat1"), Cat(3, 4.2, "cat2"), Cat(2, 3.5, "cat2")};
    for(int i = 0; i < 3; i++) {
        cats[i].meow();
    }
    return 0;
}