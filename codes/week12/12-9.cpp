#include <iostream>
using std::cout;

class A{
    public:
        A(){
            cout << "A object is created\n";
        }
        ~A(){
            cout << "A object is removed\n";
        }
        virtual void show(){
            cout << "This is A class\n";
        }
};
class B : public A{
    public:
        B(){
            cout << "B object is created\n";
        }
        ~B(){
            cout << "B object is removed\n";
        }
        void show(){
            cout << "This is B class\n";
        }
};
int main(){
    // double pi = 3.14;
    // cout << pi << '\n';    
    // cout << (int)pi << '\n';    
    // cout << static_cast<int>(pi) << '\n';    
    // return 0;

    // A* pA = new A;
    // pA->show();
    // B* pB = dynamic_cast<B*>(pA);
    // if(pB == nullptr){
    //     cout << "runtime error\n";
    //     delete pA;
    //     return 1;
    // }
    // pB->show();
    // delete pA;
    // delete pB; 
    // return 0;


    // A* pA = new B;
    // pA->show(); // This is B class
    // B* pB = dynamic_cast<B*>(pA);
    // if(pB == nullptr){
    //     cout << "runtime error\n";
    //     delete pA;
    //     return 1;
    // }
    // pB->show(); // This is B class
    // delete pB;

    B* pB = new B;
    pB->show(); // This is B class
    A* pA = static_cast<A*>(pB);
    pA->show(); // This is B class
    delete pB;
    return 0;
}