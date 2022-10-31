#include <iostream>
using std::string;
using std::cout;

class Person{
    protected:
        string name;
        int age;
    public:
        Person(const string& name = "unkown", const int age = 0){
            this->name = name;
            this->age = age;
        }
        string getName() const{
            return name;
        }
        int getAge() const{
            return age;
        }
        void setName(const string& name){
            this->name = name;
        }
        void setAge(const int age){
            this->age = age;
        }
};

class Student : public Person{
    private:
        int sId;
    public:
        Student(const string& name, const int age, int sId) : Person(name, age){
            this->sId = sId;
        }
        void view(){
            cout << "name: " << name << ", age: " << age << ", sId: " << sId << '\n';
        } 
};
int main(){
    Student student("Jae Hyeok Seong", 21, 1111111);
    student.view();
    return 0;
}