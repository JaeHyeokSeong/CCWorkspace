#include <iostream>
#include "dog.hpp"
using std::cout;

int main(){
    int size = 0;
    cout << "How many dogs do you have? => ";
    cin >> size;

    Dog* dogs = new Dog[size];
    if(dogs == nullptr){
        cout << "Insufficient memory in the heap memory\n";
        return 1;
    }
    for(int i = 0; i < size; i++){
        cout << "Enter name: ";
        string name;
        cin >> name;
        dogs[i].setName(name);
        cout << "Enter age: ";
        int age;
        cin >> age;
        dogs[i].setAge(age);
    }

    cout << "\n[Result] You have entered following things\n";
    for(int i = 0; i < size; i++) {
        cout << "Name: " << dogs[i].getName() << ", Age: " << dogs[i].getAge() << '\n';
    }

    delete []dogs;
    return 0;
}