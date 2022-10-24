#include <iostream>
#include "Dog.hpp"
using std::cout;

int main(){
    Dog dogs[5];
    Dog* dog = dogs;
    for(int i = 0; i < 5; i++) {
        dog->setAge(i);
        cout << "dogs: " << dogs[i].getAge() << ", dog: " << dog->getAge() << '\n';
        dog++;
    }
    return 0;
}