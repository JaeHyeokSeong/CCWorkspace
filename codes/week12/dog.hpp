#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>

class Dog{
    private:
        static int age;
    public:
        int getAge() const{
            return age;
        }
        void setAge(const int age){
            this->age = age;
        }
};
int Dog::age = 0;
#endif