#include <iostream>
class Dog{
    private:
        char name[100];
        int age;

    public:
        Dog(){
            strcpy(name, "");
            age = 0;
        }
        Dog(int age): age(age){
            strcpy(name, "");
        }
        ~Dog(){
            std::cout << "destructor is called in the Dog1.hpp file\n";
        }
        void setName(const char* name){
            strcpy(this->name, name);
        }
        const char* getName(){
            return name;
        }
        void setAge(int age){
            this->age = age;
        }
        int getAge(){
            return age;
        }
};