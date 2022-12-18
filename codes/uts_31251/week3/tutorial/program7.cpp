#include <iostream>
#include "Animal.hpp"

int main(){
    Animal a1("Lion", 10);
    std::cout << a1.get_name() << ' ' << a1.get_age() << '\n';
    return 0;
}