#include <iostream>
class Dog{
    private:
        int age;
    public:
        Dog(){
            age = 1;
        }
        Dog(int age) {
            this->age = age;
        }
        ~Dog(){
            std::cout << "소멸됨\n";
        }
        void setAge(int age){
            this->age = age;
        }
        int getAge() const{
            return age;
        }
};