#include <iostream>
using std::cout;
class A{
    public:
        virtual void test(){
            cout << "A\n";
        }
};
class B: public A{
    public:
        void test() {
            cout << "B\n";
        }
};
int main(){
    A* a = new A;
    a->test();
    delete a;
    a = new B;
    a->test();
    delete a; 
}