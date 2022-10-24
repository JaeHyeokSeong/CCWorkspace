#include <iostream>
using std::cout;
using std::string;

class Cat{
    private:
        int age;
        double weight;
        string name;
    public:
        Cat(int age, double weight, string name){
            this->age = age;
            this->weight = weight;
            this->name = name;
            cout << "객체가 생성되었습니다. memory address -> " << this << '\n'; 
        }
        ~Cat(){
            cout << "memory address -> " << this << " 을 가진 객체가 삭제 되어졌습니다.\n"; 
        }
        void meow(){
            cout << "memory address -> " << this << " 을 가진 객체 고양이가 소리를 냅니다: 야용~~\n";
        }
};