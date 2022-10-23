#include "person.h"

Person::Person(string name, int age, int weight){
    this->name = name;
    this->age = age;
    this->weight = weight;
}
string Person::toString(){
    return "name: " + name + ", age: " + to_string(age) + ", weight: " + to_string(weight);
}