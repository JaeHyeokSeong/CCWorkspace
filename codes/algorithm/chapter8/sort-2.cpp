#include <iostream>
#include <algorithm>
#include "student.hpp"

using std::cout;
using std::sort;

void print(Student* students, int length){
    for(int i = 0; i < length; i++){
        cout << students[i].getName() << ' ' << students[i].getScore() << '\n';
    }
}
bool compare_descendingOrder(const Student& s1, const Student& s2){
    return s1.getScore() > s2.getScore();
}
int main(){
    Student students[5] = {
        Student("손흥민", 100), 
        Student("박지성", 90.3), 
        Student("김민재", 90), 
        Student("이강인", 83), 
        Student("황의찬", 82)
    };
    sort(students, students + 5, compare_descendingOrder);
    print(students, 5);
    return 0;
}