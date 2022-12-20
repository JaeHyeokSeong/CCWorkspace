#ifndef STUDENT_HPP
#define STUDENT_HPP
class Student{
    public:
        int id, age;
        const char* name;
        char gender;
        Student(int id, const char* name, int age , char gender){
            this->id = id;
            this->name = name;
            this->age = age;
            this->gender = gender;
        }
};
#endif // STUDENT_HPP