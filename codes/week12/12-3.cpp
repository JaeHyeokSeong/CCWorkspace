#include <iostream>
#include "student.hpp"
#include "teacher.hpp"
using std::cout;

int main(){
    Student jae("Jae Hyeok Seong", 21, 31927, 14081095);
    Teacher tracy("Tracy" , 40, "computer science", "application programming");
    jae.show();
    tracy.show();
    return 0;
}