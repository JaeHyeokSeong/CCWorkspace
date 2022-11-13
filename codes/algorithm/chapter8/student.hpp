#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>
using std::string;

class Student{
    private:
        string name;
        double score;
    public:
        Student(string name, double score){
            this->name = name;
            this->score = score;
        }
        string getName() const{
            return name;
        }
        double getScore() const{
            return score;
        }
        bool operator <(const Student& student) const{
            return this->score < student.getScore();
        }
};
#endif // STUDENT_HPP