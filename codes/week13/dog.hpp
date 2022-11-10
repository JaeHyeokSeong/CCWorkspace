#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "cat.hpp"

class Cat; // 전방 선언 (forward declaration)
class Dog{
    private:
        int age;
    public: 
        Dog(int age){
            this->age = age;
        }
        int getAge() const{
            return age;
        }
        friend const char* compare(Dog& dog, Cat& cat);
};
#endif //DOG_HPP