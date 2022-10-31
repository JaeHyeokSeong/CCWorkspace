#include <iostream>
using std::cout;
class Parent{
    private:
        int a;
    public:
        Parent(int a){
            this->a =a;
            cout << "Parent object is created\n";
        }
        ~Parent(){
            cout << "Parent object is removed\n";
        }
        void showA() const{
            cout << a << '\n';
        }
};
class Child : public Parent{
    private:
        int b;
    public:
        Child(int a, int b) : Parent(a){
            this->b = b;
            cout << "Child object is created\n";
        }
        ~Child(){
            cout << "Child object is removed\n";
        }
        void showB(){
            cout << b << '\n';
        }
};  
int main(){ 
    Child c(10,20);
    c.showA();
    c.showB();
    return 0;
}