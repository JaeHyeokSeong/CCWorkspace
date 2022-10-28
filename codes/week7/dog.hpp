#include <iostream>
using std::cout;
using std::cin;
using std::string;

class Dog{
    private:
        string name;
        int age;
    public:
        Dog(){}
        Dog(string name, int age){
            this->name = name;
            this->age = age;
        }
        void setName(string name){
            this->name = name;
        }
        void setAge(int age){
            this->age = age;
        }
        string getName() const{
            return name;
        }
        int getAge() const{
            return age;
        }
};