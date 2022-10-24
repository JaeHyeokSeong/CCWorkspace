#include <iostream>
#include "Dog.hpp"
using std::cout;
int main(){
    Dog dog("coco", 3);
    cout << dog.getName() << ", " << dog.getAge() << '\n';
    return 0;
}