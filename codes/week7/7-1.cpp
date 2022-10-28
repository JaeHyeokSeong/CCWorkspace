#include <iostream>
using std::cout;

class Dog{
    private:
        int age;
    public:
        Dog(int age);
        int getAge() const;  
        void setAge(int age);
};
Dog::Dog(int age){
    this->age = age;
}
int Dog::getAge() const {
    return age;
}
void Dog::setAge(int age){
    this->age = age;
}
int main(){
    // const int x = 2;
    // cout << x << '\n';
    Dog dog(3);
    cout << dog.getAge() << '\n';

    const Dog dog1(10);
    // dog1.setAge(0);
    cout << dog1.getAge() << '\n';
    return 0;
}