#include <iostream>
#include "Dog.hpp"
using std::cout;

int main(){
    Dog dogs[2] = {Dog("가을", 3), Dog("겨울", 5)};
    for(int i = 0; i < 2; i++) {
        cout << dogs[i].getName() << ", " << dogs[i].getAge() << '\n';
    }

    cout << "\n포인터 객체\n";
    Dog* dog = new Dog("강아지1", 5);
    cout << dog->getName() << ", " << dog->getAge() << '\n';
    return 0;
}