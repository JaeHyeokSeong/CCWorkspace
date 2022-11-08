#include <iostream>
using std::cout;

class A{
    public: 
        virtual int ss(int i){
            return i*2;
        }
        int dd(int i ){
            return ss(i) * 2;
        }
};
class B: public A{
    public: 
        int ss(int i) {
            return i*3;
        } 
        void test(){

        }
};
int main(){
    B b;
    cout << b.dd(2) << '\n';
    cout << b.ss(2) << '\n';
    A* pA = new A;
    cout << pA->dd(2) << '\n';
    A* pB = new B;
    cout << pB->dd(2) << '\n'; // 12
    A* test = new B;
    cout << test->ss(2) << '\n';
    delete pA;
    delete pB;
    delete test;
    return 0;
}