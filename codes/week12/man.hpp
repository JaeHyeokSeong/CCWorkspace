#ifndef MAN_HPP
#define MAN_HPP
#include <iostream>
using std::string;

class Man{
    private:
        string name;
        int age;
    public: 
        Man(string name, int age){
            this->name = name;
            this->age = age;
        }
        string getName() const{
            return name;
        }
        int getAge() const{
            return age;
        }
};
#endif