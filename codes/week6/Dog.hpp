#include <iostream>
using std::string;

class Dog{
    private:
        string name;
        int age;

    public:
        Dog(){
            name = "";
            age = 0;
        }
        Dog(string name, int age){
            this->name = name;
            this->age = age;
        }    
        string getName(){
            return name;
        }
        int getAge(){
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
};