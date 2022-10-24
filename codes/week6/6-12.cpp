#include <iostream>
#include "person.hpp"
using std::cout;

int main(){
    Person person1("JaeHyeok", 20);
    cout << "Test => " << &person1 << "\n\n";
    Person person2("JaeWon", 25);
    cout << "Test => " << &person2 << "\n\n";
    return 0;
}