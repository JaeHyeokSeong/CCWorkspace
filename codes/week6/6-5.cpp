#include <iostream>
#include "Dog1.hpp"
using std::cout;
int main(){
    Dog dog;
    dog.setName("coco");
    dog.setAge(2);
    cout << dog.getName() << ' ' << dog.getAge() << '\n';
    return 0;
}