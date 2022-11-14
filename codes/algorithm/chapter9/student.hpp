#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iostream>

using std::string;

class Student{
    private:
        string name;
        string dob;
        double score;
    public:
        Student(const string name, const double score, const string dob){
            this->name = name;
            this->score = score;
            this->dob = dob;
        }
        string getName() const{
            return name;
        }
        string getDob() const {
            return dob;
        }
        double getScore() const{
            return score;
        }
        bool operator <(const Student& student) const{
            return score < student.getScore();
        }
};
#endif // STUDENT_HPP