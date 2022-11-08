#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "man.hpp"
using std::cout;

class Student: public Man{
    private:
        int courseNumber, stdNumber;
    public:
        Student(string name, int age, int courseNumber, int stdNumber): Man(name, age){
            this->courseNumber = courseNumber;
            this->stdNumber = stdNumber;
        }
        int getCourseNumber() const{
            return courseNumber;
        }
        int getStdNumber() const{
            return stdNumber;
        }
        void show(){
            cout << "name: " << getName() << ", age: " << getAge() << ", course number: " << courseNumber
            << ", student number: " << stdNumber << '\n';
        }
};
#endif