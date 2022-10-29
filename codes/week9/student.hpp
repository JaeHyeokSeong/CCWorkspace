#include <iostream>
using std::cout;

class Student{
    private:
        int age;
    public:
        Student(int age = 1){
            this->age = age;
        }
        void view() const{
            cout << "age: " << age << '\n';            
        }
};