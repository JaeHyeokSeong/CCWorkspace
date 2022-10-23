#include <iostream>
using std::cout;

class Person{
    private:
        int age;
    public:
        inline void setAge(int age){
            this->age = age;
        }
        inline int getAge(){
            return age;
        }
};

int main(){
    Person person;
    person.setAge(20);
    cout << "나이: " << person.getAge() << '\n';    
    return 0;
}