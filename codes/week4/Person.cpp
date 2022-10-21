#include "Person.h"

Person::Person(string p_name, string p_gender, string p_address, int p_age){
    this->name = p_name;
    this->gender = p_gender;
    this->address = p_address;
    this->age = p_age;
}
string Person::info(){
    return "name " + name + ", gender: " + gender + ", age: " + to_string(age) + ", address: " + address + '\n';
}