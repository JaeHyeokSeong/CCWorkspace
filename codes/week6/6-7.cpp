#include <iostream>
#include "Dog1.hpp"
using std::cout;

int main(){
    Dog dog(3);
    cout << "name: " << dog.getName() << ", age: " << dog.getAge() << '\n';
    return 0;
}