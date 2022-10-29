#include <iostream>
#include "student.hpp"

int main(){
    Student student1, student2(2);
    student1.view();
    student2.view();
    return 0;
}