#include <iostream>

class A{
    private:
        int a;
    public:
        void setA(const int a){
            this->a = a;
        }
        int getA() const{
            return a;
        }
};
class B : public A{
    private:
        int b;
    public:
        void setB(const int b){
            this->b = b;
        }
        int getB() const{
            return b;
        }
};
int main(){
    B b;
    b.setA(1);
    std::cout << b.getA() << '\n';
    return 0;
}