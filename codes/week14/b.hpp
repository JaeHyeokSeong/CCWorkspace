#ifndef B_HPP
#define B_HPP
#include <iostream>
class B{
    private:
        int b, sum;
    public:
        B(int b){
            this->b = b;
        }
        int getB() const{
            return b;
        }
        int add(A a){
            return a.getA() + b;
        }
};
#endif // B_HPP