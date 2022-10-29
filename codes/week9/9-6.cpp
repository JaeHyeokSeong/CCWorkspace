#include <iostream>
#include "dog.hpp"
using std::cout;

void changeAge(Dog* dog);
int main(){
    // Dog dog1, dog2(3);
    // cout << dog1.getAge() << '\n';
    // cout << dog2.getAge() << '\n';

    // Dog dogs[3] = {1,2,3};
    // for(int i = 0; i < 3; i++) {
    //     cout << dogs[i].getAge() << '\n';
    // }

    Dog dog(2);
    changeAge(&dog);
    cout << dog.getAge() << '\n';
    return 0;
}
void changeAge(Dog* dog){
    dog->setAge(100);
}