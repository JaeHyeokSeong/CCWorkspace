#ifndef TEACHER_HPP
#define TEACHER_HPP 
#include "man.hpp"
using std::cout;

class Teacher: public Man{
    private:
        string major, subject;
    public:
        Teacher(string name, int age, string major, string subject) : Man(name, age){
            this->major = major;
            this->subject = subject;
        }
        string getMajor() const{
            return major;
        }
        string getSubject() const{
            return subject;
        }
        void show(){
            cout << "name: " << getName() << ", age: " << getAge() << ", major: " << major << ", subject: " << subject << '\n';
        }
};
#endif 