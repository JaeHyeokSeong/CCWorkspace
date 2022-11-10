#include <iostream>
#include "cat.hpp"
#include "dog.hpp"

using std::cout;
    
const char* compare(Dog& dog, Cat& cat){
    return (dog.age == cat.age) ? "samge age" : "different age";
}
int main(){
    Cat cat(5);
    Dog dog(5);

    const char* result = compare(dog, cat);
    cout << result << '\n';

    return 0;
}