#include <iostream>
using std::cout;
class Cat{
    private:    
        int age;
    public:
        Cat(){
            cout << "object is created\n";
            age=1;
        }
        Cat(int age){
            this->age = age;
        }
        ~Cat(){
            cout << this << " 주소의 객체가 소멸되었습니다\n";
        }
        int getAge() const{
            return age;
        }
        void setAge(int age){
            this->age = age;
        }
        void meow() const{
            cout << "아용~\n";
        }
};