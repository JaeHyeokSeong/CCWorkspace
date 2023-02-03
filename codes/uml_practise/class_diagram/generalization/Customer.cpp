#include "Customer.h"

Customer::Customer(std::string name, int age) : User(name, age){

}

Customer::~Customer(){

}

void Customer::login() {
    std::cout << "name: " << name << ", age: " << age << '\n';
}