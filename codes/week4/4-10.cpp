#include <iostream>
#include "Person.h"
using namespace std;


int main(){
    Person person = Person("성재혁", "남자", "호주", 20);
    cout << person.info();
    return 0;
}