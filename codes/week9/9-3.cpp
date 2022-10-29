#include <iostream>
#include "person.hpp"
using std::cout;
using std::string;

template <typename T>
T max(T a, T b){
    return a+b;
}
template<>
const char* max<const char*>(const char* a, const char* b){
    const char* str = "[const char*] 더할 수 없습니다.";
    return str;
}
template<>
char max<char>(char a, char b){
    cout << "[char] 더할 수 없습니다.";
    return '\0';
}

template <typename T>
T abs(T a){
    if(a<0){
        a = -a;
    }
    return a;
}

int main(){
    // cout << max(1,3) << '\n';
    // cout << max(10.2, 10.0) << '\n';
    // cout << max('a', 'b') << '\n';
    // cout << max("hello", "ao") << '\n';
    cout << abs(-10) << '\n';
    Person<double> person1;
    person1.setHeight(172.1);
    cout << person1.getHeight() << '\n';
    return 0;
}