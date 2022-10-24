#include <iostream>
using std::cout;
using std::string;

class Person{
    private:
        string name;
        int age;
    public:
        Person(string name, int age){
            this->name = name;
            this->age = age;
            cout << "Person constructor에서 호출되었습니다 (현재 객체의 메모리 주소) => " << this << '\n';
        }
};