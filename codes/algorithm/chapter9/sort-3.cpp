#include <iostream>
#include <vector>
#include <algorithm>
#include "student.hpp"
using std::cout;
using std::sort;
using std::vector;

bool compare(const Student& s1, const Student& s2){
    if(s1.getScore() == s2.getScore()){
        return s1.getDob() > s1.getDob();
    } else {
        return s1.getScore() > s2.getScore();
    }
}

int main(){
    // [1] initialise
    vector<Student> students;
    // [2] input
    students.push_back(Student("나동빈", 90, "1996-12-22"));
    students.push_back(Student("이태일", 97, "1993-05-18"));
    students.push_back(Student("박한울", 95, "1993-02-03"));
    students.push_back(Student("이상욱", 90, "1992-12-07"));
    students.push_back(Student("강종구", 88, "1990-03-02"));
    // [3] process
    sort(students.begin(), students.end(), compare);
    // [4] output
    for(int i = 0; i < students.size(); i++) {
        cout << students[i].getName() << ' ' << students[i].getScore() << ' ' << students[i].getDob() << '\n';
    }
    return 0;
}