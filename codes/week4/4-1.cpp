#include <iostream>
using namespace std;

struct Person{
    public:
        string name;
        int age;
        double weight;
    
    public:
        void view(){
            cout << "name: " << name << '\n';
            cout << "age: " << age << '\n';
            cout << "weight: " << weight << '\n';
        }
};
void accessByPointer(Person* person);
int main(){
    Person person1 = {"Jae", 20, 70};
    person1.view();

    Person person2 = {"성재혁", 20, 66};
    person2.view();

    accessByPointer(&person1);
}
void accessByPointer(Person* person){
    cout << "age: " << person->age << '\n';
}