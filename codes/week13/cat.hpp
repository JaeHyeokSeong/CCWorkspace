#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "dog.hpp"

class Dog; // 전방선언 (forward declaration)
class Cat{
    private:
        int age;
    public: 
        Cat(int age){
            this->age = age;
        }
        int getAge() const{
            return age;
        }
        friend const char* compare(Dog& dog, Cat& cat);
};
#endif // CAT_HPP