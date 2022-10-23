// 범위 지정 연산자 (scope resolution operation :: )
#include <iostream>
using namespace std;

namespace A {
    class Dog {
        public:
            void sound(){
            cout << "bark bark" << '\n';
        }
    };
    int a = 3;
}

int a = 100;
int main(){
    int a = 10;
    cout << ::a << '\n';
    cout << A::a << '\n';
    A::Dog dog;
    dog.sound();
    return 0;
}