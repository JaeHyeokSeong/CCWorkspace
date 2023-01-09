#include <iostream>

class Person{
    private:
        int age;
        const char* name;
    public:
        Person(){
            name = "unkown";
            age = 0;
        }
        Person(const char* name, const int age){
            this->name = name;
            this->age = age;
        }
        void get_info() const{
            printf("name: %s, age: %d\n", name, age);
        }
};
int main(){
    Person person1;
    person1 = Person("Jae", 23);
    person1.get_info();

    Person person2("JaeHyeok", 23);
    person2.get_info();

    Person* person3 = new Person("Seong Jae Hyeok", 23);
    person3->get_info();
    delete person3;
    return 0;    
}