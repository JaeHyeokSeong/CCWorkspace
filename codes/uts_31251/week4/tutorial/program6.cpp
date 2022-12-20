#include <iostream>
#include <vector>
#include "student.hpp"

int main(){
    std::vector<Student> students;
    students.push_back(Student(1,"name1", 20, 'F'));
    students.push_back(Student(2,"name2", 21, 'F'));

    for(int i = 0; i < students.size(); i++){
        if(students[i].gender == 'F' && students[i].age == 20){
            std::cout << students[i].id << ' ' << students[i].name << ' ' <<  students[i].gender << ' ' << students[i].age << '\n';
        }
    }
    return 0;
}