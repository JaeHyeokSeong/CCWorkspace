#include <iostream>
#include "person.h"
using std::cout;

int main(){
    Person Jae = Person("Jae", 20, 70);
    cout << Jae.toString() << '\n';    
    return 0;
}