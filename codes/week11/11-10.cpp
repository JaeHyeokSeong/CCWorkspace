#include <iostream>
using std::cout;

class Person{
    private:
        int age;
    public:
        Person(int age = 0){
            this->age = age;
        }
        int getAge() const{
            return age;
        }
};
int main(){
    Person p1;
    cout << p1.getAge() << '\n';
    return 0;
}