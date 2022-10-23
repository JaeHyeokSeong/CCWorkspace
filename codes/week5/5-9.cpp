#include <iostream>
#include "dog.h"
using std::cout;
int main(){
    Dog dog;
    dog.setAge(3);
    cout << "coco " << dog.getAge() << '\n';
    return 0;
}