#include <iostream>
#include "a1.hpp"
#include "a2.hpp"
using std::cout;

class B : public A1, public A2{
    private:
        int b;
    public:
        B(const int a1, const int a2, const int b) : A1(a1), A2(a2){
            this->b = b;
        }
        ~B(){
            cout << "B 클래스의 객체가 소멸 되었습니다.\n";
        }
        int getB() const{
            return b;
        }
        void show() const{
            cout << "a1: " << getA1() << ", a2: " << getA2() << ", b: " << b << '\n';
        }
};
int main(){
    B b(1,2,3);
    b.show();
}
