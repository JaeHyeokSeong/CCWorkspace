#include <iostream>
using std::cout;

class A{
    private:
        void a1() {cout << "a1\n";}
        void a2() {cout << "a2\n";}
    public:
        void b1() {cout << "b1\n";}
        void b2() {cout << "b2\n";}
};

class B : public A{

};
int main(){
    B bb;
    bb.b1();
    bb.b2();
    return 0;
}